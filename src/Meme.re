let str = ReasonReact.string;
type state = {
    input: string, 
    isLoading: bool
};
type action = 
    | FetchDataX(string);

type memeType = {
    id: int, 
    name: string, 
    text: string, 
    url: string
};

let doFetchMeme = (m) => {
    //Js.log("fetch: a meme from the backend");
    Js.Promise.(
        Fetch.fetch(Config.url_be_root ++ "/getmeme/" ++ m)
        |> then_(Fetch.Response.json)
        |> then_({res => {
            //Js.log(res);
            res
            |> Decode.files 
            |> ( fs => {  /*Js.log(fs);*/    Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { /*Js.log(_err);*/     resolve(None); } })
    );
};

let doFetchMeme1 = () => {
    //Js.log("fetch: a SIGNLE meme from the backend");
    Js.Promise.(
        Fetch.fetch(Config.url_be_root ++ "/getmeme/" ++ "AD: DNS + KERBEROS")
        |> then_(Fetch.Response.json)
        |> then_({res => {
            //Js.log(res);
            res
            |> Decode.meme 
            |> ( fs => {  /*Js.log(fs);*/    Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { /*Js.log(_err);*/     resolve(None); } })
    );
};

let doFetchMemeRandom = () => {
    //Js.log("fetch: a SINGLE meme from the backend");
    Js.Promise.(
        Fetch.fetch(Config.url_be_root ++ "/getmemerandom/")
        |> then_(Fetch.Response.json)
        |> then_({res => {
            //Js.log(res);
            res
            |> Decode.meme 
            |> ( fs => {  /*Js.log(fs);*/    Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { /*Js.log(_err);*/     resolve(None); } })
    );
};

[@react.component]
let make = () => {

    // .state 

    let (_x, _setX) = React.useState( () => "initial value of x" );
    let (current_meme, setCurrentMeme) = React.useState( () => "" ); // name of the meme to fetch
    let (meme_to_fetch, setMemeToFetch) = React.useState( () => "initial value of meme_to_fetch" );
    let (fetched_memes, setFetchedMemes) = React.useState( () => [] );

    // .effect

    let _useEffectFunction = () => {
            //Js.log("useEffect: on meme_to_fetch [" ++ current_meme ++ "]")
            Js.Promise.(
                doFetchMeme(current_meme)
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    //Js.log(data);
                                    setFetchedMemes(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("NONE! no data fetched");
                                    resolve();
                                    }
                            }
                        })
                |> ignore                            
            )
            None;
    };

    let _useEffectFunction1 = () => {
            //Js.log("useEffect: on meme_to_fetch [" ++ current_meme ++ "]")
            Js.Promise.(
                doFetchMeme1()
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    //Js.log(data);
                                    setFetchedMemes(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("NONE! no data fetched");
                                    resolve();
                                    }
                            }
                        })
                |> ignore                            
            )
            None;
    };

    // Triggered by:
    // - useEffect on meme_to_fetch
    // - button click
    let useEffectFunction2 = (m) => {
        switch (m) {
        | "" => {
            Js.Promise.(
                doFetchMemeRandom()
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    setFetchedMemes(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("NONE! no data fetched");
                                    resolve();
                                    }}})
                |> ignore)                            
            None;
        }
        | memename => {
            Js.Promise.(
                doFetchMeme(memename)
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    setFetchedMemes(_ => data);
                                    resolve();
                                    }
                                | None => {
                                    Js.log("NONE! no data fetched");
                                    resolve();
                                    }}})
                |> ignore)                            
            None;

        }
        }
    };
    
    React.useEffect1( 
        () => { 
            useEffectFunction2(meme_to_fetch);
            }, 
        [|meme_to_fetch|],
    );

    // .reducer

    let (_ss, dispatch) = 
        React.useReducer( 
            (state, action) => switch (action) { 
                | FetchDataX(m) => { Js.log("IS IT EVER CLICKED????"++m); setMemeToFetch(_ => m); {...state, isLoading: true }}
                },
            {input: "Initial input", isLoading: false}
        );
    {

    // .render

    let f_dispatch = () => {
        //TODO: find a way to distiguish b/w mouse and keyboard events
        dispatch(FetchDataX(current_meme))
    };

    let f_test_cb = s => {
        //Js.log("callback value = " ++ s)
        setMemeToFetch(_ => s)
    };
    <div id="div-render-meme" style=StyleMeme.component>
        <div>
            <FetchData3 cb=f_test_cb/>            
        </div>     
        // <button style=StyleMeme.button_fetch id="MemeSearchButton2" onClick={
        //     _ev => {let _x = useEffectFunction2(""); ()}}> {str("Fetch Random")
        //     } </button> <br />
        <AntTest />
        // render the list of fetched memes
        <div id="div-render-rendermeme" style=StyleMeme.render_div className="items-list-files">
        (
            List.map(
                (zi : Decode.meme_t) => {
                    let i : Decode.meme_t = {
                        fn: Config.url_be_root++"/uploads/" ++ zi.fn, 
                        id: zi.id, 
                        text: zi.text,
                        name: zi.name, 
                        tags: zi.tags
                        };
                    <RenderMeme key=string_of_int(zi.id) m=i />
                },
                fetched_memes)
            |> Array.of_list
            |> React.array
        )
        </div>

        <label htmlFor="search"> {str("Fetch a meme: ")} </label>    <br />
        <input 
            style=Style.h_meme_fetch
            id="MemeSearch_Input_id" 
            name="MemeSearch_Input_name" 
            value={current_meme} 
            onKeyPress={ev=>{
                let k = ReactEvent.Keyboard.key(ev)
                if (k == "Enter") { f_dispatch() }
                }}
            onChange={ev => {
                let v = ReactEvent.Form.target(ev)##value
                setCurrentMeme(v)
            }}
        />
        <br />
        <button id="MemeSearchButton" onClick={_ev => f_dispatch()}> {str("Fetch!")} </button> <br />

 
    </div>
    }
};

