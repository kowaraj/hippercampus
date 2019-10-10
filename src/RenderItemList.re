let str = ReasonReact.string;

type state = {
    count: int
};

type item = {
    url: string, 
    id: int
};

type action = 
  | Check;

[@react.component]
let make = (~items) => {
    let (_state, _dispatch) = React.useReducer( (state, action) => 
    switch (action) { 
    | Check => {count: state.count + 1}
    },
    {count: 0});

    <div>
       {str("LIST of FETCHED items")} <br /> 

        <div className="items-list-files">
        (
            List.map(
                (zi : Decode.f) => {
                    let i : RenderItem2.item = { url: "http://localhost:3003/uploads/" ++ zi.fn, id: zi.id};
                    <RenderItem2 key=string_of_int(zi.id) item=i />
                },
                items)
            |> Array.of_list
            |> React.array
        )
        </div>
    </div>
};