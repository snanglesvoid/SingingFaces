var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');

exports = module.exports = function(req, res){
	// Get for a specific user
	console.log(req);
	var user = req.params.user;
	user.populate('faces', function (err, doc) {
		if (err) console.log(err);
		res.send(JSON.stringify(doc.faces));
	});	
}