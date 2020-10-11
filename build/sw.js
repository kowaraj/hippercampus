const staticCacheName =   'site-static-v9';
const dynamicCacheName = 'site-dynamic-v9';

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

// limit cache size
const limitCacheSize = (name, size) => {
    caches.open(name).then(cache => {
        cache.keys().then(keys => {
            if (keys.length > size) {
                cache.delete(keys[0]).then(limitCacheSize(name, size));
            }
        })
    })
};

// install service worker 
self.addEventListener('install', evt => {
    //console.log('service worker has been installed')
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
                .filter(key => key !== staticCacheName && key !== dynamicCacheName)
                .map(key => caches.delete(key))
                )
        })
    )
});

// reacting to a 'fetch' request
self.addEventListener('fetch', evt => {

    fspos = evt.request.url.indexOf('firestore.googleapis.com')
    if (fspos === -1) {

        evt.respondWith(
            caches.match(evt.request)
            .then( cacheResp => {

//                return cacheResp || fetch(evt.request, {mode: "cors"}).then( fetchResp => {
                return cacheResp || fetch(evt.request).then( fetchResp => {
                        //console.log("--> : " + evt.request.url + " == (" + fetchResp.type + ") " +  fetchResp.url)
                    return caches.open(dynamicCacheName).then( cache => {
                        cache.put(fetchResp.url, fetchResp.clone())
                        limitCacheSize(dynamicCacheName, 200)
                        return fetchResp
                    })
                })
            })
            .catch( cacheMiss => {

                // if (evt.request.url.indexOf('getmeme/') !== -1) {
                //     return caches.match('http://localhost:4666/getmeme/macos')
                // }
                // if (evt.request.url.indexOf('uploads/') !== -1) {
                //     return caches.match('http://localhost:4666/uploads/ShiftDisplay.png')
                // }
            })
        )

    }
    else {
        //console.log("firestore will not be cached")
    }
})

