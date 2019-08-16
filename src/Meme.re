let str = ReasonReact.string;

type state = {
    count: int
};

type action = 
  | Check;

[@react.component]
let make = () => {
    let (state, dispatch) = React.useReducer( (state, action) => 
    switch (action) { 
    | Check => {...state, count: state.count + 1}
    },
    {count: 0});

    <div>
        <img 
            style=(ReactDOMRe.Style.make(~maxWidth="400px", ~maxHeight="200px", () ))  
            src="http://localhost:3000/uploads/ss_0.png" /> 
    </div>
};
