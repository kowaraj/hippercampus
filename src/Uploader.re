let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
  tags: string,
  name: string
};

type action =
  | Click
  | UpdateTags(string)
  | UpdateName(string);
//   | Toggle
//   | GetForm
//   | Upload
//   | Submit
//   | InputText(string);

// let upload_file = () => {
//     Js.log("real uploading with fetch")
//     Js.log("upload completed !")
// };

let ql_req = "{
  allPosts {
    edges {
      node {
        id
      }
    }
  }
}";

[@react.component]
let make = () => {

    // .reduce

    let (ss, dispatch) = React.useReducer((state, action) =>
      switch (action) {
      | Click => {...state, count: state.count + 1}
      | UpdateTags(tags_string) => {...state, tags: tags_string}
      | UpdateName(name_string) => {...state, name: name_string}
      }, 
      {count: 0, show: true, tags: "", name: ""});
  
    // .render

    {
    <div>
        <div>
            {str("FILE UPLOADER:")} <br />
            <form 
                id="uploadForm"
                action= (Config.url_be ++ "?test_arg_var=test_arg_val")
                method="post"
                encType="multipart/form-data">
                <input type_="file" name="sampleFile" /> <br />
                <input type_="submit" value="Upload!" /> <br />
                <input 
                    type_="text"
                    name="name" 
                    value={ss.name} 
                    onChange={ev => {
                        let value = ReactEvent.Form.target(ev)##value;
                        dispatch(UpdateName(value))
                    }}
                />
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


        <div>
            {str("QL:")} <br />
            <form 
                id="uploadForm"
                action= (Config.url_ql ++ ql_req)
                method="post"
                encType="text/plain">
                <input type_="text" name="query" /> <br />
                <input type_="submit" value="Upload!" />
            </form>
        </div>
    </div>;
    }
};
