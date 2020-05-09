const staticCacheName = 'site-static-v2';

// assets for pre-caching
const assets = [
    '/',
    '/index.html',
    '/Index.js',
    '/app.js',
    '/sw.js',
    '/public/manifest',
    '/img/icons/icon-192x192.png'
    //,
    // 'http://localhost:4666/getmeme/shifts', 
    // 'http://localhost:4666/uploads/ShiftDisplay.png'
    // ,
    // 'http://localhost:4666/getmeme/macos',
    // 'http://localhost:4666/uploads/Screen%20Shot%202020-02-04%20at%2018.47.03.png'
];

// install service worker 
self.addEventListener('install', evt => {
    console.log('service worker has been installed')
    evt.waitUntil(
        caches.open(staticCacheName).then(cache => {
            console.log(staticCacheName + ' opened')
            cache.addAll(assets)
        })
    )
});

// reacting to an 'activate' event 
self.addEventListener('activate', evt => {
    //console.log('service worker has been activated')
    evt.waitUntil(
        caches.keys().then(keys => {
            //console.log(keys)
            return Promise.all(keys
                .filter(key => key !== staticCacheName)
                .map(key => caches.delete(key))
                )
        })
    )
});

// reacting to a 'fetch' request
self.addEventListener('fetch', evt => {
    console.log('fetch event', evt.request.url)

    evt.respondWith(
        caches.match(evt.request).then( cacheResp => {
            return cacheResp || fetch(evt.request)
        })
    )
})

// // reacting to a 'fetch' request
// self.addEventListener('fetch', evt => {
//     console.log('fetch event', evt.request.url)

//     evt.respondWith(
//         caches.match(evt.request)
//         .then( cacheResp => {
//             if (cacheResp) {
//                 console.log('HIT')
//                 return cacheResp
//             } else {
//                 console.log('MISS')
//                 fetch(evt.request)
//             }}))});

