//[%bs.raw {|require('./meme.css')|}];

[@react.component]
let make = (~fetched_memes : list(Decode.meme_t)) => {

        // render the list of fetched memes
        <div id="div-render-rendermeme" style=StyleMeme.render_div className="items-list-files">
        (
            List.map(
                (zi : Decode.meme_t) => {
                    let i : Decode.meme_t = {
                        fn: Config.url_be_root++"/uploads/" ++ zi.fn, 
                        id: zi.id, 
                        text: zi.text,
                        name: zi.name, 
                        tags: zi.tags
                        };
                    <RenderMeme key=string_of_int(zi.id) m=i />
                },
                fetched_memes)
            |> Array.of_list
            |> React.array
        )
        </div>
};



