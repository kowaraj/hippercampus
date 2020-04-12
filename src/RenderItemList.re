// let str = ReasonReact.string;

// type state = {
//     count: int
// };

// type item = {
//     url: string, 
//     id: int, 
//     name: string
// };

// type action = 
//   | Check;

// [@react.component]
// let make = (~items) => {
//     let (_state, _dispatch) = React.useReducer( (state, action) => 
//     switch (action) { 
//     | Check => {count: state.count + 1}
//     },
//     {count: 0});

//     <div>
//        {str("dump of the database...")} <br /> 

//         <div className="items-list-files">
//         (
//             List.map(
//                 (zi : Decode.f) => {
//                     let i : RenderItem2.item = { url: Config.url_be_root++"/uploads/" ++ zi.fn, id: zi.id, name: zi.name};
//                     <RenderItem2 key=string_of_int(zi.id) item=i />
//                 },
//                 items)
//             |> Array.of_list
//             |> React.array
//         )
//         </div>
//     </div>
// };