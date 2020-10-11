[@react.component]
let make = (~tags_in, ~cb_select, ~cb_deselect) => {
<div className=S.ant_div>
  <div id="ant-containder-id"  className=S.ant_container>
    <Ant.Select 
      className=S.ant_sel
      mode="multiple"
      onSelect={ s => cb_select(s)}
      onDeselect={ s => cb_deselect(s)}>
    {
      tags_in
        |> List.map( tag => <Ant.Select.Option className=S.ant_option key=tag> {ReasonReact.string(tag)} </Ant.Select.Option> ) 
        |> Array.of_list 
    }
    </Ant.Select>
  </div>
</div> ;
};