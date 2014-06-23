//**********************************************************************************
//* Copyright (C) 2007,2014 Hitachi Solutions,Ltd.
//**********************************************************************************

//#region Apache License
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License. 
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//#endregion

// VC_Client2.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// DLL�̃n���h��
	HMODULE hModule;

	// �R�[���o�b�N�֐��̒�`
	void (__stdcall *func) (LPCWSTR, LPCWSTR);

	// LoadLibrary���g�p����DLL�֐��̌Ăяo�����@�B

	// LoadLibrary��DLL�����[�h
	hModule = LoadLibrary( _T("VC_DLL.dll") );

	if( hModule == NULL )
	{
		// ���[�h�Ɏ��s�iDLL�����݂��Ȃ��j
		MessageBox(NULL, L"VC_DLL.dll��������܂���", L"�G���[", MB_OK);
	}
	else
	{
		// DLL���̊֐��̃A�h���X���擾����iDEF�t�@�C���ɏ��������O�ŌĂׂ�j
		func = (void (__stdcall *)(LPCWSTR, LPCWSTR))GetProcAddress( hModule, "Test_MYLIBAPI" );
		
		if( func != NULL )
		{
			// �擾�����A�h���X���o�R���ČĂяo��
			func(L"text", L"caption");
		}
		
		// ���[�h����DLL�����
		FreeLibrary( hModule );
	}

	return 0;
}

