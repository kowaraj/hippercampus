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
    Js.log("fetch: a meme from the backend");
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

[@react.component]
let make = () => {

    // .state 

    let (x, setX) = React.useState( () => "initial value of x" );
    let (current_meme, setCurrentMeme) = React.useState( () => "" ); // name of the meme to fetch
    let (meme_to_fetch, setMemeToFetch) = React.useState( () => "initial value of meme_to_fetch" );
    let (fetched_meme, setFetchedMeme) = React.useState( () => [] );

    // .effect

    React.useEffect1( // TODO: (no need?) How NOT to trigger this "effect" at the componentMount time
        () => { 
            Js.log("useEffect: on meme_to_fetch [" ++ current_meme ++ "]")
            Js.Promise.(
                doFetchMeme(current_meme)
                |> then_( result => {
                            switch (result) {
                                | Some(data) => {
                                    //Js.log(data);
                                    setFetchedMeme(_ => data);
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
            }, 
        [|meme_to_fetch|],
    );

    // .reducer

    let (_ss, dispatch) = 
        React.useReducer( 
            (state, action) => switch (action) { 
                | FetchDataX(m) => { /*Js.log("meme:STATE=3, m=="++m);*/ setMemeToFetch(_ => m); {...state, isLoading: true }}
                },
            {input: "Initial input", isLoading: false}
        );
    {

    // .render

    let f_dispatch = () => {
        //TODO: find a way to distiguish b/w mouse and keyboard events
        dispatch(FetchDataX(current_meme))
    };

    <div style=Style.h_component>
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

        // render teh list of fetched memes
        <div className="items-list-files">
        (
            List.map(
                (zi : Decode.f) => {
                    let i : RenderMeme.memeType = { 
                        url: Config.url_be_root++"/uploads/" ++ zi.fn, 
                        id: zi.id, 
                        text: zi.text,
                        name: zi.name
                        };
                    <RenderMeme key=string_of_int(zi.id) m=i />
                },
                fetched_meme)
            |> Array.of_list
            |> React.array
        )
        </div>
 
    </div>
    }
};

