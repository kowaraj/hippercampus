let str = ReasonReact.string;

type state = {
    count: int
};
// type meme_t  = {
//     id: int,
//     name: string, 
//     text: string, 
//     fn: string, 
//     tags: list(string)
//     };

// type memeType = {
//     id: int, 
//     name: string, 
//     text: string, 
//     fn: string, 
//     tags: list(string)
// };

type action = 
  | Check;

[@react.component]
let make = (~m : Decode.meme_t) => {

    let (_state, _dispatch) = React.useReducer( (state, action) => 
    switch (action) { 
    | Check => {count: state.count + 1}
    },
    {count: 0});

    <div>
       //{str(" ")} 
       //<br /> 
        <div style=Style.h_meme>
            //<p> {str("id = " ++ string_of_int(m.id))} </p> 
            <p style=Style.h_meme_name> {str("{" ++ m.name ++ "}")} </p> 
            <p style=Style.h_meme_text> {str("<" ++ m.text ++ ">")} </p> 
            <img 
                style=Style.h_meme_image 
                src=m.fn /> 
            <p style=Style.h_meme_text> {str("[" ++ (String.concat("", m.tags)) ++ "]")} </p> 
        </div>

    </div>
};