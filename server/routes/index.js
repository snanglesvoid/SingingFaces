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
	auth: importRoutes('./auth'),
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
	app.get('/u/:user?', routes.views.profile);

	// Session
    app.all('/join', routes.views.session.join);
    app.all('/signin', routes.views.session.signin);
    app.get('/signout', routes.views.session.signout);
    app.all('/forgot-password', routes.views.session['forgot-password']);
    app.all('/reset-password/:key', routes.views.session['reset-password']);

    // Authentication
    app.all('/auth/confirm', routes.auth.confirm);
    app.all('/auth/confirmApp', routes.auth.confirmApp);
    //app.all('/auth/app', routes.auth.app);
    app.all('/auth/:service', routes.auth.service);
	
	// API
	app.all('/api/createUser', routes.api.createUser); // combine and or compare to join
	app.all('/api/saveUser/:user', routes.api.saveUser); 

	app.all('/api/getUser/:user?', routes.api.getUser);
	app.all('/api/deleteUser/:userId', routes.api.deleteUser); // done

	app.all('/api/getFaces/:user?', routes.api.getFaces); // done
	app.all('/api/getFace/:faceId', routes.api.getFace); // done
	app.all('/api/saveFace', routes.api.saveFace); // done save & create
	app.all('/api/deleteFace/:faceId', routes.api.deleteFace); // done

	// NOTE: To protect a route so that only admins can see it, use the requireUser middleware:
	// app.get('/protected', middleware.requireUser, routes.views.protected);
	
};
