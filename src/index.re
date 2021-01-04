[@bs.val] external document: Js.t({..}) = "document";

let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= Styles.style;

ReactDOMRe.renderToElementWithId(<App />, "app-root");