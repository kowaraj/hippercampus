// ReasonML wrapper for the Firestore database interface in Firestore.js

[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: ( (string, TT.fs_meme_t) => unit) => unit = "memes_onSnapshot";

// [@bs.module "./Firestore.js"]
// external fs_add_meme: ( unit => unit ) =  "add_meme";

// [@bs.val] external document: 'a = "document";
// document##addEventListener("mouseup", _event => {
//     let loc = document##location;
//     //Js.log(loc)
//     //let ret = set_location_href(loc, "rescript-lang.org")
//     let href = document##location##href;
//     let ret = "rescript-lang.org"
//     Js.log("clicked!");
//     fs_add_meme()
// });


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
        Js.log("tags")
        Js.log(tags)
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

    // Get the meme from a selected meme.id
    let selected_meme : string => unit = item_id => { 
        let m = List.find( (mi : TT.fs_meme_t) => mi.id == item_id, memes )
        cb_fetch_selected(m) 
    };

    // Render the list of memes
    <div> 
        <RenderItemList4 items=memes cb_selection=selected_meme/>
    </div>
 
};