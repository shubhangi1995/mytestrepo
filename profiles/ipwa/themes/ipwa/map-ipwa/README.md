Installation
Installation on the environment in Windows

1.	Install last stable version of node.js (https://nodejs.org/en/)
2.	Install Grunt.js: Open up Windows Command Prompt and put in the command below: 
npm install grunt-cli -g 
This will put the grunt command in your system path, allowing it to be run from any directory.
3.	In order to use SASS or (SCSS) we need Compass. In order to use Compass we need Ruby and Compass
a.	Install Ruby http://rubyinstaller.org/ 
b.	Install SASS (more info � but not necessary to read: http://sass-lang.com/install): open Command Prompt und write:
gem install sass 
c.	Install Compass: Open Command Prompt und write:
gem install compass  
4.	Install node inside the project. Go to the project under folder map-ipwa and write 
npm install
The module node_modules will be added to the current folder. It contains all the modules which are needed to the execute different tasks (like clean all files, uglify the code, convert the sass/scss into css, etc)
5. install scss-lint is a tool to help keep your SCSS files clean and readable 
gem install scss-lint


