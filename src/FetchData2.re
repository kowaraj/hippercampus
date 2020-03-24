let str = ReasonReact.string;
type state = {
    input: string, 
    isLoading: bool
};
type action = 
    | UpdateInput(string)
    | FetchData
    | FetchDataX(string);

// let doFetchData_ql = (x2) => {
//     let req_str = "{\"query\":\"{allPosts {edges {node {id } }}}\",\"variables\":null,\"operationName\":null}";
//     Js.log(">> arq: " ++x2);
//     Js.log(">> req: " ++req_str);
    
    
//     Js.Promise.(
//         Fetch.fetchWithInit(
//             Config.url_ql, // ++ ql_req2, 
//             Fetch.RequestInit.make(
//                 ~method_=Post, 
//                 ~body=Fetch.BodyInit.make(x2),
//                 ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json", "Access-Control-Allow-Origin": "*" }),
//                 ()), 

//         )
//         |> then_(Fetch.Response.text)
//         |> then_({res => {
//             Js.log("post-Fetching of _ql:")
//             // Some(res) |> resolve
//             res
//             |> ( fs => {  Js.log(fs);    Some(fs)   }    |> resolve)
//             }})
//         |> catch({_err => { Js.log(_err);     resolve(None); } })
//     );
// };

let doFetchData = () => {
    Js.log("Fetching the backend database... (doFetchData)");
    Js.Promise.(
        Fetch.fetch(Config.url_be_root++"/getmemes")
        |> then_(Fetch.Response.json)
        |> then_({res => {
            Js.log(res);
            res
            |> Decode.files 
            |> ( fs => {  /*Js.log(fs);*/    Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { Js.log(_err);     resolve(None); } })
    );
};

let doFetchMeme = (m) => {
    Js.log("Fetching a meme from the backend database... (doFetchMeme)");
    Js.Promise.(
        Fetch.fetch(Config.url_be_root++"/getmeme/"++m)
        |> then_(Fetch.Response.json)
        |> then_({res => {
            Js.log(res);
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
    let (current_meme, setCurrentMeme) = React.useState( () => "name1" );
    let (meme_to_fetch, setMemeToFetch) = React.useState( () => "initial value of meme_to_fetch" );
    let (fetched_meme, setFetchedMeme) = React.useState( () => [] );

    let (x2, setX2) = React.useState( () => "{\"query\":\"{allPosts {edges {node {id } }}}\"}" );
    let (x3, setX3) = React.useState( () => "initial value of x3" );
    let (y, setY) = React.useState( () => "initial y" );
    let (z, setZ) = React.useState( () => [] );
    let (z2, setZ2) = React.useState( () => "");
    let (z3, setZ3) = React.useState( () => "");

    // .effect

    React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
        () => { 
            Js.log("Fired! - useEffect1(x) with x == [" ++ x ++ "]")
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
                                    Js.log("OBSOLETE? NONE! no data fetched");
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
            Js.log("Fired! - useEffect1(meme_to_fetch) with current_meme == [" ++ current_meme ++ "]")
            Js.Promise.(
                doFetchMeme(current_meme)
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    Js.log(data);
                                    setFetchedMeme(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("THIS one - NONE! no data fetched");
                                    setY(_ => "no data fetched");
                                    resolve();
                                    }
                            }
                        })
                |> ignore                            
            )
            None;
            }, 
        [|meme_to_fetch|],
    );

    React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
        () => { 
         switch (x3) {
         | "" => {Js.log("x3 hasn't changed"); None}
         | x3 => {
            Js.log("Fired! useEffect1(x3) with x3 == [" ++ x3 ++ "] ")
            setZ3(_=>x3)
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
                | FetchData => { Js.log("fetchdata: STATE=2"); setX(_ => "test"); {...state, isLoading: true }}
                | FetchDataX(m) => { Js.log("fetchdata: STATE=3, m=="++m); setMemeToFetch(_ => m); {...state, isLoading: true }}
                },
            {input: "Initial input", isLoading: false}
        );
    {

    // .render

    <div>

        // {str("SEARCH:")} <br />
        // <br />
        //     <form
        //         onSubmit={ ev => {
        //             Js.log("onSubmit called...")
        //             Js.log(ev);
        //             // let _ev_val = ReactEvent.Form.target(ev)##value;
        //             // ReactEvent.Form.preventDefault(ev);
        //             Js.log("current_meme == " ++ current_meme)
        //             dispatch(FetchDataX(current_meme));
        //         }}>
        //         <label htmlFor="search"> {str("Fetch a meme: ")} </label>                
        //         <input 
        //             style=(ReactDOMRe.Style.make(~width="600px", () ))  
        //             id="x2_input_id" 
        //             name="x666_input_name666" 
        //             value={current_meme} 
        //             onChange={ev => {
        //                 let value = ReactEvent.Form.target(ev)##value;
        //                 setCurrentMeme(value)
        //             }}
        //         />
        //     </form>
        // <br />

        //<RenderItemList items=fetched_meme />

      <RenderItemList items=z />


        // {str("---RESULTS OF THE FETCH")} <br /> 

        // {str("Input: " ++ ss.input ++ ", isLoading? = " ++ string_of_bool(ss.isLoading))}
        // <br/>
        // {str("Y === " ++ y)}
        // <br/>
        // <br/>        {str("Z3 (request)=== " ++ z3)}        <br/>
        // <br/>        {str("Z2 (reply)=== " ++ z2)}        <br/>


        // {str("FETCH DATA FORM")} <br />
        // <br />
        //     <form
        //         onSubmit={ ev => {
        //             Js.log("onSubmit called...")
        //             let _ev_val = ReactEvent.Form.target(ev)##value;
        //             ReactEvent.Form.preventDefault(ev);
        //             dispatch(FetchDataX(ss.input));
        //         }}>
        //         <label htmlFor="search"> {str("Request: ")} </label>                
        //         <input 
        //             style=(ReactDOMRe.Style.make(~width="600px", () ))  
        //             id="x2_input_id" 
        //             name="x777_input_name777" 
        //             value={x2} 
        //             onChange={ev => {
        //                 let value = ReactEvent.Form.target(ev)##value;
        //                 setX2(value)
        //             }}
        //         />
        //         <button 
        //             onClick={_ev => {
        //                 setX3(_ => x2)
        //                 }}>
        //             {str("X2->X3")}
        //         </button>
        //         <br />
        //         <button 
        //             onClick={_ev => {
        //                 setX3(_ => "")
        //                 }}>
        //             {str("X2->\"\"")}
        //         </button>               
        //     </form>
        // <br />

    </div>
    }
};

