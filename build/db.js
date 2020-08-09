//real-time listener
//firebase send a snapshot of the DB when it changed
// db.collection('memes').onSnapshot( snapshot => {
//     console.log(snapshot.docChanges())

//     snapshot.docChanges().forEach(change => {
//         if (change.type === 'added') {
//             console.log(change)
//         }
//         if (change.type === 'removed') {
//             console.log(change)
//         }
//     });
// })