let str = ReasonReact.string;

let tones : list(list(string)) = [["40.0", "Serenity of Beingness"], ["30.0", "Postulates"], ["22.0", "Games"], ["20.0", "Action"], ["8.0", "Exhilaration"], ["6.0", "Aesthetic"], ["4.0", "Enthusiasm"], ["3.5", "Cheerfulness"], ["3.3", "Strong Interest"], ["3.0", "Conservatism"], ["2.9", "Mild Interest"], ["2.8", "Contented"], ["2.6", "Disinterested"], ["2.5", "Boredom"], ["2.4", "Monotony"], ["2.0", "Antagonism"], ["1.9", "Hostility"], ["1.8", "Pain"], ["1.5", "Anger"], ["1.4", "Hate"], ["1.3", "Resentment"], ["1.2", "No-sympathy"], ["1.15", "Unexpressed Resentment"], ["1.1", "Covert Hostility"], ["1.02", "Anxiety"], ["1.0", "Fear"], ["0.98", "Despair"], ["0.96", "Terror"], ["0.94", "Numb"], ["0.9", "Sympathy"], ["0.8", "Propitiation"], ["0.5", "Grief"], ["0.375", "Making Amends"], ["0.3", "Undeserving"], ["0.2", "Self-abasement"], ["0.1", "Victim"], ["0.07", "Hopeless"], ["0.05", "Apathy"], ["0.03", "Useless"], ["0.01", "Dying"], ["0.0", "Body Death"]]


let f2s = (a) => {
    Js.log("f2s:");
    let s = string_of_int(a) ++ "";
    s
};

let tones_data : list(list(string)) = {
    List.mapi( { 
        (i, tone_level) => {
            [string_of_int(i), List.nth(tone_level, 0), List.nth(tone_level,1)]
            }
        }, tones);
};
Js.log(tones_data);

let getToneLabel = (tone_index) => {
    let t : list(string) = List.find( { 
            (tone_level) => {
                List.nth(tone_level, 0) == tone_index
                }
        }, tones_data);
    let t_label :string =  List.nth(t,2)
    t_label
};

[@react.component]
let make = () => {
    let (tone, setTone) = React.useState( () => 1);
    let (tone_label, setToneLabel) = React.useState( () => "undefined");
    let (xname, setXName) = React.useState( () => "me");

    // React.useEffect1( 
    //     () => { 
    //         Js.log("Fired!")
    //         None;
    //         },
    //     [|tone|],
    // );

    {
    <div>

        <div>
            {str("EMOTIONAL TONES:")} <br />

            // <datalist id="slider-datalist">
            // (
            //         List.map( o => {
            //                             <option key=List.nth(o,0) value=List.nth(o,0) label=List.nth(o,1)></option> 
            //                         }   
            //             , slider_data)
            //         |> Array.of_list
            //         |> React.array
            // )
            // </datalist>
        
            <form 
                id="uploadFormTones"
                action= (Config.url_tones) // ++ "?name=" ++ ss.name ++ "&tone=" ++ string_of_float(tone))
                method="post"
                encType="multipart/form-data">                

                <label> {str("Name:")} </label>                
                <input 
                    id="emo_tones_name_id" 
                    //name="emo_tones_name_name" 
                    value={xname} 
                    // onKeyPress={ev=>{
                    //     let k = ReactEvent.Keyboard.key(ev)
                    //     if (k == "Enter") {
                    //         setName(current_meme))
                    //     }
                    //     }}
                    onChange={ev => {
                        let v = ReactEvent.Form.target(ev)##value
                        setXName(v)
                    }}
                />

                <br />
 
                <br />

                <div style=Style.h_tone_slider_wrapper>
                <input 
                    style=Style.h_tone_slider
                    type_="range"
                    min=0
                    max="40"
                    step=1.0
                    value={f2s(tone)}
                    onInput={ev => {
                        Js.log("tones: onInput")
                        let v = ReactEvent.Form.target(ev)##value;
                        setTone(_ => v)
                        let tone_label = getToneLabel(v)
                        Js.log("The found tone label is:")
                        Js.log(tone_label)
                        setToneLabel(_=> tone_label)
                        //dispatch(UpdateTone(value_f))
                        Js.log("dispatched")
                        }
                    }
                    onChange={ev => {
                        Js.log("onchange")
                        let value = ReactEvent.Form.target(ev)##value;
                        Js.log(value)
                        //dispatch(UpdateTone(float(value)))
                        Js.log("onchangeed");
                    }}

                    id="toneScale"
                />
                </div>
                <br />

                <label> {str(tone_label)} </label>                



                <br />

                <input type_="submit" value="Upload!" /> <br />

            </form>
        </div>


    </div>;
    }
};
