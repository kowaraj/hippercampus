const firebase_auth = firebase.auth()

var create_user = (n, p, cb) => {
    console.log("JS:", n,p)

    firebase_auth.createUserWithEmailAndPassword(n, p)
    .then( creds => {
        console.log("creds: ", creds) 
        const uid =  creds.user.uid
        console.log("creds.user.uid: ", uid) 
        cb(uid)

    })
    .catch( err => console.log("exception: ", err) )

    console.log("JS: done: ", n,p)

}

var login = (n, p, cb) => {
    console.log("loging IN");
    firebase_auth.signInWithEmailAndPassword(n, p)
    .then( creds => {
        console.log("login creds: ", creds) 
        const uid =  creds.user.uid
        console.log("login creds.user.uid: ", uid) 
        cb(uid)

    })
    .catch( err => console.log("login exception: ", err) )


}

var logout = () => {
    console.log("loggin OUT")
    firebase_auth.signOut()
    .then( res => console.log("User has logged out"))
    .catch( err => console.log("logout exception: ", err) )
}

exports.create_user = create_user;
exports.logout = logout;
exports.login = login;


