type item = {
    url: string, 
    id: int, 
    name: string
};

[@react.component]
let make = (~item) => {
    <p style=StyleRenderItem3.item> {RR.str(item.name)} </p>
};