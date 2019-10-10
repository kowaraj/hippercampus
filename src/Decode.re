type f  = {
    id: int,
    name: string, 
    fn: string, 
    tags: list(string)
    };

let file_decoder = file_json => {
    Json.Decode.{
        id: field("id", Json.Decode.int, file_json),
        name: field("name", string, file_json),
        fn: field("fn", string, file_json),
        tags: field("tags", list(string), file_json)
    }

}

let files = json => {
    Js.log("Decode.files: json source is: <commented out>")
    //Js.log(json);
    Json.Decode.list(file_decoder, json);
}


