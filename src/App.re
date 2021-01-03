[@react.component]
let make = () => {
  <ApolloClient.React.ApolloProvider client=Client.instance>
    <Video />
  </ApolloClient.React.ApolloProvider>
};
