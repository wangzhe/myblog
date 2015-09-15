// db.getCollection('restaurants').find({})

// db.restaurants.find().count()
// db.restaurants.find( { "borough": "Manhattan" } )
// db.restaurants.find( { "address.zipcode": "10075" } )
// db.restaurants.find( { "zipcode": "10075" } )  //must follow the data hierarchy structure
// db.restaurants.find( { "grades.grade": "B" } )
// db.restaurants.find( { "grades.score": { $lt: 10 } } )
db.restaurants.find().sort( { "borough": 1, "address.zipcode": 1 } )

// db.restaurants.insert(
//    {
//       "address" : {
//          "street" : "2 Avenue",
//          "zipcode" : "10075",
//          "building" : "1480",
//          "coord" : [ -73.9557413, 40.7720266 ],
//       },
//       "borough" : "Manhattan",
//       "cuisine" : "Italian",
//       "grades" : [
//          {
//             "date" : ISODate("2014-10-01T00:00:00Z"),
//             "grade" : "A",
//             "score" : 11
//          },
//          {
//             "date" : ISODate("2014-01-16T00:00:00Z"),
//             "grade" : "B",
//             "score" : 17
//          }
//       ],
//       "name" : "Vella",
//       "restaurant_id" : "41704620"
//    }
// )