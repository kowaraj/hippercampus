let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
  tags: string
};

type action =
  | Click
  | UpdateTags(string);
//   | Toggle
//   | GetForm
//   | Upload
//   | Submit
//   | InputText(string);

// let upload_file = () => {
//     Js.log("real uploading with fetch")
//     Js.log("upload completed !")
// };


[@react.component]
let make = () => {

    // .reduce

    let (ss, dispatch) = React.useReducer((state, action) =>
      switch (action) {
      | Click => {...state, count: state.count + 1}
      | UpdateTags(tags_string) => {...state, tags: tags_string}
      }, 
      {count: 0, show: true, tags: ""});
  
    // .render

    {
    <div>
        <div>
            {str("FILE UPLOADER:")} <br />
            <form 
                id="uploadForm"
                action= (Config.url_be ++ "?testvar=testval")
                method="post"
                encType="multipart/form-data">
                <input type_="file" name="sampleFile" /> <br />
                <input type_="submit" value="Upload!" />
                <input 
                    type_="text"
                    id="search" 
                    name="tags" 
                    value={ss.tags} 
                    onChange={ev => {
                        let value = ReactEvent.Form.target(ev)##value;
                        dispatch(UpdateTags(value))
                    }}
                />

            </form>
        </div>
    </div>;
    }
};
