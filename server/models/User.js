var keystone = require('keystone');
var Types = keystone.Field.Types;

/**
 * User Model
 * ==========
 */

var User = new keystone.List('User', {
	autokey : { path:'slug', from:'name', unique:true },
	track : { createdAt:true, updatedAt:true }
});

User.add({
	name 		: { type: Types.Name, required: true, index: true },
	email 		: { type: Types.Email, initial: true, required: true, index: true },
	password 	: { type: Types.Password, initial: true, required: true },
	faces 		: { type: Types.Relationship, ref: 'Face', many: true},
	credits		: { type: Types.Number, default: 10 },
	location	: { type: Types.Location }, //verify
	language	: { type: String, default: 'en-US' } // verify
}, 'Permissions', {
	isAdmin		: { type: Boolean, label: 'Can access Keystone', index: true }
});

// Provide access to Keystone
User.schema.virtual('canAccessKeystone').get(function() {
	return this.isAdmin;
});

//User.schema.methods.getFaces = function(callback){
//	this.populate('faces', function (err, doc) {
//  		callback(doc);
//	});
//}

/**
 * Relationships
 */

User.relationship({ ref: 'Post', path: 'posts', refPath: 'author' });
User.relationship({ ref: 'Face', path: 'faces', refPath: 'User' });


/**
 * Registration
 */

User.defaultColumns = 'name, email, isAdmin';
User.register();
