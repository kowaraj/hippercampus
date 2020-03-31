let str = ReasonReact.string;

type state = {
    count: int
};

type memeType = {
    id: int, 
    name: string, 
    text: string, 
    url: string
};

type action = 
  | Check;

[@react.component]
let make = (~m) => {
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
                src=m.url /> 
        </div>

    </div>
};