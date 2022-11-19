var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://127.0.0.1:27017/";
var data = require('./data.json');

const dbName = 'DB'
let db

MongoClient.connect(url, { useNewUrlParser: true }, (err, client) => {
  if (err) return console.log(err)

  // Storing a reference to the database so you can use it later
  db = client.db(dbName)

  console.log(`Connected MongoDB: ${url}`)
  console.log(`Database: ${dbName}`)
  
  db.collection('users').insertMany(data,(err,db_res) =>{
      console.log('Data added!');
      console.log(db_res);
      db.collection("users").find(
        {'name':'Олег'},
        { projection: {} }
      ).toArray(function(err, result) {
        if (err) throw err;
        console.log(result);
    });

     db.collection('users').find(
       {'city' : 'Луцьк'},
       { projection: { _id: 0 } }
     ).toArray(function(err, result) {
      if (err) throw err;
      console.log(result);
      //db.close();
  });
  });
});
