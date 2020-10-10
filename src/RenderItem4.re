[@react.component]
let make = (~item: TT.item, ~cb_on_selection) => {
//    <p onClick={e=>cb_on_selection(e, item.id)} style=StyleRenderItem3.item> {RR.str(item.name)} </p>
    <p onClick={e=>cb_on_selection(e, item.id)} > {RR.str(item.name)} </p>
};