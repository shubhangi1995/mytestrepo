/**
 * `watch`
 *
 * ---------------------------------------------------------------
 *
 * Run predefined tasks whenever watched file patterns are added, changed or deleted.
 *
 * Watch for changes on:
 * - files in the `assets` folder
 * - the `tasks/pipeline.js` file
 * and re-run the appropriate tasks.
 *
 * For usage docs see:
 *   https://github.com/gruntjs/grunt-contrib-watch
 *
 */

'use strict';

module.exports = function (grunt) {
  grunt.config.set('watch', {
    main: {
      // Assets to watch:
      files: ['src/**/*'],

      // When assets are changed:
      tasks: ['syncAssets']
    }
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
};
