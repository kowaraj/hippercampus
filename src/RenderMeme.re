[@react.component]
let make = (~m : Decode.meme_t) => {

    let (modal, setModal) = React.useState( () => false);
    let invert_modal = () => setModal( _ => !modal);
    let get_modal_style = () => { modal ? StyleMeme.modal : StyleMeme.non_modal };

    <div>
        <div style=StyleMeme.container>
            <p style=StyleMeme.name> {RR.str("{" ++ m.name ++ "}")} </p> 
            <p style=StyleMeme.text> {RR.str("<" ++ m.text ++ ">")} </p> 
            <img 
                style=StyleMeme.image 
                src=m.fn 
                /> 
            <p style=StyleMeme.tags> {RR.str("[" ++ (String.concat("", m.tags)) ++ "]")} </p> 

//            <button id="myBtn" onClick={e_=>{ setModal( _=> !modal); }}> {RR.str("open modal")}</button>
            <button id="myBtn" onClick={ _=>invert_modal() }> {RR.str("open modal")}</button>
            <div id="myModal" className="modal" style={ get_modal_style() }>
                <div className="modal-content" style=StyleMeme.modal_content>
                    <span className="close" onClick={ _=>invert_modal()}>{ RR.str({js|\u2297|js})}</span>
                    <p>{RR.str("Some text in the Modal..")}</p>
                </div>
            </div>


        </div>

    </div>
};