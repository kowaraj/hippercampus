let container = {ReactDOMRe.Style.make(
    ~border="3px solid #ffdddd", 
    ~padding="0rem", 
    ~margin="0px", 
    ~width="fit-content", 
    () )};

let name = {ReactDOMRe.Style.make(
    ~position="center",
    () )};  

let text = {ReactDOMRe.Style.make(
    ~position="left",
    () )};  

let image = {ReactDOMRe.Style.make(
    ~maxWidth="100%", 
    ~maxHeight="100%", 
    () )};  

let tags = {ReactDOMRe.Style.make(
    ~position="left",
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

let modal_content = {ReactDOMRe.Style.make(
    // /* Modal Content/Box */
    ~backgroundColor="#fefefe",
    ~margin="15% auto",  /* 15% from the top and centered */
    ~padding="20px", 
    ~border="1px solid #888",
    ~width="80%", /* Could be more or less, depending on screen size */
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
