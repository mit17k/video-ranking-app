// module ApolloQueryResult = ApolloClient.Types.ApolloQueryResult;
// module ObservableQuery = ApolloClient.Types.ObservableQuery;

module VideoQuery = [%graphql
  {|
    query Video ($channel: String!) {
      videos(order_by: [{position: asc}], where: {channel: {_eq: $channel}}) {
        id
        channel
        position
        thumbnail
        title
        url
      }
    }
  |}
];

[@react.component]
let make = () => {
  <div className="video-container">
  {
    switch (VideoQuery.use({channel: "theRadBrad"})) {
    | {loading: true} => "Loading..."->React.string
    | {error: Some(_error)} => "Error loading data"->React.string
    | {data: Some({videos})} =>
        videos
        ->Belt.Array.map(video =>
          <div className="video-element" key={string_of_int(video.id)}>
            <img src={video.thumbnail} />
            {React.string(video.title)}
          </div>
        )
        ->React.array
    | {data: None, error: None, loading: false} => "Something went wrong!"->React.string
    };
  }
  </div>;
};