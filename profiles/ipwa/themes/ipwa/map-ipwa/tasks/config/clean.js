/**
 * `clean`
 *
 * ---------------------------------------------------------------
 *
 * Remove the files and folders in your Sails app's web root
 * (conventionally a hidden directory called `.tmp/public`).
 *
 * For usage docs see:
 *   https://github.com/gruntjs/grunt-contrib-clean
 *
 */

'use strict';

module.exports = function (grunt) {
  grunt.config.set('clean', {
    build: ['dist']
  });

  grunt.loadNpmTasks('grunt-contrib-clean');
};
