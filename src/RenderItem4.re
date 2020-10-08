[@react.component]
let make = (~item: TT.item, ~cb_on_selection) => {
//    <p style=StyleRenderItem3.item> {RR.str(item.name)} </p>
    <p onClick={e=>cb_on_selection(e, item.name)} style=StyleRenderItem3.item> {RR.str(item.name)} </p>
};