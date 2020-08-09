# Firestore

- <App /> includes <Db /> which is a .re component.
- Db.re is a wrapper for Firestore.js which is a pure JavaScript interface to Firestore.
- ./build/db.js = not required any longer
- index.html contains the initialization of the `firestore_db` JS variables (which is used firectly from Firestore.js)
```
  <!-- The core Firebase JS SDK is always required and must be listed first -->
  <script src="https://www.gstatic.com/firebasejs/7.17.2/firebase-app.js"></script>
  <script src="https://www.gstatic.com/firebasejs/7.17.2/firebase-firestore.js"></script>
  <script>
    // Your web app's Firebase configuration
     var firebaseConfig = {
      apiKey: "AIzaSyDz1wxTwSaZQupaMxgPygYLHVlgWvatAQM",
      authDomain: "hippercampus-pwa.firebaseapp.com",
      databaseURL: "https://hippercampus-pwa.firebaseio.com",
      projectId: "hippercampus-pwa",
      storageBucket: "hippercampus-pwa.appspot.com",
      messagingSenderId: "498686373457",
      appId: "1:498686373457:web:89418ae315cb26489d1270"
    };
    // Initialize Firebase
    firebase.initializeApp(firebaseConfig);
    const firestore_db = firebase.firestore()
    const test_db_apashnin = "test_db_apashnin";
  </script>
```
