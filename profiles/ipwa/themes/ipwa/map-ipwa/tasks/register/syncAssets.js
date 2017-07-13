/**
 * `syncAssets`
 *
 * ---------------------------------------------------------------
 *
 * This Grunt tasklist is not designed to be used directly-- rather
 * it is a helper called by the `watch` task (`tasks/config/watch.js`).
 *
 * For more information see:
 *   http://sailsjs.org/documentation/anatomy/my-app/tasks/register/sync-assets-js
 *
 */

'use strict';

module.exports = function (grunt) {
  grunt.registerTask('syncAssets', [
    /* validation*/
    'eslint',
    'scsslint',

    'compass:dev',
    'sync',

    /* concatenation JS */
    'concat:vendorsJs',
    'concat:js',
    'concat:css'
  ]);
};
