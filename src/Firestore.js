// Interface to the Firestore database
// Used by a wrapper, see Db.re

//real-time listener
//firebase send a snapshot of the DB when it changed

const firestore_db = firebase.firestore()
firestore_db.enablePersistence().catch(err => {
    if(err.code == 'failed-precondition') {
        console.log("persistence failed"); 
    } else if (err.code == 'unimplemented') {
        console.log("persistence is not available")
    }
})

var memes_onSnapshot = (
function(db_callback) {
    firestore_db.collection('memes').onSnapshot( snapshot => {
        //console.log(snapshot.docChanges())
        snapshot.docChanges().forEach(change => {
            console.log(change.type, change.doc.data(), change.doc.id)
            if (change.type === 'added') {
                db_callback(change.doc.id, change.doc.data(), change.type)
            }
            if (change.type === 'removed') {
                db_callback(change.doc.id, change.doc.data(), change.type)
            }
            if (change.type === 'modified') {
                db_callback(change.doc.id, change.doc.data(), change.type)
            }
        });
    })
}
);

var add_meme = (m_no_id) => {
    console.log(m_no_id)
    firestore_db.collection('memes').add(m_no_id)
                .catch(err => console.log(err));
};

var mod_meme = (m) => {
    console.log(m)
    firestore_db.collection('memes').doc(m.id).set(m)
                .catch(err => console.log(err));
};

var del_meme = (meme_id) => {
    firestore_db.collection('memes').doc(meme_id).delete()
                .then(console.log("meme deleted:", meme_id))
                .catch(err => console.log(err));
};

exports.memes_onSnapshot = memes_onSnapshot;
exports.add_meme = add_meme;
exports.mod_meme = mod_meme;
exports.del_meme = del_meme;

