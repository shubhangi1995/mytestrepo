module.exports = function(grunt) {
  grunt.config.set('compass', {
    options: {
      require: 'susy',
      fontsDir: 'src/',
      imagesDir: 'src/'
    },

    // Engagement Map Website
    // ---------------------------------------------------------------------------------------------------------------
    dev: {
      options: {
        sassDir: 'src/scss',
        cssDir: 'dist/css',
        environment: 'development',
        outputStyle: 'expanded',
        sourcemap: true
      }
    },

    prod: {
      options: {
        sassDir: 'src/scss',
        cssDir: 'dist/css',
        environment: 'production',
        outputStyle: 'compressed',
        debugInfo: false,
        sourcemap: false,
        noLineComments: true
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-compass');
};
