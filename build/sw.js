// install service worker 
self.addEventListener('install', evt => {
    console.log('service worker has been installed')
});

// reacting to an 'activate' event 
self.addEventListener('activate', evt => {
    console.log('service worker has been activated')
});

// reacting to a 'fetch' request
self.addEventListener('fetch', evt => {
    console.log('fetch event', evt)
});