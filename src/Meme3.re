
let fake_meme : Decode.meme_t  =
    {
    id: 0,
    name: "meme0name", 
    text: "meme0text", 
    fn: "meme0fn", 
    tags: ["meme0tag1 meme0tag2"]
    }
    // {
    // id: 1,
    // name: "meme1name", 
    // text: "meme1text", 
    // fn: "meme1fn", 
    // tags: ["meme1tag1 meme1tag2"]
    // }
    // ];
    
let doFetchMeme = (m) => {
    Js.Promise.(
        Fetch.fetch(Config.url_be_root ++ "/getmeme/" ++ m)
        |> then_(Fetch.Response.json)
        |> then_({res => { res |> Decode.files 
                               |> ( fs => Some([fake_meme]) |> resolve)    }})
        |> catch({_err => {  resolve(None); } })
    );
    };

[@react.component]
let make = () => {
    let (meme_to_fetch, setMemeToFetch) = React.useState( () => "initial value of meme_to_fetch" );
    let (fetched_memes, setFetchedMemes) = React.useState( () => [] );

    // let filter_fetched = (memes, tags) => {
    //     //Js.log(memes);
    //     //Js.log(tags);
    //     memes
    // }

    // let do_fetch = (memename) => {
    //     Js.Promise.(
    //         doFetchMeme(memename)
    //         |> then_( result => {
    //             switch (result) {
    //                 | Some(data) => {
    //                     setFetchedMemes(_ => data);
    //                     resolve();
    //                     }
    //                 | None => {
    //                     Js.log("NONE! no data fetched");
    //                     resolve();}
    //             }}) |> ignore) 
    //     None;
    // };
    
    // React.useEffect1( 
    //     () => { do_fetch(meme_to_fetch); }, 
    //     [|meme_to_fetch|],
    // );

    let cb_selected_meme = s => { setMemeToFetch(_ => s)  };
    let cb_add_meme = m => { setFetchedMemes(memes => List.append(memes, [m]))   };

    <div id="div-render-meme" style=StyleMeme.component>
        <Db />

//        <FetchData5 cb=cb_selected_meme/>            
//        <RenderMemeWrapper fetched_memes=fetched_memes />
    </div>
};

