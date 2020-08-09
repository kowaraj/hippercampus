var memes_onSnapshot = (
function() {
    firestore_db.collection('memes').onSnapshot( snapshot => {
        console.log(snapshot.docChanges())

        snapshot.docChanges().forEach(change => {
            if (change.type === 'added') {
                console.log(change)
            }
            if (change.type === 'removed') {
                console.log(change)
            }
        });
    })
}
);

exports.memes_onSnapshot = memes_onSnapshot;

