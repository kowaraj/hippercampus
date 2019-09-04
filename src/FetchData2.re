let str = ReasonReact.string;
type state = {
    input: string, 
    isLoading: bool
};
type action = 
    | UpdateInput(string)
    | FetchData
    | FetchDataX(string);



let ql_req2 = "{
  allPosts {
    edges {
      node {
        id
      }
    }
  }
}";

let doFetchData_ql = () => {
    Js.log("doFetchData_ql: fetching..");
    Js.Promise.(
        Fetch.fetchWithInit(
            Config.url_ql, // ++ ql_req2, 
            Fetch.RequestInit.make(
                ~method_=Post, 
                ~body=Fetch.BodyInit.make("{\"query\":\"{allPosts {edges {node {id } }}}\",\"variables\":null,\"operationName\":null}"),
                ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json", "Access-Control-Allow-Origin": "*" }),

                ()), 

        )
        |> then_(Fetch.Response.text)
        |> then_({res => {
            Some(res) |> resolve
            |> ( fs => {  Js.log(fs);    Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { Js.log(_err);     resolve(None); } })
    );
};

let req_ql = (e) => {
    Js.log("REQ_QL: !!!")
    doFetchData_ql() |>ignore;
    e |>ignore;
    ();
}

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

            //doFetchData_ql() |> ignore;


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
                
                <button onClick=req_ql>
                    {str("QL req")}
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
            List.map(
                (zi : Decode.f) => {
                    let i : RenderItem2.item = { url: "http://localhost:3000/uploads/" ++ zi.fn, id: zi.id};
                    <RenderItem2 key=string_of_int(zi.id) item=i />
                },
                z)
            |> Array.of_list
            |> React.array
        )
        </div>

    </div>
    }
};

