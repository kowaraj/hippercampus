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
        </div>

    </div>
};