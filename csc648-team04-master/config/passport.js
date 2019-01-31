/***** PASSPORT CONFIG FILE *****/

var LocalStrategy   = require('passport-local').Strategy;
var mysql = require('mysql');
var bcrypt = require('bcrypt-nodejs');

var creds = {

    host: "us-cdbr-iron-east-05.cleardb.net",
    user: "b3220b75dccc0a",
    password: "ddd8323b",
    database: "heroku_d6fcf8fd2312a32"

};

var connection = mysql.createPool(creds);


/**
 * This is where the passport strategy "local-login" lives, which authenticates a user when they log in.
 * Upon logging in, the strategy first checks that their credentials are valid, then uses serializeUser to store their user_id.
 * deserializeUser then uses this id to select the row from the database and store the object in our session to use. \
 * @param passport
 */
module.exports = function(passport) {

    passport.serializeUser(function(user, done) {
        done(null, user.user_id);
    });

    passport.deserializeUser(function(username, done) {
        connection.query("SELECT * FROM user WHERE user_id = ? ",[username], function(err, rows){
            done(err, rows);
        });
    });

    passport.use(
        'local-login',
        new LocalStrategy({
                usernameField : 'username',
                passwordField : 'password',
                passReqToCallback : true
            },
            function(req, username, password, done) {
                connection.query("SELECT * FROM user WHERE user_id = ?",[username], function(err, rows){
                    //console.log(rows[0]);
                    if (err)
                        return done(err);
                    if (!rows.length) {
                        return done(null, false, req.flash('loginMessage', 'Invalid Username or Password'));
                    }

                    // if the user is found but the password is wrong
                    if (!bcrypt.compareSync(password, rows[0].password))
                        return done(null, false, req.flash('loginMessage', 'Invalid Username or Password.')); // create the loginMessage and save it to session as flashdata

                    // all is well, return successful user
                    return done(null, rows[0],req.flash('loginMessage', 'Welcome, ' + rows[0].user_id));
                });
            })
    );
};
