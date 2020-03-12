let h = {ReactDOMRe.Style.make(~border="2px solid #ffdddd", ~padding="1rem", ~margin="1px", ~width="fit-content", () )};

let h_component = {ReactDOMRe.Style.make(
    ~border="2px solid #5555dd", 
    ~padding="0.2rem", 
    ~margin="0.2px", 
    ~width="fit-content", 
    () )};

let h_meme = {ReactDOMRe.Style.make(
    ~border="3px solid #ffdddd", 
    //~padding="0.3rem", 
    //~margin="0.3px", 
    ~width="fit-content", 
    () )};

let h_meme_url = {ReactDOMRe.Style.make(
    ~maxWidth="200px", 
    ~maxHeight="200px", 
    () )};  

let h_meme_fetch = {ReactDOMRe.Style.make(
    ~width="150px", 
    () )};  

let h_tone_slider_wrapper = {ReactDOMRe.Style.make(
    ~width="20px", 
    ~height="300px", 
    () )};  

let h_tone_slider = {ReactDOMRe.Style.make(
    ~width="300px", 
    ~height="20px", 
    ~transformOrigin="10px 10px",
    ~transform="rotate(90deg)",
    () )};      
