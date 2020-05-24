[@react.component]
let make = (~tags_in, ~cb_select, ~cb_deselect) => {
  <div id="ant-containder-id" style=StyleMeme.antd_container >
    <Ant.Select 
      style=StyleMeme.antd 
      mode="multiple" 
      onSelect={ s => cb_select(s)}
      onDeselect={ s => cb_deselect(s)}>
    {
      tags_in
        |> List.map( tag => <Ant.Select.Option  style=StyleMeme.antd_option key=tag> {ReasonReact.string(tag)} </Ant.Select.Option> ) 
        |> Array.of_list 
    }
    </Ant.Select>
  </div> ;
};