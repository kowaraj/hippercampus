
[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: ( (string, TT.fs_meme_t) => unit) => unit = "memes_onSnapshot";


[@react.component]
let make = () => {

    let (memes, setMemes) = React.useState( () => [] );

    let add_meme = (m_id, m:TT.fs_meme_t) => {
        Js.log(">>> add_meme:")
        Js.log(m)
//        Js.log(nameGet(m))

        let mm : TT.fs_meme_t = {id: m_id, name: m.name, text: m.text, fn: m.fn, tags: m.tags};
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