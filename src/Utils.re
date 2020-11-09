
// Take: List of strings - tags of a meme
// Return: Comma separated string
let list2str : list(string) => string = ls => {
    Js.String2.make( Js.List.toVector(ls) )
}

let mlist2str : list(TT.fs_meme_t) => string = ls => {
    Js.String2.make( Js.List.toVector(ls) )
}

let mlist2jsonstr : list(TT.fs_meme_t) => string = list_of_memes => {
    let list_of_jsonstr = Js.Json.stringifyAny(list_of_memes)
    Js.String2.make(list_of_jsonstr)
}

let oRIGINAL_marray2jsonstr : array(TT.fs_meme_t) => string = array_of_memes => {
    Js.log("Original array of memes:")
    Js.log(array_of_memes)
    let array_of_jsonstr = Js.Json.stringifyAny(array_of_memes)
    //Js.log(array_of_jsonstr)
    Js.String2.make(array_of_jsonstr)
}

    // id: string,
    // name: string, 
    // text: string, 
    // fn: string, 
    // tags: list(string)
let marray2jsonstr : array(TT.fs_meme_t) => string = array_of_memes => {

    let f = (acc_array, m : TT.fs_meme_t) => {
        let dict = Js.Dict.empty()
        Js.Dict.set(dict, "id", Js.Json.string(m.id))
        Js.Dict.set(dict, "name", Js.Json.string(m.name))
        Js.Dict.set(dict, "text", Js.Json.string(m.text))
        Js.Dict.set(dict, "fn", Js.Json.string(m.fn))
        Js.Dict.set(dict, "tags", Js.Json.stringArray(Array.of_list(m.tags)))

        Array.appendappend(dict)
        dict
    Js.Array.reduce( 
        },
        Array.make(),
        array_of_memes);



    //Js.log(array_of_jsonstr)
    Js.String2.make(array_of_jsonstr)
}

let is_in = (el, set) => {
    // String.trim(tag_of_a_meme) - to remove white spaces
    List.exists( i => String.trim(i) == el, set)
}

let is_subset = (subset, set) => {
    List.for_all( el => is_in(el, set), subset);
}

// Take: List of memes, List of selected tags
// Return: List of memes whose tags contain all of the selected tags
let filter_data_by_tags = (memes, sel_tags) => {
    switch (List.length(sel_tags)) {
    | 0 => memes
    | _ => List.filter( (m : TT.fs_meme_t) =>  is_subset(sel_tags, m.tags), memes)
    }
}

// Take: List of memes
// Return: List of all the unique tags 
let extract_all_tags = memes => {
    let tags = List.fold_left( 
                    (extracted_tags, (meme: TT.fs_meme_t)) => {
                                                List.append(extracted_tags, meme.tags)
                    }, [], memes)
    //Re::String::trim - The characters regarded as whitespace are: ' ', '\012', '\n', '\r', and '\t'. If 
    let tags_peeled = List.map( tag => String.trim(tag), tags)
    let tags_u = List.sort_uniq( (t1,t2) => compare(t1,t2), tags_peeled)
    //Js.log(tags_u |> Array.of_list)
    tags_u
}
