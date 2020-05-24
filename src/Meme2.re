let doFetchMeme = (m) => {
    Js.Promise.(
        Fetch.fetch(Config.url_be_root ++ "/getmeme/" ++ m)
        |> then_(Fetch.Response.json)
        |> then_({res => { res |> Decode.files 
                               |> ( fs => Some(fs) |> resolve)    }})
        |> catch({_err => {  resolve(None); } })
    );
    };

[@react.component]
let make = () => {
    let (meme_to_fetch, setMemeToFetch) = React.useState( () => "initial value of meme_to_fetch" );
    let (fetched_memes, setFetchedMemes) = React.useState( () => [] );

    let filter_fetched = (memes, tags) => {
        Js.log(memes);
        Js.log(tags);
        memes
    }

    let do_fetch = (memename) => {
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
                        resolve();}
                }}) |> ignore) 
        None;
    };
    
    React.useEffect1( 
        () => { do_fetch(meme_to_fetch); }, 
        [|meme_to_fetch|],
    );

    let cb_selected_meme = s => { setMemeToFetch(_ => s)  };

    <div id="div-render-meme" style=StyleMeme.component>
        <FetchData4 cb=cb_selected_meme/>            
        <RenderMemeWrapper fetched_memes=fetched_memes />
    </div>
};

