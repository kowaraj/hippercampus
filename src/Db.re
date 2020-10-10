// ReasonML wrapper for the Firestore database interface in Firestore.js

[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: ( (string, TT.fs_meme_t, string) => unit) => unit = "memes_onSnapshot";

// [@bs.module "./Firestore.js"]
// external fs_add_meme: ( unit => unit ) =  "add_meme";

// [@bs.val] external document: 'a = "document";
// document##addEventListener("mouseup", _event => {
//     let loc = document##location;
//     //Js.log(loc)
//     //let ret = set_location_href(loc, "rescript-lang.org")
//     let href = document##location##href;
//     let ret = "rescript-lang.org"
//     Js.log("clicked!");
//     fs_add_meme()
// });

[@bs.get] external getId: TT.fs_meme_t => string = "id";
[@bs.get] external getName: TT.fs_meme_t => string = "name";
[@bs.get] external getText: TT.fs_meme_t => string = "text";
[@bs.get] [@bs.return nullable] external getFn: TT.fs_meme_t => option(string) = "fn";
[@bs.get] [@bs.return nullable] external getTags: TT.fs_meme_t => option(string) = "tags";


[@react.component]
let make = (~cb_fetch_selected) => {

    let (memes, setMemes) = React.useState( () => [] );
    let (memesToShow, setMemesToShow) = React.useState( () => [] );

    let meme_added = (m_id, m) => {
        let tags = getTags(m) // option(string), bs.nullable => might be undefined!
        let tags_array = {
            switch tags {
                | Some(s) => Js.String2.split(s, ",");
                | None => Js.Array.from(Js.String.castToArrayLike("no tags found"))
            }
        }
        let tags_list = Array.to_list(tags_array)
        let m_fn = getFn(m);
        let fn_string = {
            switch m_fn {
                | Some(fn) => fn;
                | None => "no files attached"
            }
        }
        let mm : TT.fs_meme_t = {id: m_id, name: getName(m), text: getText(m), fn: fn_string, tags: tags_list}
        setMemes( ms => List.append(ms, [ mm ] ) )
    }

    let meme_removed = (m_id) => {
        setMemes( ms => List.filter(m => getId(m) == m_id, ms) )
    }

    // Callback for realtime db update 
    let db_callback = (m_id, m:TT.fs_meme_t, change_type) => {
        switch change_type {
            | "added" => meme_added(m_id, m)
            | "removed" => meme_removed(m_id)
            | _ => ()
        }
    };

    // Register a callback
    React.useEffect0( () => { 
        fs_memes_onSnapshot(db_callback)
        None;
    });

    // Get the meme from a selected meme.id
    let selected_meme : string => unit = item_id => { 
        let m = List.find( (mi : TT.fs_meme_t) => mi.id == item_id, memes )
        cb_fetch_selected(m) 
    };

    //AntTest: working with tags
    let (all_tags, setAllTags) = React.useState( () => ["bash", "ssh", "linux"] );
    let (sel_tags, setSelTags) = React.useState( () => [] );
    let cb_select_tags = s => { setSelTags(old_tags => List.append(old_tags, [s]))   };
    let cb_deselect_tags = s => { setSelTags(old_tags => List.filter(dt => dt != s, old_tags)) };

    React.useEffect2( () => {
        setMemesToShow(_ => Utils.filter_data_by_tags(memes, sel_tags));
        setAllTags(_ => Utils.extract_all_tags(memes))
        None
        },
        (memes, sel_tags),
    );

    // Render the list of memes
    <div> 
        <RenderItemList4 items=memesToShow cb_selection=selected_meme/>
        <AntTest tags_in=all_tags cb_select=cb_select_tags cb_deselect=cb_deselect_tags />
    </div>
 
};