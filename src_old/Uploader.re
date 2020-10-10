let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
  tags: string,
  name: string, 
  text: string
};

type action =
  | Click
  | UpdateTags(string)
  | UpdateText(string)
  | UpdateName(string);

[@react.component]
let make = () => {

    // .reduce

    let (ss, dispatch) = React.useReducer((state, action) =>
      switch (action) {
      | Click => {...state, count: state.count + 1}
      | UpdateTags(tags_string) => {...state, tags: tags_string}
      | UpdateText(text_string) => {...state, text: text_string}
      | UpdateName(name_string) => {...state, name: name_string}
      }, 
      {count: 0, show: true, tags: "", text: "", name: ""});
  
    // .render

    {
    <div>
        <div style=StyleUpload.container>
            // {str("FILE UPLOADER:")} <br />
            <form style=StyleUpload.form
                id="uploadForm"
                action= (Config.url_be_create ++ "?test_arg_var=test_arg_val")
                method="post"
                encType="multipart/form-data">                

                <label style=StyleUpload.label> {str("Image:")} </label> <br />
                <input 
                    style=StyleUpload.file_button 
                    type_="file" 
                    name="sampleFile" 
                    placeholder="filename"
                    /> <br />

                <label style=StyleUpload.label> {str("Name:")} </label> <br />
                <input 
                    style=StyleUpload.input
                    type_="text"
                    name="name" 
                    value={ss.name} 
                    onChange={ev => {
                        let value = ReactEvent.Form.target(ev)##value;
                        dispatch(UpdateName(value))
                    }}
                    />  <br />

                <label style=StyleUpload.label> {str("Tags:")} </label> <br />
                <input 
                    style=StyleUpload.input
                    type_="text"
                    id="search" 
                    name="tags" 
                    value={ss.tags} 
                    onChange={ev => {
                        let value = ReactEvent.Form.target(ev)##value;
                        dispatch(UpdateTags(value))
                    }}
                />
                <br />
                <label style=StyleUpload.label> {str("Text:")} </label>  <br />
                // <input 
                //     style=StyleUpload.input
                //     type_="text"
                //     id="searchtext" 
                //     name="text" 
                //     value={ss.text} 
                //     onChange={ev => {
                //         let value = ReactEvent.Form.target(ev)##value;
                //         dispatch(UpdateText(value))
                //     }}
                // />
               <textarea 
                    style=StyleUpload.textarea
                    type_="text"
                    id="searchtext" 
                    name="text" 
                    value={ss.text} 
                    onChange={ev => {
                        let value = ReactEvent.Form.target(ev)##value;
                        dispatch(UpdateText(value))
                    }}
                />                
                <br />
                <input style=StyleUpload.button type_="submit" value="Upload!" /> <br />

            </form>
        </div>

    </div>;
    }
};
