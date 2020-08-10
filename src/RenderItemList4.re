[@react.component]
let make = (~items) => {

    <div>
        <div style=StyleRenderItem3.list>
        (
            List.map(
                (zi : TT.fs_meme_t) => {
                    let i : TT.item = { 
                        url: Config.url_be_root++"/uploads/" ++ zi.fn, 
                        id: zi.id, 
                        name: zi.name
                        };
                    <RenderItem4 key=zi.id item=i />
                },
                items)
            |> Array.of_list
            |> React.array
        )
        </div>
    </div>
};