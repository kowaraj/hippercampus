type f  = {
    fn: string, 
    tags: list(string)
    };

let file_decoder = file_json => {
    Json.Decode.{
        fn: field("fn", string, file_json),
        tags: field("tags", list(string), file_json)
    }

}

let files = json => {
    Js.log("Decode.files: json source is: <commented out>")
    //Js.log(json);
    Json.Decode.list(file_decoder, json);
}


