//list of types

// Type of an item in the Meme list
type item = {
    url: string, 
    id: string, 
    name: string
};

// Type of the Meme in a Firestore database
type fs_meme_t  = {
    id: string,
    name: string, 
    text: string, 
    fn: string, 
    tags: list(string)
    };

let default_meme  = {
    id: "noid",
    name: "noname",
    text: "notext", 
    fn: "nofn", 
    tags: ["notags"]
    };    

type new_meme_t  = {
    .
    "name": string, 
    "text": string, 
    "fn": string, 
    "tags": string
};
