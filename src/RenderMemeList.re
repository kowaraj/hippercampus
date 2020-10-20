

let memes_ref = ref([] : list(TT.fs_meme_t) );

[@react.component]
let make = (~cb_fetch_selected) => {

    //Js.log("react.component: RenderMemeList.re");

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

        //update the ref
        memes_ref := List.append(memes_ref^, [ m ] )
    };

    let db_ch_removed = m_id => {
        setMemes( ms => List.filter( (m:TT.fs_meme_t) => m.id != m_id, ms) )

        //TODO: update the ref
    };

    let db_ch_updated = (m_upd : TT.fs_meme_t) => {
        setMemes( ms => {
            let ms_1 = List.filter( (m:TT.fs_meme_t) => m.id != m_upd.id, ms)
            let ms_2 = List.append(ms_1, [ m_upd ] )
            ms_2
        })

        //TODO: update the ref
    };

    React.useEffect2( () => {
        setMemesToShow(_ => Utils.filter_data_by_tags(memes, sel_tags));
        setAllTags(_ => Utils.extract_all_tags(memes))
        None
        },
        (memes, sel_tags),
    );

    // Render the list of memes
    <div className=S.renderMemeList_container> 
        <Db cb_meme_added=db_ch_added cb_meme_updated=db_ch_updated cb_meme_removed=db_ch_removed/>
        <RenderItemList4 items=memesToShow cb_selection=selected_meme/>
        <TagsSelector tags_in=all_tags cb_select=cb_select_tags cb_deselect=cb_deselect_tags />
    </div>             

    // // Render the list of memes
    // <div> 
    //     <button className=S.db_dump_button onClick={ _ => dumpDbIntoFile(Utils.mlist2str(memes)) }> {RR.str("DUMP")} </button> 
    //     <Db cb_meme_added=db_ch_added cb_meme_updated=db_ch_updated cb_meme_removed=db_ch_removed/>
    //     <RenderItemList4 items=memesToShow cb_selection=selected_meme/>
    //     <TagsSelector tags_in=all_tags cb_select=cb_select_tags cb_deselect=cb_deselect_tags />
    // </div>
};