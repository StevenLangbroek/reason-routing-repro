let component = ReasonReact.statelessComponent("ErrorPage");

let stringEl = ReasonReact.stringToElement;

let make = (_children) => {
    ...component,
    render: (_self) => {
        <div>(stringEl("Whoopsie!"))</div>
    }
}