// CallerEXE.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// DLL�̃n���h��
	HMODULE hModule;

	// �R�[���o�b�N�֐��̒�`
	LPCWSTR (__stdcall *func) (LPCWSTR);

	// LoadLibrary���g�p����DLL�֐��̌Ăяo�����@�B

	// LoadLibrary��DLL�����[�h
	hModule = LoadLibrary( _T("BridgeDLL.dll") );

	if( hModule == NULL )
	{
		// ���[�h�Ɏ��s�iDLL�����݂��Ȃ��j
		MessageBox(NULL, L"BridgeDLL.dll��������܂���", L"�G���[", MB_OK);
	}
	else
	{
		// DLL���̊֐��̃A�h���X���擾����iDEF���g�p���Ă��Ȃ��̂Łj
		func = (LPCWSTR (__stdcall *)(LPCWSTR))GetProcAddress( hModule, "_TestMethod@4" );

		if( func != NULL )
		{
			// �擾�����A�h���X���o�R���ČĂяo��
			MessageBox(NULL, func(L"�A���}�l�[�W����}�l�[�W�I�I�I"), L"�߂�l", MB_OK);
		}
		
		// ���[�h����DLL�����
		FreeLibrary( hModule );
	}

	return 0;
}

