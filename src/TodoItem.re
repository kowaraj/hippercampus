let str = ReasonReact.string;

type todoitem = {
    id: int,
    title: string,
    completed: bool
};
    [@react.component]
    let make = (~item) => {
    <div 
        className="item"
        onClick=((_evt) => ())>

        <input 
            type_="checkbox"
            checked=(item.completed)
            onChange=((evt) => ())
        />
        (str(item.title))
    </div>
    
   };
