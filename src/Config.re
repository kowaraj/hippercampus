let local = true
let url_be_root =  if (local) "http://localhost:4666" else "http://ec2-54-246-215-40.eu-west-1.compute.amazonaws.com:4666"
//let url_be_root =  if (local) "http://192.168.1.32:4666" else "http://ec2-54-246-215-40.eu-west-1.compute.amazonaws.com:4666"
let url_be_create =  url_be_root ++ "/creatememe";

let url_be_root4 =  "http://to_be_defined:4666"
let url_be_root_uploads = "http://to_be_defined:4666"
let url_be_create4 =  url_be_root4 ++ "/creatememe";

type login_t = 
    | LOGGED_INIT
    | LOGGED_IN 
    | LOGGED_OUT
    ;

let login_state = ref(LOGGED_INIT);
let is_logged_in = () => { 
    switch (login_state^) {
        // | LOGGED_INIT => {Js.log("config: is_logged_in: LOGIN STATE: INIT"); false}
        // | LOGGED_IN =>   {Js.log("config: is_logged_in: LOGIN STATE: IN"); true}
        // | LOGGED_OUT =>  {Js.log("config: is_logged_in: LOGIN STATE: OUT"); false}
        | LOGGED_INIT => false
        | LOGGED_IN =>   true
        | LOGGED_OUT =>  false
    }
}
