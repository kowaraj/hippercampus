//real-time listener
db.collection('memes').onSnapshot( snapshot => {
    //console.log(snapshot.docChanges())
})