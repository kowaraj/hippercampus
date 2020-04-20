let str = ReasonReact.string;
type state = {
    input: string, 
    isLoading: bool
};
type action = 
    | FetchData

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
let make = (~cb) => {
    let (x, setX) = React.useState( () => "initial value of x" );
    let (z, setZ) = React.useState( () => [] );

    React.useEffect1( 
        () => { 
            Js.log("Fired! - useEffect1(x) with x == [" ++ x ++ "]")
            Js.Promise.(
                doFetchData()
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    setZ(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("OBSOLETE? NONE! no data fetched");
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
   
    let (_ss, _dispatch) = 
        React.useReducer( 
            (state, action) => switch (action) { 
                | FetchData => { Js.log("fetchdata: STATE=2"); setX(_ => "test"); {...state, isLoading: true }}
                },
            {input: "Initial input", isLoading: false}
        );

    // .render

    let local_f : string => unit = item_name => {
        //let meme_index = Random.int(10)
        //let meme_name = List.nth(z, meme_index)
        //Js.log("random meme name = "++ meme_name.name)
        Js.log(item_name)
        // cb(meme_name.name)
        cb(item_name)
    };

    {
    <div>
//        <button style=StyleRenderItem3.button onClick={_ => local_f}> {RR.str("clickme")}</button>
      <RenderItemList3 items=z list_cb=local_f/>
    </div>
    }
};

