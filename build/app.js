if ('serviceWorker' in navigator) {
    navigator.serviceWorker.register('/sw.js')
    .then(() => console.log('sw registered'))
    .catch(() => console.log('sw not registered'))
}