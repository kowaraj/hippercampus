- TEST (React) Express (backend), see: https://github.com/kowaraj/hippercampus_test_be
- TEST React client (frontend), see: https://github.com/kowaraj/hippercampus_test_fe
- ACTUAL frontend (localhost:3002), the current project https://github.com/kowaraj/hippercampus
- ACTUAL backend (localhost:3003), see `flask run  --host localhost --port 3003` in here https://github.com/kowaraj/hippercampus_py_neo4j_v2

TODO:
- add a timestamp to the image files, like: image_filename_ts.png
- Replace getmeme/<meme/name> with getmeme_by_id/<id>

# Hippercampus

- Frontend (localhost:3002), the current project https://github.com/kowaraj/hippercampus
- Backend (localhost:3003), see `flask run  --host localhost --port 3003` in here https://github.com/kowaraj/hippercampus_py_neo4j_v2

## Run it (frontend)
```
npm install

# Tab 1
`npm start` = to trans-pile *.re to *.js

# Tab 2
`npm run webpack` = to bundle *.js to Index.js

# Tab 3
`npm run server` = to start a web server
```

## Run the _test_be

It expects a backend to be found on `localhost:3003`


# CORS configuration

Actors: 
- frontend: 
  - rendered img tag with src="http://localhost:4666/uploads/image1"
  - fetched meme with src="http://localhost:4666/meme/meme1"
  - service worker (interrupting the fetch and checking cache)
  - dynamic cache itself
- backend:
  - flask \__init__.py with CORS(app, resources={...})
  - flask route for GET of '/uploads/<\fn>'
- browser (+ DevTools):
  - Application tab: Service worker
  - Application tab: Cache storage
  - "Update on reaload" checkbox
  - "Offline" checkbox


image tag:
```
  <img src=m.fn style=StyleMeme.modal_content onClick={ _=>invert_modal()}/> 
```
 
fetching a meme:
```
  Fetch.fetch(Config.url_be_root++"/getmemes")
```

sw.js:
```
self.addEventListener('fetch', evt => {
    evt.respondWith(
        caches.match(evt.request).then( cacheResp => {
            return cacheResp || fetch(evt.request, {mode: "cors"}).then( fetchResp => {
                return caches.open(dynamicCacheName).then( cache => {
                    cache.put(fetchResp.url, fetchResp.clone())
                    return fetchResp
  ...
```

Flask's \__init__:
```
cors = CORS(app, resources={
    r"/uploads/*": {"Access-Control-Allow-Origin": "http://localhost:3666"},
    r"/getmemes*": {"origins": "*"}, 
    r"/getmeme/*": {"origins": "*"}
    })
```

Flask's route:
```
@bp.route('/uploads/<fn>', methods=['GET'])
def uploads(fn):
    ...
    resp.headers["Access-Control-Allow-Origin"] =  "http://localhost:3666"
    resp.headers["Access-Control-Allow-Credentials"] =  "true"
```
















# How it works

index.html has 2 tags - index_uploader and index_content
Index.re binds 2 components to these 2 tags - Uploader and FetchData2

### Uploader 

Uploader is a Reducer. It does the following:
- display upload form (pure HTML)
  - 'submit' makes a POST to "http://localhost:3000/upload" (see: Config.re)
- TODO: no need to be a Reducer = no state, no action

### FetchData2

FetchData2 is a component with hooks:
- 3 useState
- 1 useEffect1
- 1 useReducer

`doFetchData` makes a GET to "http://localhost:3000/..." to query the database for the info.

It renders a form which by 'onSubmit' "reduces" to `FetchDataX(str)` the info.




