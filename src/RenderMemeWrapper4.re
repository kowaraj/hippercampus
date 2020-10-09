[@bs.module "./Firestore.js"] external fs_add_meme: ( TT.new_meme_t => unit ) =  "add_meme";
[@bs.module "./Firestore.js"] external fs_del_meme: ( string => unit ) =  "del_meme";

[@react.component]
let make = (~fetched_meme : TT.fs_meme_t) => {

    let (memeId, setMemeId    ) = React.useState( () => fetched_meme.id   );
    let (memeName, setMemeName) = React.useState( () => fetched_meme.name );
    let (memeText, setMemeText) = React.useState( () => fetched_meme.text );
    let (memeFn,   setMemeFn  ) = React.useState( () => fetched_meme.fn   );
    let (memeTags, setMemeTags) = React.useState( () => Js.String2.make(fetched_meme.tags) );

    let button_add_meme = (_e) => {
        let m = {"name": memeName, "text": memeText, "fn": memeFn, "tags": memeTags}
        fs_add_meme(m);
    };
    let button_del_meme = (_e) => {
        fs_del_meme(memeId);
    };
    let (modal, setModal) = React.useState( () => false);
    let invert_modal = () => setModal( _ => !modal);
    let get_modal_style = () => { modal ? StyleMeme.modal : StyleMeme.non_modal };

    React.useEffect1( () => {
        setMemeId( _ => fetched_meme.id )
        setMemeName( _ => fetched_meme.name )
        setMemeText( _ => fetched_meme.text )
        setMemeFn( _ => fetched_meme.fn )
        setMemeTags( _ => Js.String2.make(fetched_meme.tags) )
        None
        },
        [|fetched_meme|],
    );

    <div>
        <input style=StyleUpload.input type_="text" name="name" value={memeName} 
            onChange={ev => {setMemeName(ReactEvent.Form.target(ev)##value)}}
            /> 
            <br />
        <textarea style=StyleUpload.textarea type_="text" id="searchtext" name="text" value={memeText} 
            onChange={ev => {setMemeText(ReactEvent.Form.target(ev)##value)}}
            />                
        <input style=StyleUpload.input_tags type_="text" name="tags" value={memeTags} 
            onChange={ev => {setMemeTags(ReactEvent.Form.target(ev)##value)}}
            /> 
            <br />
        <img style=StyleMeme.image src=memeFn alt="meme image" onClick={ _=>invert_modal() }/> 
            <div className="modal" style={ get_modal_style() } onClick={ _=>invert_modal()}>
                <img src=memeFn style=StyleMeme.modal_content onClick={ _=>invert_modal()}/> 
            </div>
            <br />
        <button style=StyleUpload.add_meme_button onClick=button_add_meme> {RR.str("Push")} </button> 
        <button style=StyleUpload.add_meme_button onClick=button_del_meme> {RR.str("Kill")} </button> 
        <br />
    </div>

};



