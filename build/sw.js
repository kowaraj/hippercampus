const staticCache = 'site-static';

// assets for pre-caching
const assets = [
    '/',
    '/index.html',
    '/Index.js',
    '/app.js',
    '/sw.js',
    '/public/manifest',
    '/img/icons/icon-192x192.png',
    'http://localhost:4666/getmemerandom/',
    'http://localhost:4666/uploads/Screen%20Shot%202020-02-04%20at%2018.47.03.png',
    'http://localhost:4666/uploads/ShiftDisplay.png',
    'http://localhost:4666/uploads/jcmdr.png',
    '/meme'
];

// install service worker 
self.addEventListener('install', evt => {
    console.log('service worker has been installed')
    evt.waitUntil(
        caches.open(staticCache).then(cache => {
            console.log(staticCache + ' opened')
            cache.addAll(assets)
        })
    )
});

// reacting to an 'activate' event 
self.addEventListener('activate', evt => {
    console.log('service worker has been activated')
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



    //     evt.respondWith(
    //         caches.match(evt.request).then( cacheResp => {
    // //            return cacheResp || fetch(evt.request)
    //             if (cacheResp) {
    //                 return cacheResp
    //             } else {
    //                 evt.waitUntil(
    //                     caches.open(staticCache).then(cache => {
    //                         console.log('fetch to cache!')
    //                         cache.add(evt.request.url)
    //                     })
    //                 )
    //                 console.log('wait done');
    //                 caches.match(evt.request).then( cacheResp2 => {
    //                     return cacheResp2 || fetch(evt.request)
    //                 })
    //             }}))
    //         })        
