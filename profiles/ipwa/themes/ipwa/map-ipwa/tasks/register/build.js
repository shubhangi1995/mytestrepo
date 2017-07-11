/**
 * `buildProd`
 *
 * ---------------------------------------------------------------
 *
 * This Grunt tasklist will be executed instead of `build` if you
 * run `sails www` in a production environment, e.g.:
 * `NODE_ENV=production sails www`
 *
 * This generates a folder containing your compiled (and usually minified)
 * assets.  The most common use case for this is bundling up files to
 * deploy to a CDN.
 *
 * For more information see:
 *   http://sailsjs.org/documentation/anatomy/my-app/tasks/register/build-prod-js
 *
 */

'use strict';

module.exports = function (grunt) {
  grunt.registerTask('build', [
    'clean',

    /* validation */
    'eslint',
    'scsslint',

    /* compass + copy */
    'compass:prod', // from scss to css
    'copy', // everything exept css

    /* concatenation */
    'concat:vendorsJs',
    'concat:js',
    'concat:css',

    /* uglify/minimification*/
    'uglify',
    'cssmin'
  ]);
};
