let valueFromEvent = (evt): string => evt->ReactEvent.Form.target##value;

  type state = string;
  [@react.component]
  let make = (~onSubmit) => {
    let (text, setText) = React.useReducer((oldText, newText) => newText, "");
    <input
        value=text
        type_="text"
        placeholder="Write something to do"
        onChange=((evt) => setText(valueFromEvent(evt)))
        onKeyDown=((evt) =>
        if (ReactEvent.Keyboard.key(evt) == "Enter") {
           onSubmit(text);
          setText("")
        }
      )
    />
  };
