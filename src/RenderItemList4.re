[@react.component]
let make = (~items, ~cb_selection) => {

    let list_item_selected = (_e, item_name) => {
        cb_selection(item_name)
    };

    <div className="container">
    <div className="row box2">
        (
            List.map(
                (zi : TT.fs_meme_t) => {
                    let i : TT.item = { 
                        url: Config.url_be_root_uploads ++ zi.fn, 
                        id: zi.id, 
                        name: zi.name
                        };
                    <RenderItem4 cb_on_selection=list_item_selected key=zi.id item=i />
                },
                items)
            |> Array.of_list
            |> React.array
        )
    </div>
    </div>
};