var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');

exports = module.exports = function(req, res){
	//console.log(req.params);
	if(!req.params.faceId){
		console.log('API: faceId missing');
	} else {
		var Face = keystone.list('Face');
	
		Face.model.findById(req.params.faceId)
	    .remove(function(err) {
	        // post has been deleted
	        res.sendStatus(200);
	        console.log('API: Deleted face "'+req.params.faceId+'"');
	    });
	}


}