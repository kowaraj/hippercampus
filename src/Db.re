// ReasonML wrapper for the Firestore database interface in Firestore.js

[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: ( (string, TT.fs_meme_t) => unit) => unit = "memes_onSnapshot";

//[@bs.val] external document: 'a = "document";
//[@bs.set] external setName: (textarea, string) => unit = "name";
// call a method
//document##addEventListener("mouseup", _event => {
//  let loc = document##location;
  ////    document##location##href = "rescript-lang.org";
//  Js.log("clicked!");
//});


[@bs.get] external getName: TT.fs_meme_t => string = "name";
[@bs.get] external getText: TT.fs_meme_t => string = "text";
[@bs.get] [@bs.return nullable] external getFn: TT.fs_meme_t => option(string) = "fn";
[@bs.get] [@bs.return nullable] external getTags: TT.fs_meme_t => option(string) = "tags";


[@react.component]
let make = (~cb_fetch_selected) => {

    let (memes, setMemes) = React.useState( () => [] );

    // Callback for realtime db update
    let add_meme = (m_id, m:TT.fs_meme_t) => {
        //Js.log("Db.re: add_meme:")
        //Js.log(m)
        let tags = getTags(m) // option(string), bs.nullable => might be undefined!
        let tags_array = {
                switch tags {
                | Some(s) => Array.to_list(Js.String2.split(s, " "));
                | None => ["no tags found"]
                }
        };
        let m_fn = getFn(m);
        let fn_string = {
            switch m_fn {
                | Some(fn) => fn;
                | None => "no files attached"
            }
        }
        let mm : TT.fs_meme_t = {id: m_id, name: getName(m), text: getText(m), fn: fn_string, tags: tags_array}
        setMemes( ms => List.append(ms, [ mm ] ) )
    };

    // Register a callback
    React.useEffect0( () => { 
        fs_memes_onSnapshot(add_meme)
        None;
    });

    // Get the meme from a selected name
    let selected_meme : string => unit = _item_name => { 
        let m = List.find( (mi : TT.fs_meme_t) => mi.name == _item_name, memes )
        cb_fetch_selected(m) 
    };

    // Render the list of memes
    <div> 
        <RenderItemList4 items=memes cb_selection=selected_meme/>
    </div>
 
};