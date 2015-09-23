var keystone = require('keystone');
var _        = require('underscore');
var async    = require('async');

exports = module.exports = function(req, res){
	console.log('API: Save face');

	// Require body.face for input
	var f = req.body.face;
	if (f._id){
	keystone.list('Face').model.find()
		.where('_id', p._id)
		.exec(function(err, faces){
			if (err) res.send(404);
			var pdb = faces[0];
			pdb.set(f);
			pdb.set({user:req.user._id});
			pdb.save();
			//console.log(pdb);
			res.send(pdb);
		})
	}
	else{
		//console.log('creating new face');
		var PM = keystone.list('Face').model;
		var pdb = new PM();
		pdb.set(f);
		pdb.set({user:req.user._id});
		req.user.faces.push(pdb._id);
		req.user.save();
		//console.log(pdb);
		pdb.save();
		res.send(pdb);
	}
}