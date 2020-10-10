let str = ReasonReact.string;

type state = {
    count: int
};

type item = {
    url: string, 
    id: int, 
    name: string
};

type action = 
  | Check;

[@react.component]
let make = (~item) => {
    let (_state, _dispatch) = React.useReducer( (state, action) => 
    switch (action) { 
    | Check => {count: state.count + 1}
    },
    {count: 0});

    <div style=Style.h>
        <p> {str("id = " ++ string_of_int(item.id) ++ ", name = " ++ item.name)} </p> 

        <img 
            style=(ReactDOMRe.Style.make(~maxWidth="100px", ~maxHeight="50px", () ))  
            src=item.url /> 
    </div>
};