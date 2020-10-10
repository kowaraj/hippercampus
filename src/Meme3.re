[@react.component]
let make = () => {

    //Db: show DB content and select a meme
    let (meme_to_show, setMemeToShow) = React.useState( () => TT.default_meme )

    //RenderMemeWrapper: showing the selected meme
    let cb_selected_meme = m => { setMemeToShow(_ => m); Js.log(m)  };

//    <div id="div-render-meme" style=StyleMeme.component>
    <div  className="row" id="div-render-meme">
        <Db cb_fetch_selected=cb_selected_meme />
        <RenderMemeWrapper4 fetched_meme=meme_to_show />
    </div>
};

