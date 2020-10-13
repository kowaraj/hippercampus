type route =
  | Home
  | Login;


[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <div className=S.app_main>
  <Env />  
  {
      switch (url.path) {
      | ["login"] => {
              <LoginForm /> 
              } 
      | _ => {
              <Meme3 /> 
              } 
      }
  }
  //<p> {str("v.20200911.5")} </p>
  </div>;
};



