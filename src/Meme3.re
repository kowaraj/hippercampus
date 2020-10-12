[@react.component]
let make = () => {
    //Db: show DB content and select a meme
    let (meme_to_show, setMemeToShow) = React.useState( () => TT.default_meme )

    //RenderMemeWrapper: showing the selected meme
    let cb_selected_meme = m => { setMemeToShow(_ => m); Js.log(m)  };

    Js.log(RR.v);
    //Js.log("MEME3.re mark = " ++ Config.mark^);

    <div id="div-render-meme">
        <div>
            <button className=S.memes_button onClick={_ => ReasonReactRouter.push("/login")}> {RR.str("M")} </button> 
        </div>

{
        switch (Config.mark^) {
        | "IN" => {    
            <div>
            <RenderMemeList cb_fetch_selected=cb_selected_meme />
            <RenderMemeWrapper4 fetched_meme=meme_to_show />
            </div>
             }
        | _ => {     <p > {RR.str("PLEASE, LOG IN...")} </p>}
        };
}
    </div>




    // <div id="div-render-meme">
    //     <div>
    //         <button className=S.memes_button onClick={_ => ReasonReactRouter.push("/login")}> {RR.str("M")} </button> 
    //     </div>
    //     <RenderMemeList cb_fetch_selected=cb_selected_meme />
    //     <RenderMemeWrapper4 fetched_meme=meme_to_show />
    // </div>
};

