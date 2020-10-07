// ReasonML wrapper for the Firestore database interface in Firestore.js

[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: ( (string, TT.fs_meme_t) => unit) => unit = "memes_onSnapshot";

[@bs.val] external document: 'a = "document";
// call a method
document##addEventListener("mouseup", _event => {
  let loc = document##location;

  ////    document##location##href = "rescript-lang.org";

  Js.log("clicked!");
});

// get a property

// set a property

[@bs.get] external getName: TT.fs_meme_t => string = "text";

[@react.component]
let make = () => {

    let (memes, setMemes) = React.useState( () => [] );

    let add_meme = (m_id, m:TT.fs_meme_t) => {
        Js.log("Db.re: add_meme:")
//        Js.log(m)
        Js.log(getName(m))
        Js.log(m.name)




        let mm : TT.fs_meme_t = {id: m_id, name: m.name, text: m.text, fn: m.fn, tags: m.tags};
//        Js.log(mm)
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