[@bs.module "./Fireauth.js"]
external fb_registerCallback_onAuthStateChanged: ( (string => unit) => unit ) = "registerCallback_onAuthStateChanged";

let onauth_callback = user => {
    Js.log(user)
    switch (user) {
        | "" => { Js.log("onauth_callback: User logged out");  Config.login_state := LOGGED_OUT;}
        | _  => { Js.log("onauth_callback: User logged in"); Config.login_state := LOGGED_IN;}
    }
}

Js.log("registering callback: fb_registerCallback_onAuthStateChanged(onauth_callback")
fb_registerCallback_onAuthStateChanged(onauth_callback);


[@react.component]
let make = () => {

    <div>
    </div>
}