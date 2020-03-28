// let str = ReasonReact.string;
// type state = {
//     input: string, 
//     isLoading: bool
// };
// type action = 
//     | UpdateInput(string)
//     | FetchData
//     | FetchDataX(string);


// let doFetchData = () => {
//     Js.log("Fetching the backend database... (doFetchData)");
//     Js.Promise.(
//         Fetch.fetch(Config.url_be_root++"/getmemes")
//         |> then_(Fetch.Response.json)
//         |> then_({res => {
//             Js.log(res);
//             res
//             |> Decode.files 
//             |> ( fs => {  /*Js.log(fs);*/    Some(fs)   }    |> resolve)
//             }})
//         |> catch({_err => { Js.log(_err);     resolve(None); } })
//     );
// };

// let doFetchMeme = (m) => {
//     Js.log("Fetching a meme from the backend database... (doFetchMeme)");
//     Js.Promise.(
//         Fetch.fetch(Config.url_be_root++"/getmeme/"++m)
//         |> then_(Fetch.Response.json)
//         |> then_({res => {
//             Js.log(res);
//             res
//             |> Decode.files 
//             |> ( fs => {  /*Js.log(fs);*/    Some(fs)   }    |> resolve)
//             }})
//         |> catch({_err => { /*Js.log(_err);*/     resolve(None); } })
//     );
// };

// [@react.component]
// let make = () => {

//     // .state 

//     let (x, setX) = React.useState( () => "initial value of x" );
//     let (current_meme, setCurrentMeme) = React.useState( () => "name1" );
//     let (meme_to_fetch, setMemeToFetch) = React.useState( () => "initial value of meme_to_fetch" );
//     let (fetched_meme, setFetchedMeme) = React.useState( () => [] );

//     let (x2, setX2) = React.useState( () => "{\"query\":\"{allPosts {edges {node {id } }}}\"}" );
//     let (x3, setX3) = React.useState( () => "initial value of x3" );
//     let (y, setY) = React.useState( () => "initial y" );
//     let (z, setZ) = React.useState( () => [] );
//     let (z2, setZ2) = React.useState( () => "");
//     let (z3, setZ3) = React.useState( () => "");

//     // .effect

//     React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
//         () => { 
//             Js.log("Fired! - useEffect1(x) with x == [" ++ x ++ "]")
//             Js.Promise.(
//                 doFetchData()
//                 |> then_( result => {
//                             switch (result) {
//                                 | Some(data) => {
//                                     //Js.log(data);
//                                     setY(_ => "some files have been fetched!");
//                                     setZ(_ => data);
//                                     resolve();
//                                     }
//                                 | None => {
//                                     Js.log("OBSOLETE? NONE! no data fetched");
//                                     setY(_ => "no data fetched");
//                                     resolve();
//                                     }
//                             }
//                         })
//                 |> ignore                            
//             )
//             None;
//             }, 
//         [|x|],
//     );
//     React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
//         () => { 
//             Js.log("Fired! - useEffect1(meme_to_fetch) with current_meme == [" ++ current_meme ++ "]")
//             Js.Promise.(
//                 doFetchMeme(current_meme)
//                 |> then_( result => {
//                             switch (result) {
//                                 | Some(data) => {
//                                     Js.log(data);
//                                     setFetchedMeme(_ => data);
//                                     resolve();
//                                     }
//                                 | None => {
//                                     Js.log("THIS one - NONE! no data fetched");
//                                     setY(_ => "no data fetched");
//                                     resolve();
//                                     }
//                             }
//                         })
//                 |> ignore                            
//             )
//             None;
//             }, 
//         [|meme_to_fetch|],
//     );

//     React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
//         () => { 
//          switch (x3) {
//          | "" => {Js.log("x3 hasn't changed"); None}
//          | x3 => {
//             Js.log("Fired! useEffect1(x3) with x3 == [" ++ x3 ++ "] ")
//             setZ3(_=>x3)
//             None;
//          }}
//         },          
//         [|x3|],
//     );
     
//     // .reducer

//     let (_ss, _dispatch) = 
//         React.useReducer( 
//             (state, action) => switch (action) { 
//                 | UpdateInput(newInput) => {...state, input: newInput}
//                 | FetchData => { Js.log("fetchdata: STATE=2"); setX(_ => "test"); {...state, isLoading: true }}
//                 | FetchDataX(m) => { Js.log("fetchdata: STATE=3, m=="++m); setMemeToFetch(_ => m); {...state, isLoading: true }}
//                 },
//             {input: "Initial input", isLoading: false}
//         );

//     // .render
//     {
//     <div>
//       <RenderItemList items=z />
//     </div>
//     }
// };

