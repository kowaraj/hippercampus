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
            <p> {str("id = " ++ string_of_int(m.id))} </p> 
            <p> {str("name = " ++ m.name)} </p> 
            <p> {str("text = " ++ m.text)} </p> 
            <img 
                style=Style.h_meme_url 
                src=m.url /> 
        </div>

    </div>
};