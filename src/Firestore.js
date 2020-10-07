// Interface to the Firestore database
// Used by a wrapper, see Db.re

//real-time listener
//firebase send a snapshot of the DB when it changed

const firestore_db = firebase.firestore()
var memes_onSnapshot = (
function(cb) {
    firestore_db.collection('memes').onSnapshot( snapshot => {
        //console.log(snapshot.docChanges())
        snapshot.docChanges().forEach(change => {
            if (change.type === 'added') {
                //console.log(change.type, change.doc.data(), change.doc.id)

                var m = change.doc.data();
//                console.log(m)
                // var mm_001 = /* name */m[/* name */1];
                // var mm_002 = /* text */m[/* text */2];
                // var mm_003 = /* fn */m[/* fn */3];
                // var mm_004 = /* tags */m[/* tags */4];
                // var mm = /* record */[
                //   /* id */m_id,
                //   mm_001,
                //   mm_002,
                //   mm_003,
                //   mm_004
                // ];
            
                //                cb(change.doc.data().id, change.doc.data().name, {name: change.doc.data().name, text: change.doc.data().text}, change.doc.data())
                cb(change.doc.id, m )

            }
            if (change.type === 'removed') {
                // console.log(change)
            }
        });
    })
}
);

exports.memes_onSnapshot = memes_onSnapshot;

