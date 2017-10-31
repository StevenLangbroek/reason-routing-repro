open Webapi;

[%bs.raw {|require('./index.css')|}];

[@bs.module "./registerServiceWorker"] external registerServiceWorker : unit => unit = "default";

type routes =
    | HomeRoute
    | TargetsRoute
    | ErrorRoute;
    /* | DeploymentTargetRoute(string); */

let router = DirectorRe.makeRouter({
    "/": "home",
    "/targets": "deploymentTargets",
    "/*": "errorPage"
    /* "/targets/:deploymentTargetId": "deploymentTarget" */
});

let renderForRoute = (route) => {
    let element = switch route {
      | HomeRoute => <Home router=router />
      | TargetsRoute => <Targets router=router />
      | ErrorRoute => <ErrorPage />
    };
    ReactDOMRe.renderToElementWithId(element, "root");
  };

let handlers = {
    "home": () => {
        renderForRoute(HomeRoute);
    },
    "deploymentTargets": () => {
        renderForRoute(TargetsRoute);
    },
    "errorPage": () => {
        renderForRoute(ErrorRoute);
    }
};

registerServiceWorker();

DirectorRe.configure(router, {
    "resource": handlers
});

DirectorRe.init(router, Webapi.Dom.Location.hash(Dom.location));