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

    {
    <div>

        <div>
            {str("EMOTIONAL TONES:")} <br />
            <form 
                id="uploadFormTones"
                action= (Config.url_tones) // ++ "?name=" ++ ss.name ++ "&tone=" ++ string_of_float(tone))
                method="post"
                encType="multipart/form-data">                

                <label> {str("Name:")} </label>                
                <input 
                    id="emo_tones_name_id" 
                    value={xname} 
                    onChange={ev => {
                        let v = ReactEvent.Form.target(ev)##value
                        setXName(v)
                    }}
                />

                <br />
 
                <br />
                <div style=Style.h_div_split2_container>
                    <div style=Style.h_div_split2_vertical_p0>
                        <div>
                            <div style=Style.h_tone_slider_wrapper>
                            <input 
                                style=Style.h_tone_slider
                                type_="range"
                                min=0
                                max="40"
                                step=1.0
                                value={f2s(tone)}
                                onInput={ev => {
                                    let v = ReactEvent.Form.target(ev)##value;
                                    setTone(_ => v)
                                    let tone_label = getToneLabel(v)
                                    setToneLabel(_=> tone_label)
                                    }
                                }
                                onChange={ev => {
                                    let value = ReactEvent.Form.target(ev)##value 
                                    Js.log(value)
                                }}
                                id="toneScale"
                            />
                            </div>
                        </div>
                //                        <p> {str("part 1")} </p>
                    </div>
                    <div style=Style.h_div_split2_vertical_pi>

                        <table id="tones-table">
                        <tbody>
                        (
                            {
                                let cellClick = (x, ev) => {
                                    let value = ReactEvent.Mouse.target(ev);
                                    Js.log(value);
                                    Js.log(x);
                                    setTone(_ => int_of_string(x));
                                    let tone_label = getToneLabel(x);
                                    setToneLabel(_=> tone_label);

                                    ()
                                };
                                let len = List.length(tones_data)
                                let a = Array.of_list(tones_data)
                                let t0 = Belt.Array.slice(a, ~offset=0,     ~len=len/2 )
                                let t1 = Belt.Array.slice(a, ~offset=len/2, ~len=len   )
                                let t_pairs = Belt.Array.zip(t0,t1)

                                Array.map( o => {

                                    let (e1,e2) = o;
                                    <tr key=List.nth(e1,0)>
                                        <td style=Style.h_emotones_cell onClick=cellClick(List.nth(e1,0)) key=List.nth(e1,0)> {str(List.nth(e1,2))}</td>
                                        <td style=Style.h_emotones_cell onClick=cellClick(List.nth(e2,0)) key=List.nth(e2,0)> {str(List.nth(e2,2))}</td>
                                    </tr> 

                                }   
                                , t_pairs)

                            |> React.array
                            }
                        )
                        </tbody>
                        </table>
                            
                        //<p> {str("part 2")} </p>
                    </div>
                    // <div style=Style.h_div_split2_vertical_pi>
                    //     <p> {str("part 3")} </p>
                    // </div>
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
