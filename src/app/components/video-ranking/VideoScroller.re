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
let make = (~channel) => {
  <div className="row flex-row flex-nowrap video-container">
    {
      switch (VideoQuery.use({channel: channel})) {
      | {loading: true} => "Loading..."->React.string
      | {error: Some(_error)} => "Error loading data"->React.string
      | {data: Some({videos})} =>
          videos
          ->Belt.Array.map(video =>
            <div className="col-3 d-flex align-items-stretch video-element-container">
              <div className="card card-block">
                <img src={video.thumbnail} className="card-img-top" alt="..." />
                <div className="card-body">
                  <p className="card-text">{React.string(video.title)}</p>
                </div>
              </div>
            </div>
          )
          ->React.array
      | {data: None, error: None, loading: false} => "Something went wrong!"->React.string
      };
    }
  </div>;
};