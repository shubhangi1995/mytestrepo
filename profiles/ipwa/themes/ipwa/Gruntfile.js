
module.exports = function (grunt) {
    grunt.initConfig({
        watch: {
            src: {
                files: ['**/*.scss'],
                tasks: ['sass:dev']
            },
            options: {
                livereload: true,
            },
        },
        //compass: {
        //    dev: {
        //        options: {
        //            sassDir: 'custom-sass',
        //            cssDir: 'css',
        //            imagesPath: 'assets/img',
        //            noLineComments: false,
        //            outputStyle: 'compressed'
        //        }
        //    }
        //},
        sass: {
            options: {
                sourcemap: false,
                precision: 8,
                lineNumbers: true
            },
            dev: {
                files: [{
                    expand: 'expanded',
                    check: false,
                    update: false,
                    cwd: './scss',
                    src: ['*.scss'],
                    dest: './css',
                    ext: '.css'
                }]
            }
        }
        // todo: Create a task for production (sass: dist).
    });
    grunt.loadNpmTasks('grunt-contrib-compass');
    grunt.loadNpmTasks('grunt-contrib-sass');
    grunt.loadNpmTasks('grunt-contrib-watch');
};
