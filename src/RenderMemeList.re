let dumpDbIntoFile = [%raw {|
function download(text) {
  var pom = document.createElement('a');
  pom.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
  pom.setAttribute('download', "dump.json");
  pom.style.display = 'none';
  document.body.appendChild(pom);
  pom.click();
  document.body.removeChild(pom);
}
|}];


[@react.component]
let make = (~cb_fetch_selected) => {

    //AntTest: working with tags
    let (all_tags, setAllTags) = React.useState( () => ["bash", "ssh", "linux"] );
    let (sel_tags, setSelTags) = React.useState( () => [] );
    let cb_select_tags = s => { setSelTags(old_tags => List.append(old_tags, [s]))   };
    let cb_deselect_tags = s => { setSelTags(old_tags => List.filter(dt => dt != s, old_tags)) };

    let (memesToShow, setMemesToShow) = React.useState( () => [] );
    let (memes, setMemes) = React.useState( () => [] );

    // Get the meme from a selected meme.id
    let selected_meme : string => unit = item_id => { 
        let m = List.find( (mi : TT.fs_meme_t) => mi.id == item_id, memesToShow )
        cb_fetch_selected(m) 
    };

    let db_ch_added = m => {
        setMemes( ms => List.append(ms, [ m ] ) ) 
    };

    let db_ch_removed = m_id => {
        setMemes( ms => List.filter( (m:TT.fs_meme_t) => m.id != m_id, ms) )
    };

    let db_ch_updated = (m_upd : TT.fs_meme_t) => {
        setMemes( ms => {
            let ms_1 = List.filter( (m:TT.fs_meme_t) => m.id != m_upd.id, ms)
            let ms_2 = List.append(ms_1, [ m_upd ] )
            ms_2
        })
    };

    React.useEffect2( () => {
        setMemesToShow(_ => Utils.filter_data_by_tags(memes, sel_tags));
        setAllTags(_ => Utils.extract_all_tags(memes))
        None
        },
        (memes, sel_tags),
    );

    {
        switch (Config.is_logged_in()) {
            | true => { 
                // Render the list of memes
                <div> 
                    <button className=S.db_dump_button onClick={ _ => dumpDbIntoFile(Utils.mlist2str(memes)) }> {RR.str("DUMP")} </button> 
                    <Db cb_meme_added=db_ch_added cb_meme_updated=db_ch_updated cb_meme_removed=db_ch_removed/>
                    <RenderItemList4 items=memesToShow cb_selection=selected_meme/>
                    <TagsSelector tags_in=all_tags cb_select=cb_select_tags cb_deselect=cb_deselect_tags />
                </div>             
                }
            | false => { 
                <p > {RR.str("OUT")} </p> 
                }
        }
    };

    // // Render the list of memes
    // <div> 
    //     <button className=S.db_dump_button onClick={ _ => dumpDbIntoFile(Utils.mlist2str(memes)) }> {RR.str("DUMP")} </button> 
    //     <Db cb_meme_added=db_ch_added cb_meme_updated=db_ch_updated cb_meme_removed=db_ch_removed/>
    //     <RenderItemList4 items=memesToShow cb_selection=selected_meme/>
    //     <TagsSelector tags_in=all_tags cb_select=cb_select_tags cb_deselect=cb_deselect_tags />
    // </div>
};