/**
 * grunt/pipeline.js
 *
 * The order in which your css, javascript, and template files should be
 * compiled and linked from your views and static HTML files.
 *
 * (Note that you can take advantage of Grunt-style wildcard/glob/splat expressions
 * for matching multiple files.)
 *
 * For more information see:
 *   https://github.com/balderdashy/sails-docs/blob/master/anatomy/myApp/tasks/pipeline.js.md
 */

'use strict';

// CSS files to inject in order
//
// (if you're using LESS with the built-in default config, you'll want
//  to change `assets/styles/importer.less` instead.)

// Project Engagement Map
//---------------------------------------------------------------------------------------------------------------
// CSS files to inject in order
var cssFilesToInject = [
  // Document Ready Starter
  'css/vendors/ol.css',
  'css/main.css'
];

// Client-side javascript files to inject in order
var jsVendorsToInject = [
  // All of the rest of your client-side js files
  // will be injected here in no particular order.
  'js/vendors/**/*.js'
];

var jsFilesToInject = [
  // All of the rest of your client-side js files
  // will be injected here in no particular order.
  'js/main.js',
  'js/components/**/*.js',
  'js/data/europeTopojson.js'
];

// Prefix relative paths to source files so they point to the proper locations
// (i.e. where the other Grunt tasks spit them out, or in some cases, where
// they reside in the first place)
module.exports.cssFilesToInject = cssFilesToInject.map(function (path) {
  return 'dist/' + path;
});
module.exports.jsVendorsToInject = jsVendorsToInject.map(function (path) {
  return 'src/' + path;
});
module.exports.jsFilesToInject = jsFilesToInject.map(function (path) {
  return 'src/' + path;
});
