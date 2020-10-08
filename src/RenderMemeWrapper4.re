//[%bs.raw {|require('./meme.css')|}];

[@react.component]
let make = (~fetched_meme : TT.fs_meme_t) => {

        // render the list of fetched memes
        <div id="div-render-rendermeme" style=StyleMeme.render_div className="items-list-files">
            <RenderMeme4 key=fetched_meme.id m=fetched_meme />
        </div>
};



