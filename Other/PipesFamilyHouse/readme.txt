���̃A�v���P�[�V������
�i�R���\�[���j��Parent.exe�́i�����p�C�v�̓��o�́j��Child.exe
�Ԃœ����p�C�v���g�p�����v���Z�X�ԒʐM�����܂��B

�EStdIOAndPipe
�@RedirectStandardXXXX��true�ɐݒ肵�A
�@�q�v���Z�X�ł�Console�o�R�Ŏg�p�B

�EAnonymousPipe
�@AnonymousPipeXXXXStream�𒼐ڎg�p����B

�q�v���Z�X�iChild.exe�j�Ƀf�o�b�K��
�A�^�b�`�iDebug�j����ꍇ�͉��L���Q�ƁB

�E���@ : �f�o�b�K�������I�ɋN������
�@http://msdn.microsoft.com/ja-jp/library/a329t4ed(v=vs.80).aspx
�E���Y�^ Image File Execution Options
�@http://limejuicer.blog66.fc2.com/blog-entry-18.html


���p�������

�E�V�F���F�R���\�[��
�@�iCUI�̃R�}���h�j
�@
�E�W�����o�́F�v���Z�X�ɕW���I�ɗp�ӂ����R�̓��o�͐�
�@�E�W�����́iC�����scanf�AWin32��ReadFile�ȂǂŁu�ǂݎ��v�j
�@�E�W���o�́iC�����printf�AWin32��WriteFile�ȂǂŁu�������݁v�j
�@�E�W���G���[�o�́i�W���o�͂Ɠ����A�n���h�������قȂ�j
�@
�@�EGetStdHandle �֐�
�@�@http://msdn.microsoft.com/ja-jp/library/cc429347.aspx
�@�@�R���\�[���ւ̓��o�́i�V�F���j���K�v�ȃA�v���P�[�V�����ŗ��p�B
�@�@�ESTD_INPUT_HANDLE�F�W�����̓n���h��
�@�@�ESTD_OUTPUT_HANDLE�F�W���o�̓n���h��
�@�@�ESTD_ERROR_HANDLE�F�W���G���[�n���h��
�@
�@�@��L���A�q�v���Z�X�N�����A
�@�@STARTUPINFO�\���̂ɐݒ肷��B
�@
�@�ESTARTUPINFO structure (Windows)
�@�@http://msdn.microsoft.com/ja-jp/library/ms686331.aspx
�@�@�EHANDLE hStdInput;
�@�@�EHANDLE hStdOutput;
�@�@�EHANDLE hStdError;
�@�@
�@�EPROCESS_INFORMATION structure (Windows)
�@�@http://msdn.microsoft.com/ja-jp/library/ms684873.aspx
�@�@
�E���_�C���N�g�F�W�����o�͂̕t���ւ����w���B
�@�i��L�̃n���h�����R���\�[�� �� �t�@�C���A�����p�C�v�ȂǂƕύX�j
�@
�@
���Q�l�iC����ł̎����j��

�R���\�[�� �v���Z�X�𐶐�����
�W���n���h�������_�C���N�g������@
http://support.microsoft.com/kb/190351/ja

�@�E�e��
�@�@�E�q�v���Z�X�Ƀf�[�^���o�͉\�ȓ����p�C�v�i�p���\�j
�@�@�@hOutputReadTmp�i�e�v���Z�X�Ŏg��Tmp�j�AhOutputWrite�i�q�v���Z�X�ɓn���j
�@�@�@
�@�@�E�q�v���Z�X����f�[�^����͉\�ȓ����p�C�v�i�p���\�j
�@�@�@hInputRead�i�q�v���Z�X�ɓn���j�AhInputWriteTmp�i�e�v���Z�X�Ŏg��Tmp�j
�@�@�@
�@�@�E�e�v���Z�X�Ŏg�������p�C�v�E�n���h��
�@�@�@�E�p���s�̃R�s�[���쐬�iDuplicateHandle�j�B
�@�@�@�@�EhOutputRead
�@�@�@�@�EhInputWrite
�@�@�@�ETmp���N���[�Y����iCloseHandle�j�B
�@�@�@�@�EhOutputReadTmp
�@�@�@�@�EhInputWriteTmp
�@�@�@
�@�@�E�q�v���Z�X�ɓn�������p�C�v�E�n���h��
�@�@�@�ESTARTUPINFO�\���̂ɐݒ肵�Ďq�v���Z�X���N���B
�@�@�@�E�n���h�����N���[�Y����B
�@�@�@�@�EhOutputWrite
�@�@�@�@�EhInputRead
�@�@�@�@
�@�@�EhOutputRead�F�W�����́iC�����scanf�AWin32��ReadFile�Ȃǁj
�@�@�EhInputWrite�F�W���o�́iC�����printf�AWin32��WriteFile�Ȃǁj
�@�@
�@�E�q��
�@�@�EhOutputWrite�F�W�����́iC�����scanf�AWin32��ReadFile�Ȃǁj
�@�@�EhInputRead�F�W���o�́iC�����printf�AWin32��WriteFile�Ȃǁj
�@�@
�ECreatePipe �֐�
�@http://msdn.microsoft.com/ja-jp/library/cc429801.aspx
�@���O�Ȃ��p�C�v���쐬���A���̃p�C�v��
�@�ǎ摤�Ə������̗����̃n���h�����擾����B
�@�i���͑��Əo�͑����̃n���h��������j
�@
�EDuplicateHandle �֐�
�@http://msdn.microsoft.com/ja-jp/library/cc429766.aspx
�@�I�u�W�F�N�g�n���h���̕������쐬����B
�@�E�n���h�����v���Z�X�Ԃŋ��L������ꍇ
�@�E�A�N�Z�X���̈Ⴄ�n���h�����쐬����ꍇ
�@�ɗ��p���邱�Ƃ��ł���B