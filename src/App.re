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
    | ["meme2"] => {
        <Meme2 /> 
      }
    | ["meme3"] => {
        <Meme3 /> 
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

    <Db />
  </div>;
};



