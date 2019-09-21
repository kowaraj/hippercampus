- For the test (React) Express (backend), see: https://github.com/kowaraj/hippercampus_test_be
- For the test React client (frontend), see: https://github.com/kowaraj/hippercampus_test_fe

# Hippercampus

## Run it
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

It expects a backend to be found on `localhost:3000/upload` and `localhost:3000/2`

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

`doFetchData` makes a GET to "http://localhost:3000/test_be/2" to query the (future) database for the info.

It renders a form which by 'onSubmit' "reduces" to `FetchDataX(str)` the info.




# More info


After you see the webpack compilation succeed (the `npm run webpack` step), open up `build/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Run Project with Server

To run with the webpack development server run `npm run server` and view in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

Note that any hot reload on a route will fall back to the root (`/`), so `ReasonReact.Router.dangerouslyGetInitialUrl` will likely be needed alongside the `ReasonReact.Router.watchUrl` logic to handle routing correctly on hot reload refreshes or simply opening the app at a URL that is not the root.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 npm run server`).

## Build for Production

```sh
npm run clean
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version as well as copy `src/index.html` into `build/`. You can then deploy the contents of the `build` directory (`index.html` and `Index.js`).

If you make use of routing (via `ReasonReact.Router` or similar logic) ensure that server-side routing handles your routes or that 404's are directed back to `index.html` (which is how the dev server is set up).

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
