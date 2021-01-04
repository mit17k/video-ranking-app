[@react.component]
let make = () => {
  <ApolloClient.React.ApolloProvider client=Client.instance>
    <Header />
    <Video />
  </ApolloClient.React.ApolloProvider>
};
