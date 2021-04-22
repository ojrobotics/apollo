# Running Google Maps in Navigation mode - Dreamview

* First you need to have a Google Maps Platforms API key: `https://developers.google.com/maps/documentation`.
* Follow the instructions in 4.1 at (https://github.com/ApolloAuto/apollo/blob/master/docs/howto/how_to_use_apollo_2.5_navigation_mode.md). 
* Change `map: "BaiduMap"` to `map: "GoogleMap"`
* In the `mapAPiUrl`: replace the url with this one `"https://maps.googleapis.com/maps/api/js?key=YOUR_API_KEY&callback=initMap"`.
`
