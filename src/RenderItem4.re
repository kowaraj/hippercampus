[@react.component]
let make = (~item: TT.item, ~cb_on_selection) => {
//    <p onClick={e=>cb_on_selection(e, item.id)} style=StyleRenderItem3.item> {RR.str(item.name)} </p>

    // Js.log("MEME3.re mark = " ++ Config.mark^);
    // {
    //     switch (Config.mark^) {
    //     | "IN" => {     <p > {RR.str("IN")} </p>}
    //     | "OUT" => {     <p > {RR.str("OUT")} </p>}
    //     | _ => {     <p > {RR.str("INIT")} </p>}
    //     }

    // }

    <p className=S.meme_p onClick={e=>cb_on_selection(e, item.id)} > {RR.str(item.name)} </p>
};