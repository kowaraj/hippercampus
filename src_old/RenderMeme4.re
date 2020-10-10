//[%bs.raw {|require('./meme.css')|}];

[@react.component]
let make = (~m : TT.fs_meme_t) => {

    let (modal, setModal) = React.useState( () => false);
    let invert_modal = () => setModal( _ => !modal);
//    let get_modal_style = () => { modal ? StyleMeme.modal : StyleMeme.non_modal };

    let y = String.length(m.name);
    let x = string_of_int( 12 - y/3 );

    <div>
        <div>
            <p> {RR.str(m.name)} </p> 
            <p> {RR.str(m.text)} </p> 
            <p> {RR.str((String.concat("", m.tags)))} </p> 

            <img src=m.fn alt="meme image" onClick={ _=>invert_modal() }/> 
            <div className="modal" onClick={ _=>invert_modal()}>
                <img src=m.fn onClick={ _=>invert_modal()}/> 
            </div>

        </div>

    </div>
};