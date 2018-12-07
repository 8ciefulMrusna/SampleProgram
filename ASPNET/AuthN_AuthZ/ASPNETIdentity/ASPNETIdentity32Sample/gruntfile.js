module.exports = function (grunt) {
    grunt.initConfig({
        // package.json�t�@�C�����̃v���p�e�B�̒l���Q�Ƃ���
        pkg: grunt.file.readJSON('package.json'),
        // �e�^�X�N�̍\�����`
        // package.json �� scripts ���� "grunt cssmin" �ȂǂŌĂяo����B
        copy: {
            bundle: {
                files: [
                    {
                        expand: true, src: ['**'],
                        cwd: 'node_modules/jquery/dist/',
                        dest: 'wwwroot/lib/jquery/dist/'
                    },
                    {
                        expand: true, src: ['**'],
                        cwd: 'node_modules/jquery-validation/dist/',
                        dest: 'wwwroot/lib/jquery-validation/dist/'
                    },
                    {
                        expand: true, src: ['**'],
                        cwd: 'node_modules/jquery-validation-unobtrusive/dist/', 
                        dest: 'wwwroot/lib/jquery-validation-unobtrusive/dist/'
                    },
                    {
                        expand: true, src: ['**'],
                        cwd: 'node_modules/bootstrap/dist/',
                        dest: 'wwwroot/lib/bootstrap/dist/'
                    },
                    {
                        expand: true, src: ['**'],
                        cwd: 'node_modules/font-awesome/css/',
                        dest: 'wwwroot/lib/font-awesome/css/'
                    },
                    {
                        expand: true, src: ['**'],
                        cwd: 'node_modules/font-awesome/fonts/',
                        dest: 'wwwroot/fonts/'
                    }
                ]
            }
        }
    });
    // �K�v��Grunt�v���O�C����ǂݍ��ށB
    grunt.loadNpmTasks('grunt-contrib-copy');
    // �e�^�X�N��g�������J�X�^�� �^�X�N��o�^����B
    // package.json �� scripts ���� "grunt bundle" �ŌĂяo����B
    grunt.registerTask('bundle', ['copy']);
};