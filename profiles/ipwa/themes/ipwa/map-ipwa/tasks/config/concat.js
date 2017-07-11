/**
 * `concat`
 *
 * ---------------------------------------------------------------
 *
 * Concatenates the contents of multiple JavaScript and/or CSS files
 * into two new files, each located at `concat/production.js` and
 * `concat/production.css` respectively in `.tmp/public/concat`.
 *
 * This is used as an intermediate step to generate monolithic files
 * that can then be passed in to `uglify` and/or `cssmin` for minification.
 *
 * For usage docs see:
 *   https://github.com/gruntjs/grunt-contrib-concat
 *
 */

'use strict';

module.exports = function (grunt) {
  grunt.config.set('concat', {

    vendorsJs: {
      src: require('../pipeline').jsVendorsToInject,
      dest: 'dist/concat/vendors.js'
    },
    js: {
      src: require('../pipeline').jsFilesToInject,
      dest: 'dist/concat/production.js'
    },
    css: {
      src: require('../pipeline').cssFilesToInject,
      dest: 'dist/concat/production.css'
    }

  });

  grunt.loadNpmTasks('grunt-contrib-concat');
};
