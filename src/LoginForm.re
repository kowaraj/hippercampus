[@bs.module "./Fireauth.js"]
external fs_create_user: ( string, string, (string => unit) ) => unit = "create_user";

[@bs.module "./Fireauth.js"]
external fs_logout: ( unit => unit ) = "logout";

[@bs.module "./Fireauth.js"]
external fs_login: ( string, string, (string => unit) ) => unit = "login";


//let app_uid = ref("");

[@react.component]
let make = () => {

    // let (username, setUsername) = React.useState( () => "kj@gmail.com" );
    // let (password, setPassword) = React.useState( () => "abracadabra" );
    let (username, setUsername) = React.useState( () => "" );
    let (password, setPassword) = React.useState( () => "" );

    let set_uid = (uid) => {
        Js.log("loginform: set_uid: "++ uid)
    }

    let signup = (_e) => {
                Js.log("Sign-up has been disabled.");
                //fs_create_user(username, password, set_uid);
    }

    let signin = (_e) => {
        switch (Config.is_logged_in()) {
        | true => { fs_logout() }
        | false => { fs_login(username, password, set_uid); }
        }
        ReasonReactRouter.push("/");
    };

    let sign_cancel = _ => {
        ReasonReactRouter.push("/");
    };

    <div>
 
        {
            switch (Config.is_logged_in()) {
                | true => { <p> {RR.str("User logged in")} </p> }
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
                | true =>  { <button className="btn pink  " onClick=signin> {RR.str("Sign OUT")} </button> }
                | false => { <button className="btn green " onClick=signin> {RR.str("Sign In")} </button>  }
            }
        }

//        <button className="btn pink  " onClick=signin> {RR.str("Sign In")} </button> 
        <button className="btn grey right" onClick=sign_cancel> {RR.str("Back")} </button> 


    </div>

};

