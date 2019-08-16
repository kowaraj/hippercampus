let str = ReasonReact.string;

type meme = {
    name: string,
    url: string
}

type xx = 
    | YesX
    | NoX;

let x = YesX;

let memes = switch (x) { 
    | NoX => None
    | YesX => Some([ {name: "a", url: "aa"}, {name: "b", url: "bb"}]);
};

let fetchMemes = () => {
    Js.Promise.(
        memes|> resolve
    )
};

type state = 
    | NotAsked
    | Loading
    | Failure
    | Success(list(meme));

type action = 
    | Load
    | LoadFailed
    | Display(list(meme));

[@react.component]
let make = () => {
    let (ss, dispatch) = 
    React.useReducer( (state, action) => 
        switch (action) { 
        | Load => 
            ReasonReact.UpdateWithSideEffects(
            Loading,
            ( self => Js.Promise.
                (
                    fetchMemes()
                    |> then_(result =>
                        switch (result) {
                        | Some(memes) => resolve(self.send(Display(memes)))
                        | None => resolve(self.send(LoadFailed))
                        }
                        )
                    |> ignore
                )
            ),
        )
        | LoadFailed => ReasonReact.Update(Failure)
        | Display(memes) => ReasonReact.Update(Success(memes))
        }, 
        ReasonReact.Update(NotAsked)
    );


    <div>
        {
            str("Not asked")}
    </div>

};



// [@react.component]
// let make = () => {
//     let (ss, dispatch) = 
//     React.useReducer( (state, action) => 
//         switch (action) { 
//         | Load => 
//             ReasonReact.UpdateWithSideEffects(
//             Loading,
//             ( self => Js.Promise.
//                 (
//                     fetchMemes()
//                     |> then_(result =>
//                         switch (result) {
//                         | Some(memes) => resolve(self.send(Display(memes)))
//                         | None => resolve(self.send(LoadFailed))
//                         }
//                         )
//                     |> ignore
//                 )
//             ),
//         )
//         | LoadFailed => ReasonReact.Update(Failure)
//         | Display(memes) => ReasonReact.Update(Success(memes))
//         }, 
//         ReasonReact.Update(NotAsked)
//     );


//     <div>
//         {str("Not asked")}
//         // { switch state {
//         //     | NotAsked => <div> {str("Not asked")}</div>
//         //     | Loading => <div> {str("Not asked")}</div>
//         //     | Failure => <div> {str("Not asked")}</div>
//         //     | Success(memes) => <div> {str("Not asked")}</div>
//         //     };
//         // };
//     </div>

// };
