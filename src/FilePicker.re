let valueFromEvent = (evt): string => evt->ReactEvent.Form.target##value;
let filesFromEvent = (evt): string => evt->ReactEvent.Form.target##files;

/* Web File API object; different browsers have different properties. */
type fileType = {
  .
  "lastModified": int,
  "lastModifiedDate": string,
  "name": string,
  "size": int,
  "type_": string,
  "webkitRelativePath": string,
};
let filesFromEvent2 = (evt): string => {
    let files: list(fileType) = ReactEvent.Form.target(evt)##files;
    let file1 = ReactEvent.Form.target(evt)##files[0];
    Js.log(file1);
    
    let firstFile = List.length(files) > 0 ? Some(List.hd(files)) : None;
    Js.log("First file is: ")
    Js.log(firstFile);
    let filename: string = ReactEvent.Form.target(evt)##value;

    if (Js.String.startsWith("C:\\fakepath\\", filename)) {
      Js.String.sliceToEnd(~from=12, filename)
    } else {
      filename
    };

}

type state = string;
[@react.component]
let make = (~onSubmit) => {
    let (text, setText) = React.useReducer((oldText, newText) => newText, "");
    <input
        value=text
        type_="file"
        placeholder="Write something to do"
        onChange=((evt) => {
            Js.log("fired -- FilePicker: onChange"); 
            Js.log(evt); 
            Js.log("Files from event:"); 
            Js.log(filesFromEvent(evt))
            Js.log(filesFromEvent2(evt))
            setText(valueFromEvent(evt));




            })
        onKeyDown=((evt) =>
        if (ReactEvent.Keyboard.key(evt) == "Enter") {
           onSubmit(text);
          setText("")
        }
      )
    />
  };
