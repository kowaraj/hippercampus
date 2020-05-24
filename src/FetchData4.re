let doFetchMemes = () => {
    Js.log("doFetchMemes:")

    Js.Promise.(
        Fetch.fetch(Config.url_be_root++"/getmemes")
        |> then_(Fetch.Response.json)
        |> then_({res => {
            res
            |> Decode.files 
            |> ( fs => {  Some(fs)   }    |> resolve)
            }})
        |> catch({_err => { Js.log(_err);     resolve(None); } })
    );
};

[@react.component]
let make = (~cb) => {
    let (fetchedMemes, setFetchedMemes) = React.useState( () => [] );

    let (all_tags, setAllTags) = React.useState( () => ["bash", "ssh", "linux"] );
    let (sel_tags, setSelTags) = React.useState( () => [] );

    let filter_data_by_tags = (memes, sel_tags) => {
        switch (List.length(sel_tags)) {
        | 0 => memes
        | _ => 
            List.filter( 
                ( meme : Decode.meme_t) => List.exists( 
                                                meme_tag => List.for_all( 
                                                                    sel_tag => sel_tag == meme_tag, 
                                                                    sel_tags),
                                                meme.tags),
                memes)
        }
    }

    React.useEffect1( () => { 
        Js.Promise.(
            doFetchMemes()
            |> then_( result => {
                switch (result) {
                    | Some(data) => {
                        setFetchedMemes(_ => filter_data_by_tags(data, sel_tags));
                        resolve(); }
                    | None => {
                        Js.log("FetchData3.re: NONE! no data fetched");
                        resolve();}
            }}) |> ignore ) None;
        }, 
        [|sel_tags|],
    );

    let local_f : string => unit = item_name => {  cb(item_name) };
    let cb_select_tags = s => { setSelTags(old_tags => List.append(old_tags, [s]))   };
    let cb_deselect_tags = s => { setSelTags(old_tags => List.filter(dt => dt != s, old_tags)) };

    {
    <div>
      <RenderItemList3 items=fetchedMemes list_cb=local_f/>
      <AntTest tags_in=all_tags cb_select=cb_select_tags cb_deselect=cb_deselect_tags />
    </div>
    }
};

