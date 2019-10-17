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
    url: string
};




let doFetchMeme = (m) => {
    Js.log("Fetching a meme from the backend database... (doFetchMeme)");
    Js.Promise.(
        Fetch.fetch("http://localhost:3003/getmeme/"++m)
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

 
    // .effect

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
                                    Js.log("NONE! no data fetched");
                                    //setY(_ => "no data fetched");
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

    let (ss, dispatch) = 
        React.useReducer( 
            (state, action) => switch (action) { 
                | FetchDataX(m) => { Js.log("STATE=3, m=="++m); setMemeToFetch(_ => m); {...state, isLoading: true }}
                },
            {input: "Initial input", isLoading: false}
        );
    {

    // .render

    <div>

        {str("SEARCH FOR A MEME:")} <br />
        <br />
                <label htmlFor="search"> {str("Fetch a meme: ")} </label>                
                <input 
                    style=(ReactDOMRe.Style.make(~width="600px", () ))  
                    id="MemeSearch_Input_id" 
                    name="MemeSearch_Input_name" 
                    value={current_meme} 
                    onKeyPress={ev=>{
                        let k = ReactEvent.Keyboard.key(ev)
                        if (k == "Enter") {
                            dispatch(FetchDataX(current_meme))
                        }
                        }}
                    onChange={ev => {
                        let v = ReactEvent.Form.target(ev)##value
                        setCurrentMeme(v)
                    }}
                />
                <button id="MemeSearchButton" onClick={_ev => {
                    dispatch(FetchDataX(current_meme)); }}> {str("Dispatch!")}
                </button>
        <br />
        <br />

        <div className="items-list-files">
        (
            List.map(
                (zi : Decode.f) => {
                    let i : RenderMeme.memeType = { url: "http://localhost:3003/uploads/" ++ zi.fn, id: zi.id, name: zi.name};
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

