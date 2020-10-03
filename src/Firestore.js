//real-time listener
//firebase send a snapshot of the DB when it changed

const firestore_db = firebase.firestore()
var memes_onSnapshot = (
function(cb) {
    firestore_db.collection('memes').onSnapshot( snapshot => {
        //console.log(snapshot.docChanges())

        snapshot.docChanges().forEach(change => {
            if (change.type === 'added') {
                console.log(change.type, change.doc.data(), change.doc.id)
//                cb(change.doc.data().id, change.doc.data().name, {name: change.doc.data().name, text: change.doc.data().text}, change.doc.data())
                cb(change.doc.id, change.doc.data())
            }
            if (change.type === 'removed') {
                // console.log(change)
            }
        });
    })
}
);

exports.memes_onSnapshot = memes_onSnapshot;

