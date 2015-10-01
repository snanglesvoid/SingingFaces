var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');
var Face = keystone.list('Face');

exports = module.exports = function(req, res){
	if(!req.params.faceId){
		console.log('API: faceId missing');
	} else {
		var faceId = req.params.faceId;
		console.log('API: Get face '+faceId);
	}
	
	
	Face.model.findById(faceId)
		.exec(function(err, face) {
			if(err){
				console.log(err);
			}
			console.log(face);
			res.send(JSON.stringify(face));	
		});
}