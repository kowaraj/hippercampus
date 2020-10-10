let str = ReasonReact.string;

type route =
  | Home
  | Upload
  | Meme
  | DBDump;

[@react.component]
let make = () => {

  let url = ReasonReactRouter.useUrl();
  <div className="container grey-text text-darken-1">

    <p className="row"> {str("v.20200910.4")} </p>
    //<Nav />
    {
      switch (url.path) {
      // | ["home"] => {
      //     <Home />
      //   } 
      // | ["meme"] => {
      //     <Meme /> 
      //   }
      // | ["meme2"] => {
      //     <Meme2 /> 
      //   }
      // | ["meme3"] => {
      //     <Meme3 /> 
      //   }
      // | ["upload"] => {
      //     <Uploader /> 
      //   }
      // | ["dbdump"] => {
      //     <FetchData2 /> 
      //   }
      | _ => {
          <Meme3 /> 
          //<p> {str("None")} </p>
      } 
    }}

  </div>;
};



