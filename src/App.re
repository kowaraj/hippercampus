let str = ReasonReact.string;

type route =
  | Home
  | Upload
  | Meme
  | DBDump;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <div className="container orange lighten-5">
    {
      switch (url.path) {
      | _ => {
              <Meme3 /> 
              } 
      }
    }

  </div>;
};



