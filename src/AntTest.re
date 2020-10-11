// let antd_container = {ReactDOMRe.Style.make(
//     ~border="2px solid #ff0000", 
//     ~width="100%",
//     ~lineHeight="4em",
//     () )};  
// let antd = {ReactDOMRe.Style.make(
//     ~border="2px solid #00ff00", 
//     ~width="100%",
//     ~height="60px",
//     ~fontSize="4em",
//     ~lineHeight="8em",
//     () )};      
// let antd_option = {ReactDOMRe.Style.make(
//     ~border="2px solid #0000ff", 
//     ~fontSize="3em",
//     ~lineHeight="2em",
//     ~width="100%", 
//     () )};      

[@react.component]
let make = (~tags_in, ~cb_select, ~cb_deselect) => {
//  <div id="ant-containder-id" style=StyleMeme.antd_container >
<div className="row">
//  <div id="ant-containder-id"  style=antd_container>
  <div id="ant-containder-id"  className="col s12">
    <Ant.Select 
//      style=StyleMeme.antd 
      className="col s12" 
      mode="multiple"
      onSelect={ s => cb_select(s)}
      onDeselect={ s => cb_deselect(s)}>
    {
      tags_in
//        |> List.map( tag => <Ant.Select.Option  style=StyleMeme.antd_option key=tag> {ReasonReact.string(tag)} </Ant.Select.Option> ) 
        |> List.map( tag => <Ant.Select.Option className="flow-text s12" key=tag> {ReasonReact.string(tag)} </Ant.Select.Option> ) 
        |> Array.of_list 
    }
    </Ant.Select>
  </div>
</div> ;
};