
let component = {ReactDOMRe.Style.make(
    ~border="10px solid #0000ff", 
    ~padding="0.2rem", 
    ~margin="0.2px", 
    // ~width="fit-content", 
    // ~height="fit-content", 
    ~width="95vw",
    ~height="95vh",
    // ~maxWidth="100%", 
    // ~maxHeight="100%", 
    () )};

let container = {ReactDOMRe.Style.make(
    ~border="5px solid #ff0000", 
    ~padding="0rem", 
    ~margin="0px", 
    ~width="94vw",
    ~height="85vh",
//    ~display="inline-flex",
//    ~width="fit-content", 
//    ~height="fit-content", 
    () )};

let button_fetch = {ReactDOMRe.Style.make(
    ~border="1px solid #aaaaaa", 
    ~margin="1px",
    ~height="5vh",
    ~width="20vh",
    ~fontSize="2vh",
    () )};  

let name_f = (len) => {ReactDOMRe.Style.make(
    ~border="1px solid #aaaaaa", 
    ~margin="1px",
    ~fontSize=len++"vw",
    ~textAlign="center",
    //~maxWidth="40vw", 
    ~maxHeight="40vh", 
    () )};  

let name = {ReactDOMRe.Style.make(
    ~border="1px solid #aaaaaa", 
    ~margin="1px",
    ~fontSize="15vw",
    ~textAlign="center",
    ~maxWidth="40vw", 
    ~maxHeight="40vh", 
    () )};  

let text = {ReactDOMRe.Style.make(
    ~border="1px solid #aaaaaa", 
    ~margin="5px",
    ~position="center",
    ~fontSize="10vw",
    ~textAlign="left",
    ~wordBreak="break-all",
    () )};  

let image = {ReactDOMRe.Style.make(
    ~border="1px solid #aaaaaa", 
    ~maxWidth="80vw", 
    ~maxHeight="80vh", 
    () )};  

let tags = {ReactDOMRe.Style.make(
    ~border="1px solid #aaaaaa", 
    ~margin="2px",
    ~position="center",
    ~fontSize="5vw",
    ~textAlign="right",
//    ~wordBreak="break-all",
     () )};  


let modal = {ReactDOMRe.Style.make(
/* The Modal (background) */
    ~display="block", /* Hidden by default */
    ~position="fixed",  /* Stay in place */
    ~zIndex="1", /* Sit on top */
    ~left="0",
    ~top="0",
    ~width="100%", /* Full width */
    ~height="100%", /* Full height */
    ~overflow="auto", /* Enable scroll if needed */
//    ~backgroundColor="rgb(0,0,0)", /* Fallback color */
    ~backgroundColor="rgba(0,0,0,0.4)", /* Black w/ opacity */
    () )};
let non_modal = {ReactDOMRe.Style.make(
/* The Modal (background) */
    ~display="none", /* Hidden by default */
    ~position="fixed",  /* Stay in place */
    ~zIndex="1", /* Sit on top */
    ~left="0",
    ~top="0",
    ~width="100%", /* Full width */
    ~height="100%", /* Full height */
    ~overflow="auto", /* Enable scroll if needed */
//    ~backgroundColor="rgb(0,0,0)", /* Fallback color */
    ~backgroundColor="rgba(0,0,0,0.4)", /* Black w/ opacity */
    () )};

// let modal_content = {ReactDOMRe.Style.make(
//     // /* Modal Content/Box */
//     ~backgroundColor="#fefefe",
//     ~margin="15% auto",  /* 15% from the top and centered */
//     ~padding="20px", 
//     ~border="1px solid #888",
//     ~width="80%", /* Could be more or less, depending on screen size */
//     () )};
let modal_content = {ReactDOMRe.Style.make(
    // /* Modal Content/Box */
    ~display="block", /* Hidden by default */
    ~margin="auto",  /* 15% from the top and centered */
 //   ~maxWidth="700px",
    ~width="100%", /* Could be more or less, depending on screen size */
    () )};

let modal_close = {ReactDOMRe.Style.make(
    /* The Close Button */
    ~color="#aaa",
    ~float="right",
    ~fontSize="28px", 
    ~fontWeight="bold",
    () )};

let modal_hover_focus = {ReactDOMRe.Style.make(
    ~color="black",
    ~textDecoration="none",
    ~cursor="pointer",
    () )};



let image2 = {ReactDOMRe.Style.make(
    ~width="20%", /* Full width */
    ~height="20%", /* Full height */
    ~maxWidth="20%", 
    ~maxHeight="20%", 
    () )};  

// let modal2 = {ReactDOMRe.Style.make(
// /* The Modal (background) */
//     ~display="block", /* Hidden by default */
//     ~position="fixed",  /* Stay in place */
//     ~zIndex="1", /* Sit on top */
//     ~left="0",
//     ~top="0",
//     ~width="100%", /* Full width */
//     ~height="100%", /* Full height */
//     ~overflow="auto", /* Enable scroll if needed */
// //    ~backgroundColor="rgb(0,0,0)", /* Fallback color */
//     ~backgroundColor="rgba(0,0,0,0.4)", /* Black w/ opacity */
//     () )};
// let non_modal2 = {ReactDOMRe.Style.make(
// /* The Modal (background) */
//     ~display="none", /* Hidden by default */
//     ~position="fixed",  /* Stay in place */
//     ~zIndex="1", /* Sit on top */
//     ~left="0",
//     ~top="0",
//     ~width="100%", /* Full width */
//     ~height="100%", /* Full height */
//     ~overflow="auto", /* Enable scroll if needed */
// //    ~backgroundColor="rgb(0,0,0)", /* Fallback color */
//     ~backgroundColor="rgba(0,0,0,0.4)", /* Black w/ opacity */
//     () )};


let modal_close2 = {ReactDOMRe.Style.make(
    /* The Close Button */
    ~position="absolute",
    ~top="15px",
    ~right="35px",
    ~color="#f1f1f1",
    ~float="bottom",
    ~fontSize="40px", 
    ~fontWeight="bold",
    () )};

//   position: absolute;
//   top: 15px;
//   right: 35px;
//   color: #f1f1f1;
//   font-size: 40px;
//   font-weight: bold;
//   transition: 0.3s;
