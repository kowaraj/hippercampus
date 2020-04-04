let str = ReasonReact.string;

type state = {
    count: int
};

type action = 
  | Check;

[@react.component]
let make = (~m : Decode.meme_t) => {

    <div>
        <div style=Style.h_meme>
            <p style=Style.h_meme_name> {str("{" ++ m.name ++ "}")} </p> 
            <p style=Style.h_meme_text> {str("<" ++ m.text ++ ">")} </p> 
            <img 
                style=Style.h_meme_image 
                src=m.fn /> 
            <p style=Style.h_meme_text> {str("[" ++ (String.concat("", m.tags)) ++ "]")} </p> 
        </div>

    </div>
};