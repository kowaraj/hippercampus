//real-time listener
//firebase send a snapshot of the DB when it changed

var memes_onSnapshot = (
function() {
    firestore_db.collection('memes').onSnapshot( snapshot => {
        //console.log(snapshot.docChanges())

        snapshot.docChanges().forEach(change => {
            if (change.type === 'added') {
                console.log(change.type, change.doc.data(), change.doc.id)
            }
            if (change.type === 'removed') {
                // console.log(change)
            }
        });
    })
}
);

exports.memes_onSnapshot = memes_onSnapshot;

