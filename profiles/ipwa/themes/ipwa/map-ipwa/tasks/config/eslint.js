/**
 * Validate files with ESLint.
 *
 * ---------------------------------------------------------------
 *
 * For usage docs see:
 * https://www.npmjs.com/package/grunt-eslint
 *
 * package: https://github.com/airbnb/javascript/tree/master/packages/eslint-config-airbnb-base (not connect to react)
 * example of configuration file https://github.com/eslint/eslint/blob/master/conf/eslint.json
 * rules: http://eslint.org/docs/rules/
 * use rules from AirBnb but simplified that based on: http://blog.javascripting.com/2015/09/07/fine-tuning-airbnbs-eslint-config/
 * configure http://eslint.org/docs/user-guide/configuring
 */

'use strict';

module.exports = function (grunt) {
  grunt.config.set('eslint', {
    main: [
      'src/js/components/**/*.js',
      'src/js/main.js'
    ]
  });

  grunt.loadNpmTasks('grunt-eslint');
};
