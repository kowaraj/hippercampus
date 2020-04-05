let str = ReasonReact.string;

type route =
  | Home
  | Upload
  | Meme
  | DBDump;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  // Js.log("The current URL: ")
  // Js.log(url.path);
  <div>
    {switch (url.path) {
    | ["home"] => {
        //Js.log("Going to 'home' page"); 
        <Home />
      } 
    | ["meme"] => {
        //Js.log("Going to 'meme' page"); 
        <Meme /> 
      }
    | ["upload"] => {
        //Js.log("Going to 'upload' page"); 
        <Uploader /> 
      }
    // | ["tones"] => {
    //     <EmotionalTones /> 
    //   }
    | _ => {
        Js.log("Going to default page"); 
        <p> {str("None")} </p>
        // unused: <FetchData2 /> 
      } 
    }}
//    <p> {str("Navigation menu:")} </p>
//    <Nav />

  </div>;
};



