let str = ReasonReact.string;

type state = {
  count: int,
  show: bool,
};

type action =
  | Click;
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

    let (_state, _dispatch) = React.useReducer((state, action) =>
    switch (action) {
    | Click => {...state, count: state.count + 1}
    // | Toggle => {...state, show: ! state.show}
    // | GetForm => state
    // | Upload => {
    //     Js.log("fake uploading....");
    //     upload_file();
    //     state
    // }
    // | Submit => {
    //     Js.log("fake submit");
    //     state
    // }
    // | InputText(text) => {
    //     Js.log("fake InputText " ++ text);
    //     state
    // } 
    }, {count: 0, show: true});

  
    // .render

    {
    <div>
        <div>
            {str("FILE UPLOADER:")} <br />
            <form 
                id="uploadForm"
                action=Config.url_be
                method="post"
                encType="multipart/form-data">
                <input type_="file" name="sampleFile" /> <br />
                <input type_="submit" value="Upload!" />
            </form>
        </div>
    </div>;
    }
};
