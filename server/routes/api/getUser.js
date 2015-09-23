var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');

exports = module.exports = function(req, res){
	//console.log(req);
		if(!req.params.user){
		slug = res.user.slug;
	} else {
		slug = req.params.user;
	}
	console.log('API: Get user "'+slug+'":');

	var q = keystone.list('User');

	q.model.findOne({
		slug: slug
	})
		.exec(function(err, result) {
			if(!err){
				res.send(JSON.stringify(result));
				console.log(result);
			}
			else {
				console.log('User does not exist!'+stringify(result)+stringify(err));
			}
		});
}