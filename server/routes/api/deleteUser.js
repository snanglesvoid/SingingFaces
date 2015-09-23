var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');

exports = module.exports = function(req, res){
	//console.log(req);

	var User = keystone.list('User');

	User.model.findById(req.params.userId)
    .remove(function(err) {
        // user has been deleted
        res.sendStatus(200);
        console.log('API: Deleted user "'+req.params.userId+'"');
    });
}