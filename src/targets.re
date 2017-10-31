[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("DeploymentTargets");

[@bs.module] external logo : string = "./logo.svg";

let stringEl = ReasonReact.stringToElement;

let make = (~router, _children) => {
    let gotoFaultyRoute = (event) => {
        ReactEventRe.Mouse.preventDefault(event);
        DirectorRe.setRoute(router, "/404");
    };
    {
        ...component,
        render: (_self) => 
            <div className="App">
            <div className="App-header">
                <img src=logo className="App-logo" alt="logo" />
            </div>
            <p className="App-intro">
                (stringEl("DeploymentTargets"))
                <a href="#" onClick=gotoFaultyRoute>(stringEl("Faulty Route"))</a>
            </p>
            </div>
    }
}