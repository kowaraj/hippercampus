let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle
  | GetForm;

[@react.component]
let make = () => {
    let (state, dispatch) = React.useReducer((state, action) =>
    switch (action) {
    | Click => {...state, count: state.count + 1}
    | Toggle => {...state, show: ! state.show}
    | GetForm => state
    }, {count: 0, show: true});

    let message =
        "CLICK " ++ string_of_int(state.count) ++ " # ";

    // let get_form = () => {
    //         <form 
    //             id="uploadForm"
    //             action="localhost:8000/upload"
    //             method="post"
    //             encType="multipart/form-data">
    //             <input type_="file" name="sampleFile" />
    //             <input type_="submit" value="Upload!" />
    //         </form>
    // };
        
    <div>
        <button onClick={_event => dispatch(Click)}>
            {str(message)}
        </button>
        <button onClick={_event => dispatch(GetForm)}>
            {str("GET FORM")}
        </button>

        <button onClick={_event => dispatch(Toggle)}>
            {str("TOGGLE")}
        </button>
        {state.show ? str("No greetings today") : ReasonReact.null}

        <div>
            // {get_form()}
        </div>

    </div>;
};
