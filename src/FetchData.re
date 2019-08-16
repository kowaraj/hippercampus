let str = ReasonReact.string;

let testitems : list(TodoItem.todoitem) = [{id: 0, title: "testItem1name", completed: false}];
// let testitem1 : TodoItem.todoitem = {id: 0, title: "testItem1name", completed: false};

type state = {
    input: string, 
    isLoading: bool
};

type action = 
    | UpdateInput(string)
    | FetchData;

[@react.component]
let make = () => {
    let (ss, dispatch) = 
        React.useReducer( 
            (state, action) => switch (action) { 
                | UpdateInput(newInput) => {...state, input: newInput}
                | FetchData => {...state, isLoading: true}
                }, 
            {input: "Initial input", isLoading: false}
        );

    {
    <div>
        {str("BACKEND DATA")}
        // <div className="items">
        // (
        //     React.array(Array.of_list(
        //         List.map((item : TodoItem.todoitem) => <TodoItem 
        //                                 key=(string_of_int(item.id))
        //                                 item />, 
        //                 testitems)
        //     ))
        // )
        // </div>
    </div>
    }
};

