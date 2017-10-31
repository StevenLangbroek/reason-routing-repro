[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let stringEl = ReasonReact.stringToElement;

let make = (~router, _children) => {
  let gotoTargets = (event) => {
    ReactEventRe.Mouse.preventDefault(event);
    DirectorRe.setRoute(router, "/targets");
  };
  {
    ...component,
    render: (_self) =>
      <div className="App">
        <div className="App-header">
          <img src=logo className="App-logo" alt="logo" />
        </div>
        <p className="App-intro">
          (stringEl("To get started, edit"))
          <code> (stringEl(" src/App.re ")) </code>
          (stringEl("and save to reload."))
        </p>
        <p>
          <a href="#" onClick=gotoTargets>(stringEl("Go to Targets"))</a>
        </p>
      </div>
  }
};