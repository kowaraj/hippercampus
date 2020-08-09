let doFetchMemes = () => {
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

let fake_memes : list(Decode.meme_t) = [ 
    {
    id: 0,
    name: "meme0name", 
    text: "meme0text", 
    fn: "meme0fn", 
    tags: ["meme0tag1 meme0tag2"]
    },
    {
    id: 1,
    name: "meme1name", 
    text: "meme1text", 
    fn: "meme1fn", 
    tags: ["meme1tag1 meme1tag2"]
    }
    ];

[@react.component]
let make = (~cb) => {
    let (fetchedMemes, setFetchedMemes) = React.useState( () => [] );

    let (all_tags, setAllTags) = React.useState( () => ["bash", "ssh", "linux"] );
    let (sel_tags, setSelTags) = React.useState( () => [] );

    // Take: List of memes, List of selected tags
    // Return: List of memes whose tags contain all of the selected tags
    let filter_data_by_tags = (memes, sel_tags) => {
        switch (List.length(sel_tags)) {
        | 0 => memes
        | _ => 
            List.filter( 
                ( meme : Decode.meme_t) => List.exists( 

                                                meme_tag => List.for_all( 
                                                                    sel_tag => sel_tag == String.trim(meme_tag), 
                                                                    sel_tags),
                                                meme.tags),
                memes)
        }
    }

    // Take: List of memes
    // Return: List of all the unique tags 
    let extract_all_tags = memes => {
        let tags = List.fold_left( 
                        (extracted_tags, (meme: Decode.meme_t)) => {
                                                    List.append(extracted_tags, meme.tags)
                        }, [], memes)
        //Re::String::trim - The characters regarded as whitespace are: ' ', '\012', '\n', '\r', and '\t'. If 
        let tags_peeled = List.map( tag => String.trim(tag), tags)
        let tags_u = List.sort_uniq( (t1,t2) => compare(t1,t2), tags_peeled)
        //Js.log(tags_u |> Array.of_list)
        tags_u
    }

    React.useEffect1( () => { 
        Js.Promise.(
            doFetchMemes()
            |> then_( result => {
                switch (result) {
                    | Some(data) => {
//                        setFetchedMemes(_ => filter_data_by_tags(data, sel_tags));
                        setFetchedMemes(_ => filter_data_by_tags(fake_memes, sel_tags));
                        setAllTags(_ => extract_all_tags(data))
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
      //<Db />
    </div>
    }
};

