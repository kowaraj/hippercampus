[@bs.module "./Fireauth.js"]
external fs_create_user: ( string, string, (string => unit) ) => unit = "create_user";

[@bs.module "./Fireauth.js"]
external fs_logout: ( unit => unit ) = "logout";

[@bs.module "./Fireauth.js"]
external fs_login: ( string, string, (string => unit) ) => unit = "login";


let dumpDbIntoFile : string => unit = [%raw {|
function download(text) {
  var pom = document.createElement('a');
  pom.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
  pom.setAttribute('download', "dump.json");
  pom.style.display = 'none';
  document.body.appendChild(pom);
  pom.click();
  document.body.removeChild(pom);
}
|}];

type data = {    ms: array(TT.fs_meme_t)    };
[@bs.scope "JSON"] [@bs.val] external parseIntoMyData: string => data = "parse"



[@react.component]
let make = () => {

    let (username, setUsername) = React.useState( () => "" );
    let (password, setPassword) = React.useState( () => "" );

    let set_uid = (uid) => {
        Js.log("loginform: set_uid: "++ uid)
    }

    let signup = (_e) => {
        Js.log("Sign-up is disabled.");
        //fs_create_user(username, password, set_uid);
    }

    let signin = (_e) => {
        fs_login(username, password, set_uid); 
        ReasonReactRouter.push("/");
    };

    let signout = (_e) => {
        fs_logout() 
        ReasonReactRouter.push("/");
    };

    let sign_cancel = _ => {
        ReasonReactRouter.push("/");
    };

    <div className=S.menu_container>
        <div className=S.generic_row>
        </div>
        
        <div className=S.generic_row>
            {
                switch (Config.is_logged_in()) {
                    | true =>  { <p> {RR.str("User logged in") } </p> }
                    | false => { <p> {RR.str("User logged out")} </p> }
                }
            }

            <input type_="text" id="hippercampus.username" name="hippercampus.username" value={username} 
                placeholder="user name" autoComplete="on"
                onChange= { ev => setUsername(ReactEvent.Form.target(ev)##value) } 
                />
            <input type_="text" id="hippercampus.password" name="hippercampus.password" value={password} 
                placeholder="pass word" autoComplete="on"
                onChange= { ev => setPassword(ReactEvent.Form.target(ev)##value) } 
                />
            <button className="btn indigo" onClick=signup> {RR.str("Sign Up")} </button> 

            {
                switch (Config.is_logged_in()) {
                    | true =>  { <button className="btn pink  " onClick=signout> {RR.str("Sign Out")} </button> }
                    | false => { <button className="btn green " onClick=signin > {RR.str("Sign In") } </button> }
                }
            }

            //<button className="btn pink  " onClick=signin> {RR.str("Sign In")} </button> 
            <button className="btn grey right" onClick=sign_cancel> {RR.str("Back")} </button> 
        </div>

        <div className=S.generic_row>
            <button className=S.db_dump_button 
                onClick={ _ => {
                    let ms_json = Utils.mlist2jsonstr(RenderMemeList.memes_ref^);
                    dumpDbIntoFile(ms_json);
                    //let result = parseIntoMyData(ms_json)
                    //Js.log(result)
                    } }
                > {RR.str("DUMP")} </button> 
        </div>
    </div>

};

