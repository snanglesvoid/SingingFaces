var keystone = require('keystone');

exports = module.exports = function(req, res) {
	
	var view = new keystone.View(req, res);
	var locals = res.locals;
	
	// Set locals
	locals.section = 'profile';
	locals.filters = {
		user: req.params.user
	};
	locals.data = {
		faces: []
	};
	console.log(locals.filters.user);

	view.on('init', function(next) {
		
		var q = keystone.list('User').model.findOne({
			slug: locals.filters.user
		}).populate('faces');
		
		q.exec(function(err, result) {
			user = result;
			next(err);
		});
	});		

	
	
	// Load other faces
	view.on('init', function(next) {
		
		var q = keystone.list('Face').model.find()
			.where('user', locals.filters.user)
			.sort('plays')
			.populate('user').limit('4');
		
		q.exec(function(err, results) {
			locals.data.faces = results;
			next(err);
		});
		
	});
	console.log(locals.data);
	// Render the view
	view.render('profile');
	
};
