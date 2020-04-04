type f  = {
    id: int,
    name: string, 
    text: string, 
    fn: string, 
    tags: list(string)
    };

type meme_t  = {
    id: int,
    name: string, 
    text: string, 
    fn: string, 
    tags: list(string)
    };

let file_decoder = file_json => {
    Json.Decode.{
        id: field("id", Json.Decode.int, file_json),
        name: field("name", string, file_json),
        text: field("text", string, file_json),
        fn: field("fn", string, file_json),
        tags: field("tags", list(string), file_json)
    }

}

let meme_decoder = meme_json => {
    let decoded_meme : meme_t = Json.Decode.{
        id: field("id", Json.Decode.int, meme_json),
        name: field("name", string, meme_json),
        text: field("text", string, meme_json),
        fn: field("fn", string, meme_json),
        tags: field("tags", list(string), meme_json)
    }
    decoded_meme
}

let files = json => {
    //Js.log("Decode.files: json source is: <commented out>")
    //Js.log(json);
    Json.Decode.list(file_decoder, json);
}

let meme = json => {
    Js.log("Decode.files: json source is: <commented out>")
    Js.log(json);
    let decoded_meme_list : list(meme_t) = Json.Decode.list(meme_decoder, json);
    decoded_meme_list
}