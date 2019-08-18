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


let doFetchData = () => {
    Js.log("fake fetching data..........");
    Js.Promise.(
      Fetch.fetch("http://localhost:3000/test_be")
      |> then_(Fetch.Response.text)
      |> then_(res => {
            Js.log(res);
            resolve(res);
            })
      |> catch( { 
          _err => {Js.log(_err); 
          resolve("errr");
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
                            Js.log(result);
                            setY(_ => result);
                            resolve();
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
                | FetchData => { setX(_ => "test"); {...state, isLoading: true }}
                },
            {input: "Initial input", isLoading: false}
        );

    {
    <div>
        {str("BACKEND DATA")}

        <br />
            <form
                onSubmit={ ev => {
                    ReactEvent.Form.preventDefault(ev);
                    dispatch(FetchData);
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

