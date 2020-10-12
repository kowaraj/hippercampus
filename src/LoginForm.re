[@bs.module "./Fireauth.js"]
external fs_create_user: ( string, string, (string => unit) ) => unit = "create_user";

[@bs.module "./Fireauth.js"]
external fs_logout: ( unit => unit ) = "logout";

[@bs.module "./Fireauth.js"]
external fs_login: ( string, string, (string => unit) ) => unit = "login";


//let app_uid = ref("");

[@react.component]
let make = () => {

    let (username, setUsername) = React.useState( () => "kj@gmail.com" );
    let (password, setPassword) = React.useState( () => "abracadabra" );

    let set_uid = (uid) => {

        Config.app_uid := uid

    }

    let signup = (_e) => {
//                Js.log("Signing UP:"++ username ++ password);
                fs_create_user(username, password, set_uid);
    }

    let signin = (_e) => {
        Js.log("signin: userID ======= " ++ Config.app_uid^ )
        switch (Config.app_uid^) {
        | "" => {
                Js.log("Loging in:"++ username ++ password);
                fs_login(username, password, set_uid);
                Config.mark := "IN";
            }
        | _ => {
                Js.log("Already logged in, uid: " ++ Config.app_uid^ ++ ", WIll log OUT")
                fs_logout()
                Config.app_uid := "";
                Config.mark := "OUT";
            }
       }

        ReasonReactRouter.push("/");
    };

    <div>
    // {
    //     switch (Config.mark^) {
    //     | "IN" => { <h1> {RR.str("LOGGED IN")} </h1> }
    //     | "OUT" => { <h1> {RR.str("LOGGED OUT")} </h1> }
    //     | _ => { <h1> {RR.str("INIT")} </h1> }
    //     }

    // }
        <input type_="text" name="username" value={username} placeholder="user name"
            onChange= { ev => setUsername(ReactEvent.Form.target(ev)##value) } 
            />
        <input type_="text" name="password" value={password} placeholder="pass word"
            onChange= { ev => setPassword(ReactEvent.Form.target(ev)##value) } 
            />
        <button className="btn indigo" onClick=signup> {RR.str("Sign Up")} </button> 
    {
        switch (Config.mark^) {
        | "IN" => { <button className="btn pink  " onClick=signin> {RR.str("Sign OUT")} </button> }
        | _ => { <button className="btn green  " onClick=signin> {RR.str("Sign In")} </button>  }
        }

    }
//        <button className="btn pink  " onClick=signin> {RR.str("Sign In")} </button> 


    </div>

};

