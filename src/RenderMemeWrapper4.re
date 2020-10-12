[@bs.module "./Firestore.js"] external fs_add_meme: ( TT.new_meme_t => unit ) =  "add_meme";
[@bs.module "./Firestore.js"] external fs_mod_meme: ( TT.upd_meme_t => unit ) =  "mod_meme";
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
    let button_mod_meme = (_e) => {
        let m = {"id": memeId, "name": memeName, "text": memeText, "fn": memeFn, "tags": memeTags}
        fs_mod_meme(m);
    };
    let button_del_meme = (_e) => {
        fs_del_meme(memeId);
    };
    let (modal, setModal) = React.useState( () => false);
    let invert_modal = () => setModal( _ => !modal);
    //let get_modal_style = () => { modal ? StyleMeme.modal : StyleMeme.non_modal };

    React.useEffect1( () => {
        setMemeId( _ => fetched_meme.id )
        setMemeName( _ => fetched_meme.name )
        setMemeText( _ => fetched_meme.text )
        setMemeFn( _ => fetched_meme.fn )
        setMemeTags( _ => Utils.list2str(fetched_meme.tags) )
        None
        },
        [|fetched_meme|],
    );

    <div>
        <input className="orange-text text-darken-5 center-align flow-text" value={memeName} 
            onChange={ev => {setMemeName(ReactEvent.Form.target(ev)##value)}}
            /> 

        <textarea className="box" value={memeText} 
            onChange={ev => {setMemeText(ReactEvent.Form.target(ev)##value)}}
            />                
        <input className="blue-text right-align" value={memeTags} 
            onChange={ev => {setMemeTags(ReactEvent.Form.target(ev)##value)}}
            /> 

        <div className="row">
            <div className="col s3">
                <button className="btn indigo" onClick=button_add_meme> {RR.str("Push")} </button> 
            </div>
            <div className="col s3">
                <button className="btn pink" onClick=button_del_meme> 
                    <span> {RR.str("DEL")} </span>
                    <i className="material-icons right"> {RR.str("cancel")} </i>
                </button> 
            </div>
            <div className="col s3">
                <button className="btn orange" onClick=button_mod_meme> {RR.str("UPD")} </button> 
            </div>

            // <div className="hide col s4">
            //     <div className="right">
            //         //<img style=StyleMeme.image src=memeFn alt="meme image" onClick={ _=>invert_modal() }/> 
            //         <img src=memeFn alt="image" onClick={ _=>invert_modal() }/> 
            //             //<div className="modal" style={ get_modal_style() } onClick={ _=>invert_modal()}>
            //             <p className="right-align"> RR.v </p>
            //         <div className="modal" onClick={ _=>invert_modal()}>
            //             //<img src=memeFn style=StyleMeme.modal_content onClick={ _=>invert_modal()}/> 
            //             <img src=memeFn onClick={ _=>invert_modal()}/> 
            //         </div>
            //     </div>
            // </div>

        </div>


    </div>

};



