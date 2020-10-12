// ReasonML wrapper for the Firestore database interface in Firestore.js

[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: ( (string, TT.fs_meme_t, string) => unit) => unit = "memes_onSnapshot";

[@bs.get] external getId: TT.fs_meme_t => string = "id";
[@bs.get] external getName: TT.fs_meme_t => string = "name";
[@bs.get] external getText: TT.fs_meme_t => string = "text";
[@bs.get] [@bs.return nullable] external getFn: TT.fs_meme_t => option(string) = "fn";
[@bs.get] [@bs.return nullable] external getTags: TT.fs_meme_t => option(string) = "tags";

[@react.component]
let make = (~cb_meme_added, ~cb_meme_updated, ~cb_meme_removed) => {

    let update_a_meme = (m_id, m)=> {
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
        let mm : TT.fs_meme_t = {id: m_id, name: getName(m), text: getText(m), fn: fn_string, tags: tags_list};
        mm
    }

    let meme_added = (m_id, m) => {
        // let tags = getTags(m) // option(string), bs.nullable => might be undefined!
        // let tags_array = {
        //     switch tags {
        //         | Some(s) => Js.String2.split(s, ",");
        //         | None => Js.Array.from(Js.String.castToArrayLike("no tags found"))
        //     }
        // }
        // let tags_list = Array.to_list(tags_array)
        // let m_fn = getFn(m);
        // let fn_string = {
        //     switch m_fn {
        //         | Some(fn) => fn;
        //         | None => "no files attached"
        //     }
        // }
        // let mm : TT.fs_meme_t = {id: m_id, name: getName(m), text: getText(m), fn: fn_string, tags: tags_list};
        let mm = update_a_meme(m_id, m)
        cb_meme_added(mm);
        ()
    }

    let meme_updated = (m_id, m) => {
        let mm = update_a_meme(m_id, m)
        cb_meme_updated(mm);
        ()
    }

    let meme_removed = (m_id) => {
        cb_meme_removed(m_id);
        ()
    }

    // Callback for realtime db update 
    let db_callback = (m_id, m:TT.fs_meme_t, change_type) => {
        switch change_type {
            | "added" => meme_added(m_id, m)
            | "removed" => meme_removed(m_id)
            | "modified" => meme_updated(m_id, m)
            | _ => ()
        }
    };

    // Register a callback for Firestore DB (pure JS)
    React.useEffect0( () => { 
        fs_memes_onSnapshot(db_callback)
        None;
    });

    // Render the list of memes
    <div>

    </div>
 
};