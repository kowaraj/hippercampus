let str = ReasonReact.string;

type state = {
    count: int
};

type item = {
    url: string, 
    id: int
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
        <p> {str("RenderItem: id = " ++ string_of_int(item.id))} </p> 
        <img 
            style=(ReactDOMRe.Style.make(~maxWidth="200px", ~maxHeight="100px", () ))  
            src=item.url /> 
    </div>
};