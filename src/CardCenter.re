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
        <br/>
        {str("--meme--")}
        <Meme />
        {str("--meme--")}
        <br/>
    </div>
};
