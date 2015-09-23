var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');

exports = module.exports = function(req, res){
	// Set locals
	var locals = res.locals;
	locals.filters = {
		user: req.params.user
	};
	locals.data = {
		faces: []
	};
	if(req.params.user == ''){ 
		locals.filters.user = req.user.slug;
	}

	console.log('API: Get faces for user "' + locals.filters.user + '":');

	var q = keystone.list('User');

	q.model.findOne({
		slug: locals.filters.user
	})
		.populate('faces')
		.exec(function(err, result) {
			if(!err){
				res.send(JSON.stringify(result.faces));
			}
			else {
				console.log('User does not exist!'+stringify(result)+stringify(err));
			}
		});
}