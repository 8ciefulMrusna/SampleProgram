// �G�N�X�|�[�g�ƃC���|�[�g�̐؂�ւ�
#ifdef MYLIBAPI // VC_DLL_EXPORTS �ł���������

// DLL��PJ�ł�MYLIBAPI���g�p���Ċ֐����G�N�X�|�[�g�B

#else

// EXE��(DLL�𗘗p����)PJ�ł�MYLIBAPI���C���|�[�g�B
// extern "C" �́A���̌��ꂩ��Ăԏꍇ�ɕK�v�B
#define MYLIBAPI extern "C" __declspec(dllimport)

#endif

// �ȉ��A�G�N�X�|�[�g�֐��̃v���g�^�C�v�錾
// �ʏ�A__stdcall��K�p����(__stdcall = WINAPI)�B
MYLIBAPI void __stdcall Test_MYLIBAPI(LPCWSTR lpText, LPCWSTR lpCaption);

// ���̕������ƁAC4603�AC4273�̌x�����o�邪�A���͂Ȃ��B

// �EC4603�F'<identifier>': �}�N������`����Ă��Ȃ����A
//          �v���R���p�C���ς݃w�b�_�[���g�p���Ă����`�Ƃ͈قȂ�܂��B

// �EC4273�Fdll �����N����т��Ă��܂���B
