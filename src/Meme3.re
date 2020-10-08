[@react.component]
let make = () => {
    let (meme_to_fetch, setMemeToFetch) = React.useState( () => TT.default_meme )

    let cb_selected_meme = m => { setMemeToFetch(_ => m); Js.log("meme to fetch: "); Js.log(m.name);  };

    <div id="div-render-meme" style=StyleMeme.component>
        <Db cb_fetch_selected=cb_selected_meme />
        <RenderMemeWrapper4 fetched_meme=meme_to_fetch />

    </div>
};

