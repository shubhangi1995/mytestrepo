/**
 * `uglify`
 *
 * ---------------------------------------------------------------
 *
 * Minify client-side JavaScript files using UglifyJS.
 *
 * For usage docs see:
 *   https://github.com/gruntjs/grunt-contrib-uglify
 *
 */
module.exports = function(grunt) {

  grunt.config.set('uglify', {

    main: {
      src: ['dist/concat/production.js'],
      dest: 'dist/min/production.min.js'
    },

  });

  grunt.loadNpmTasks('grunt-contrib-uglify');
};
