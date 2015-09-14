/**
 * This file is where you define your application routes and controllers.
 * 
 * Start by including the middleware you want to run for every request;
 * you can attach middleware to the pre('routes') and pre('render') events.
 * 
 * For simplicity, the default setup for route controllers is for each to be
 * in its own file, and we import all the files in the /routes/views directory.
 * 
 * Each of these files is a route controller, and is responsible for all the
 * processing that needs to happen for the route (e.g. loading data, handling
 * form submissions, rendering the view template, etc).
 * 
 * Bind each route pattern your application should respond to in the function
 * that is exported from this module, following the examples below.
 * 
 * See the Express application routing documentation for more information:
 * http://expressjs.com/api.html#app.VERB
 */

var keystone = require('keystone');
var middleware = require('./middleware');
var importRoutes = keystone.importer(__dirname);

// Common Middleware
keystone.pre('routes', middleware.initLocals);
keystone.pre('render', middleware.flashMessages);

// Import Route Controllers
var routes = {
	views: importRoutes('./views'),
	api:  importRoutes('./api')
};

// Setup Route Bindings
exports = module.exports = function(app) {
	
	// Views
	app.get('/', routes.views.index);
	app.get('/blog/:category?', routes.views.blog);
	app.get('/blog/post/:post', routes.views.post);
	app.get('/gallery', routes.views.gallery);
	app.all('/contact', routes.views.contact);
	
	// API
	app.post('/api/createUser', routes.api.createUser);
	app.get('/api/getUser/:user', routes.api.getUser);
	app.post('/api/saveUser/:user', routes.api.saveUser);
	app.post('/api/deleteUser/:user', routes.api.deleteUser);
	app.get('/api/getFaces/:user?', routes.api.getFaces); // List faces for a specific user or all
	app.post('/api/createFace', middleware.requireUser, routes.api.createFace);
	app.get('/api/getFace/:face', middleware.requireUser, routes.api.getFace);
	app.post('/api/saveFace/:face', middleware.requireUser, routes.api.saveFace);
	app.post('/api/deleteFace/:face', middleware.requireUser, routes.api.deleteFace);
	app.get('/api/getFavorites', middleware.requireUser, routes.api.getFavorites);
	app.post('/api/addFavorite', middleware.requireUser, routes.api.addFavorite);

	// NOTE: To protect a route so that only admins can see it, use the requireUser middleware:
	// app.get('/protected', middleware.requireUser, routes.views.protected);
	
};
