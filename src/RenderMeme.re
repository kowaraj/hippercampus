[@react.component]
let make = (~m : Decode.meme_t) => {

    <div>
        <div style=StyleMeme.container>
            <p style=StyleMeme.name> {RR.str("{" ++ m.name ++ "}")} </p> 
            <p style=StyleMeme.text> {RR.str("<" ++ m.text ++ ">")} </p> 
            <img 
                style=StyleMeme.image 
                src=m.fn 
                /> 
            <p style=StyleMeme.tags> {RR.str("[" ++ (String.concat("", m.tags)) ++ "]")} </p> 

            <button id="myBtn"> {RR.str("open modal")}</button>
            <div id="myModal" className="modal">
                <div className="modal-content">

                    // <span className="close">{ RR.str( {js|\u00a9|js}) }</span>
                    // <span className="close">{ RR.str( {js|©|js})      }</span>
                    // <span className="close">{ [%raw   {|'\u00a9'|}]   }</span>
                    <span className="close">{ RR.str({js|\u2297|js})}</span>

                    <p>{RR.str("Some text in the Modal..")}</p>
                </div>
            </div>


        </div>

    </div>
};