[@react.component]
let make = () =>  
  <div style=StyleMeme.antd_container >

    <Ant.Select 
      style=StyleMeme.antd
      mode="multiple">
      {
        [ "bash", "Linux", "OAuth2.0" ] 
          |> List.map( top => <Ant.Select.Option  style=StyleMeme.antd_option key=top> {ReasonReact.string(top)} </Ant.Select.Option> ) 
          |> Array.of_list 
      }
    </Ant.Select>
  </div> ;
