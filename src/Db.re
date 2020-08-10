[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: ( (string, string) => unit) => unit = "memes_onSnapshot";


[@react.component]
let make = () => {

    let (memes, setMemes) = React.useState( () => [] );

    let add_meme = (m_id, m_name) => {
        Js.log(m_id)
        Js.log(m_name)

        let mm : TT.fs_meme_t = {id: m_id, name: m_name, text: "text", fn: "fn", tags: ["t1", "t2"]};
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