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
[@bs.get] external getFn: TT.fs_meme_t => string = "fn";
[@bs.get] [@bs.return nullable] external getTags: TT.fs_meme_t => option(string) = "tags";


[@react.component]
let make = () => {

    let (memes, setMemes) = React.useState( () => [] );

    let add_meme = (m_id, m:TT.fs_meme_t) => {
        Js.log("Db.re: add_meme:")
        Js.log(m)
        let tags = getTags(m) // option(string), bs.nullable => might be undefined!
        let tags_array = {
                switch tags {
                | Some(s) => Array.to_list(Js.String2.split(s, " "));
                | None => ["no tags found"]
                }
        };
        let mm : TT.fs_meme_t = {id: m_id, name: getName(m), text: getText(m), fn: getFn(m), tags: tags_array}
        setMemes( ms => List.append(ms, [ mm ] ) )
    };

    React.useEffect0( () => { 
        fs_memes_onSnapshot(add_meme)
        None;
    });

    <div> 
        <RenderItemList4 items=memes/>
    </div>
 
};