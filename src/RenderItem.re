let str = ReasonReact.string;

type state = {
    count: int
};

type action = 
  | Check;

[@react.component]
let make = (~url) => {
    let (_state, _dispatch) = React.useReducer( (state, action) => 
    switch (action) { 
    | Check => {count: state.count + 1}
    },
    {count: 0});

    <div>
        <img 
            style=(ReactDOMRe.Style.make(~maxWidth="200px", ~maxHeight="100px", () ))  
            src=url /> 
    </div>
};