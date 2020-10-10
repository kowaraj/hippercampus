type item = {
    url: string, 
    id: int, 
    name: string
};

[@react.component]
let make = (~item, ~cb) => {
    <p onClick={e=>cb(e, item.name)} style=StyleRenderItem3.item> {RR.str(item.name)} </p>
};