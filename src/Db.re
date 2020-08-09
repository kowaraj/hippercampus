[@bs.module "./Firestore.js"]
external fs_memes_onSnapshot: unit => unit = "memes_onSnapshot";


[@react.component]
let make = () => {

    fs_memes_onSnapshot();
    <div>
    </div>
};