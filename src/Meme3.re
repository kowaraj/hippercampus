[@react.component]
let make = () => {
    //Db: show DB content and select a meme
    let (meme_to_show, setMemeToShow) = React.useState( () => TT.default_meme )

    //RenderMemeWrapper: showing the selected meme
    let cb_selected_meme = m => { setMemeToShow(_ => m); Js.log(m)  };

    Js.log(RR.v);
    Js.log("react.component: Meme3.re");
    <div id="div-render-meme">
        <div className="card">
        </div>
        <div>
            <button className=S.memes_button onClick={_ => ReasonReactRouter.push("/login")}> {RR.str("M")} </button> 
        </div>


        {
            switch (Config.is_logged_in()) {
                | true => { 
                    <div>
                    <RenderMemeList cb_fetch_selected=cb_selected_meme />
                    <RenderMemeWrapper4 fetched_meme=meme_to_show />
                    </div>
                    }
                | false => {  <p > {RR.str("PLEASE, LOG IN...")} </p> }
            }
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

