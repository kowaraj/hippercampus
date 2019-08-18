let str = ReasonReact.string;

let testitems : list(TodoItem.todoitem) = [{id: 0, title: "testItem1name", completed: false}];
// let testitem1 : TodoItem.todoitem = {id: 0, title: "testItem1name", completed: false};

type state = {
    input: string, 
    isLoading: bool
};

type action = 
    | UpdateInput(string)
    | FetchData
    | FetchDataX(string);


let doFetchData = () => {
    Js.log("fake fetching data..........");
    Js.Promise.(
      Fetch.fetch("http://localhost:3000/test_be")
      |> then_(Fetch.Response.text)
      |> then_(res => {
            Js.log(res);
            resolve(Some(res));
            })
      |> catch( { 
          _err => {Js.log(_err); 
          resolve(None);
          } })

    );
};

[@react.component]
let make = () => {
    let (x, setX) = React.useState( () => "initial value of x" );
    let (y, setY) = React.useState( () => "initial y" );

    React.useEffect1( // TODO: How NOT to trigger this "effect" at the componentMount time
        () => { 
            Js.log("Fired: useEffect1")
            Js.log(x); 
            Js.log("HERE you can call fetching the data from the backend!")


            //setY(_ => doFetchData());

            Js.Promise.(
                doFetchData()
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    Js.log(data);
                                    setY(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("no data fetched");
                                    setY(_ => "no data fetched");
                                    resolve();
                                    }
                            }
                        })
                |> ignore                            
            )

            
            None;
            }, 
        [|x|],
    );
    
    let (ss, dispatch) = 
        React.useReducer( 
            (state, action) => switch (action) { 
                | UpdateInput(newInput) => {...state, input: newInput}
                | FetchData => { Js.log("STATE=2"); setX(_ => "test"); {...state, isLoading: true }}
                | FetchDataX(d) => { Js.log("STATE=3, d=="++d); setX(_ => d); {...state, isLoading: true }}
                },
            {input: "Initial input", isLoading: false}
        );

    {
    <div>
        {str("BACKEND DATA")}

        <br />
            <form
                onSubmit={ ev => {
                    Js.log("onSubmit called...")
                    let ev_val = ReactEvent.Form.target(ev)##value;
                    ReactEvent.Form.preventDefault(ev);
//                    dispatch(FetchData);
                    dispatch(FetchDataX(ss.input));
                }}>

                <label htmlFor="search"> {str("Search")} </label>
                <input 
                    id="search" 
                    name="search " 
                    value={ss.input} 
                    onChange={ev => {
                        let value = ReactEvent.Form.target(ev)##value;
                        dispatch(UpdateInput(value))
                    }}
                />
                <button type_="submit">
                    {str("Submit Search")}
                </button>
                
            </form>
        <br />

        {str("Input: " ++ ss.input ++ ", isLoading? = " ++ string_of_bool(ss.isLoading))}
        <br/>
        {str("Y === " ++ y)}
    </div>
    }
};

