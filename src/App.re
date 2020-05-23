let str = ReasonReact.string;

type route =
  | Home
  | Upload
  | Meme
  | DBDump;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  <div>

    <Nav />
    {switch (url.path) {
    | ["home"] => {
        <Home />
      } 
    | ["meme"] => {
        <Meme /> 
      }
    | ["upload"] => {
        <Uploader /> 
      }
    | ["dbdump"] => {
        <FetchData2 /> 
      }
    | _ => {
        <p> {str("None")} </p>
      } 
    }}

  </div>;
};



