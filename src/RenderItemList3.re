let str = ReasonReact.string;

type state = {
    count: int
};

type item = {
    url: string, 
    id: int, 
    name: string
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
        <div style=StyleRenderItem3.list>
        (
            List.map(
                (zi : Decode.meme_t) => {
                    let i : RenderItem3.item = { url: Config.url_be_root++"/uploads/" ++ zi.fn, id: zi.id, name: zi.name};
                    <RenderItem3 key=string_of_int(zi.id) item=i />
                },
                items)
            |> Array.of_list
            |> React.array
        )
        </div>
    </div>
};