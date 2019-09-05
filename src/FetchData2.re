let str = ReasonReact.string;
type state = {
    input: string, 
    isLoading: bool
};
type action = 
    | UpdateInput(string)
    | FetchData
    | FetchDataX(string);

let doFetchData_ql = (x2) => {
    let req_str = "{\"query\":\"{allPosts {edges {node {id } }}}\",\"variables\":null,\"operationName\":null}";
//  ___________ = {"query":"{allPosts {edges {node {id } }}}","variables":null,"operationName":null}
//  ___________ = {"query":"{allPosts {edges {node {id } }}}"}
//  ___________ = {"query": "mutation {  createPost(username:"johndoe", title:"Hello 2", body:"Hello body 2"){post{title body author{ username }}}}""
    Js.log(">> arq: " ++x2);
    Js.log(">> req: " ++req_str);
    
    
    Js.Promise.(
        Fetch.fetchWithInit(
            Config.url_ql, // ++ ql_req2, 
            Fetch.RequestInit.make(
                ~method_=Post, 
                ~body=Fetch.BodyInit.make(x2),
//                ~body=Fetch.BodyInit.make(req_str),
                ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json", "Access-Control-Allow-Origin": "*" }),
                ()), 

        )
        |> then_(Fetch.Response.text)
        |> then_({res => {
            Js.log("post-Fetching of _ql:")
            // Some(res) |> resolve
            res
            |> ( fs => {  Js.log(fs);    Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { Js.log(_err);     resolve(None); } })
    );
};

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
    let (x2, setX2) = React.useState( () => "{\"query\":\"{allPosts {edges {node {id } }}}\"}" );
    let (x3, setX3) = React.useState( () => "initial value of x3" );
    let (y, setY) = React.useState( () => "initial y" );
    let (z, setZ) = React.useState( () => [] );
    let (z2, setZ2) = React.useState( () => "");
    let (z3, setZ3) = React.useState( () => "");

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

    React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
        () => { 
         switch (x3) {
         | "" => {Js.log("x3 hasn't changed"); None}
         | x3 => {
            Js.log("Fired: useEffect1, X3 == [" ++ x3 ++ "] ")
            setZ3(_=>x3)
            Js.Promise.(
                doFetchData_ql(x3)
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    Js.log("End of promise! data = ")
                                    Js.log(data);
                                    setY(_ => "X3: some files have been fetched!");
                                    setZ2(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("NONE! no data fetched");
                                    setY(_ => "X3: no data fetched");
                                    resolve();
                                    }
                            }
                        })
                |> ignore                            
            )
            None;
         }}
        },          
        [|x3|],
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

                <label htmlFor="search"> {str("Request: ")} </label>                
                <input 
                    style=(ReactDOMRe.Style.make(~width="600px", () ))  
                    id="x2_input_id" 
                    name="x2_input_name" 
                    value={x2} 
                    onChange={ev => {
                        let value = ReactEvent.Form.target(ev)##value;
                        setX2(value)
                    }}
                />

                <button 
                    onClick={_ev => {
                        setX3(_ => x2)
                        }}>
                    {str("X2->X3")}
                </button>
                <br />
                <button 
                    onClick={_ev => {
                        setX3(_ => "")
                        }}>
                    {str("X2->\"\"")}
                </button>               
            </form>
        <br />

        {str("RESULTS OF THE FETCH")} <br /> 

        {str("Input: " ++ ss.input ++ ", isLoading? = " ++ string_of_bool(ss.isLoading))}
        <br/>
        {str("Y === " ++ y)}
        <br/>
        <br/>        {str("Z3 (request)=== " ++ z3)}        <br/>
        <br/>        {str("Z2 (reply)=== " ++ z2)}        <br/>
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

