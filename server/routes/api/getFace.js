var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');
var Face = keystone.list('Face');

exports = module.exports = function(req, res){
	//console.log(req);
	
	console.log('getFace');
	console.log(req.user)
	var slug = req.params.face;
	Face.model.find()
		.where('slug',slug)
		//.populate('user')
		.sort('createdAt')
		.limit(2)
		.exec(function(err, face) {
			if(err){
				console.log(err);
			}
			console.log(face);
			face = face[0];
			face.image = undefined;
			face.price = undefined;
			face.status = undefined;
			face.updatedAt = undefined;
			face.updatedBy = undefined;
			face.user = undefined;
			face.image = undefined;
			var toJSON = {
				name : face.name,
				fml : face.fml,
				slug : face.slug
			};
			console.log(toJSON);
			res.send(JSON.stringify(toJSON));
		});
}