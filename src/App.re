let str = ReasonReact.string;

type route =
  | Home
  | Upload
  | Meme
  | DBDump;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <div className=S.app_main>
    {
      switch (url.path) {
      | _ => {
              <Meme3 /> 
              } 
      }
    }
    //<p> {str("v.20200911.5")} </p>
  </div>;
};



