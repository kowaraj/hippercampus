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
        {str("BOTTOM OF THE CARD - " ++ string_of_int({state.count}))}
    </div>
};
