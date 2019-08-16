let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
};

type action =
  | Click
  | Toggle
  | GetForm
  | Upload
  | Submit
  | InputText(string);

let upload_file = () => {
    Js.log("real uploading with fetch")


    Js.log("upload completed !")
};


let testitems : list(TodoItem.todoitem) = [{id: 0, title: "testItem1name", completed: false}];
let testitem1 : TodoItem.todoitem = {id: 0, title: "testItem1name", completed: false};




[@react.component]
let make = () => {
    let (state, dispatch) = React.useReducer((state, action) =>
    switch (action) {
    | Click => {...state, count: state.count + 1}
    | Toggle => {...state, show: ! state.show}
    | GetForm => state
    | Upload => {
        Js.log("fake uploading....");
        upload_file();
        state
    }
    | Submit => {
        Js.log("fake submit");
        state
    }
    | InputText(text) => {
        Js.log("fake InputText " ++ text);
        state
    } 
    }, {count: 0, show: true});

    let message =
        "CLICK " ++ string_of_int(state.count) ++ " # ";

    let get_form = () => {
            <form 
                id="uploadForm"
                action="http://localhost:3000/upload"
                method="post"
                encType="multipart/form-data">
                <input type_="file" name="sampleFile" />
                <input type_="submit" value="Upload!" />
            </form>
    };
        
    let fileSelected = () => {
        Js.log("fileSelected triggered!!!! ");
    };
    

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
            {get_form()}
        </div>

        <button onClick={_event => dispatch(Upload)}>
            {str("UPLOAD-with-FETCH")}
        </button>

        <input type_="file" onClick={_event => fileSelected()}>

        </input>

    <div className="items">
        (
        React.array(Array.of_list(
            List.map((item : TodoItem.todoitem) => <TodoItem 
                                    key=(string_of_int(item.id))
                                    item />, 
                    testitems)
         ))
       )
     </div>

    <div className="item1">
        <TodoItem key=(string_of_int(testitem1.id)) item=testitem1 />

    </div>
 
    <div className="title">
        (str("What to do"))
        <Input onSubmit=((text) => dispatch(InputText(text))) />
    </div>

    <div className="title">
        (str("What to do"))
        <FilePicker onSubmit=((text) => dispatch(InputText(text))) />
    </div>

        <div>
            
           <form 
                id="uploadForm"
                action="http://localhost:3000/upload"
                method="post"
                encType="multipart/form-data">
                <input type_="file" name="sampleFile" />
                <input type_="submit" value="Upload!" />
            </form>


        </div>
          
    </div>;
};
