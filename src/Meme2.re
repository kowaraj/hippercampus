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
                                    resolve();
                                    }}})
                |> ignore)                            
            None;
    };
    
    React.useEffect1( 
        () => { do_fetch(meme_to_fetch); }, 
        [|meme_to_fetch|],
    );

    let f_test_cb = s => { setMemeToFetch(_ => s)  };

    <div id="div-render-meme" style=StyleMeme.component>
        <FetchData3 cb=f_test_cb/>            
        <AntTest />
        <RenderMemeWrapper fetched_memes=fetched_memes />
    </div>
};

