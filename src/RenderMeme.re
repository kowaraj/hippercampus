[@react.component]
let make = (~m : Decode.meme_t) => {

    let (modal, setModal) = React.useState( () => false);
    let invert_modal = () => setModal( _ => !modal);
    let get_modal_style = () => { modal ? StyleMeme.modal : StyleMeme.non_modal };

    <div>
        <div style=StyleMeme.container>

            <p style=StyleMeme.name> {RR.str("{" ++ m.name ++ "}")} </p> 
            <p style=StyleMeme.text> {RR.str("<" ++ m.text ++ ">")} </p> 
            <p style=StyleMeme.tags> {RR.str("[" ++ (String.concat("", m.tags)) ++ "]")} </p> 

            <img style=StyleMeme.image src=m.fn alt="meme image" onClick={ _=>invert_modal() }/> 
            <div className="modal" style={ get_modal_style() } onClick={ _=>invert_modal()}>
                <img src=m.fn style=StyleMeme.modal_content onClick={ _=>invert_modal()}/> 
            </div>

        </div>

    </div>
};