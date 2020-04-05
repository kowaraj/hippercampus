[@react.component]
let make = (~m : Decode.meme_t) => {

    let (modal, setModal) = React.useState( () => false);
    let invert_modal = () => setModal( _ => !modal);
    let get_modal_style = () => { modal ? StyleMeme.modal : StyleMeme.non_modal };

    let (modal2, setModal2) = React.useState( () => false);
    let invert_modal2 = () => setModal2( _ => !modal2);
    let get_modal_style2 = () => { modal2 ? StyleMeme.modal2 : StyleMeme.non_modal2 };
    let my_image_on_click = () => { 
        invert_modal2()
    };

    <div>
        <div style=StyleMeme.container>

            <p style=StyleMeme.name> {RR.str("{" ++ m.name ++ "}")} </p> 
            <p style=StyleMeme.text> {RR.str("<" ++ m.text ++ ">")} </p> 
//            <img style=StyleMeme.image src=m.fn /> 
            <p style=StyleMeme.tags> {RR.str("[" ++ (String.concat("", m.tags)) ++ "]")} </p> 

// //            <button id="myBtn" onClick={e_=>{ setModal( _=> !modal); }}> {RR.str("open modal")}</button>
//             <button id="myBtn" onClick={ _=>invert_modal() }> {RR.str("open modal")}</button>
//             <div id="myModal" className="modal" style={ get_modal_style() }>
//                 <div className="modal-content" style=StyleMeme.modal_content>
//                     <span className="close" onClick={ _=>invert_modal()}>{ RR.str({js|\u2297|js})}</span>
//                     <p>{RR.str("Some text in the Modal..")}</p>
//                 </div>
//             </div>

            <img id="myImg2" style=StyleMeme.image2 src=m.fn alt="meme image2" onClick={ _=>my_image_on_click() }/> 
            <div id="myModal2" className="modal2" style={ get_modal_style2() }>
                //<span style=StyleMeme.modal_close2 className="close2" onClick={ _=>invert_modal2()}>{ RR.str({js|\u2297|js})}</span>
                <img id="img02" src=m.fn style=StyleMeme.modal_content2 onClick={ _=>invert_modal2()}/> 
                <div id="caption2"></div>
            </div>


        </div>

    </div>
};