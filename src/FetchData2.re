let str = ReasonReact.string;
type state = {
    input: string, 
    isLoading: bool
};
type action = 
    | UpdateInput(string)
    | FetchData
    | FetchDataX(string);

let doFetchData = () => {
    Js.log("doFetchData: fetching :3000/test_be/2 ");
    Js.Promise.(
        Fetch.fetch("http://localhost:3000/test_be/2")
        |> then_(Fetch.Response.json)
        |> then_({res => {
            res
            |> Decode.files 
            |> ( fs => {  /*Js.log(fs);*/    Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { /*Js.log(_err);*/     resolve(None); } })
    );
};

let test_url = "http://localhost:3000/uploads/ss_6.png";

[@react.component]
let make = () => {

    // .state 

    let (x, setX) = React.useState( () => "initial value of x" );
    let (y, setY) = React.useState( () => "initial y" );
    let (z, setZ) = React.useState( () => [] );

    // .effect

    React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
        () => { 
            Js.log("Fired: useEffect1: [" ++ x ++ "] - HERE you can call fetching the data from the backend!")
            Js.Promise.(
                doFetchData()
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    //Js.log(data);
                                    setY(_ => "some files have been fetched!");
                                    setZ(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("NONE! no data fetched");
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
    
    // .reducer

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

    // .render

    <div>
        {str("FETCH DATA FORM")} <br />

        <br />
            <form
                onSubmit={ ev => {
                    Js.log("onSubmit called...")
                    let _ev_val = ReactEvent.Form.target(ev)##value;
                    ReactEvent.Form.preventDefault(ev);
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

        {str("RESULTS OF THE FETCH")} <br /> 

        {str("Input: " ++ ss.input ++ ", isLoading? = " ++ string_of_bool(ss.isLoading))}
        <br/>
        {str("Y === " ++ y)}
        <br/>

        <div className="items-files">
        (
            React.array(
                Array.of_list(
                    List.map(
                        (zi : Decode.f) => 
                            <RenderItem url={"http://localhost:3000/uploads/" ++ zi.fn} />,
                        z
                    )
                )
            )
        )
        </div>

    </div>
    }
};

