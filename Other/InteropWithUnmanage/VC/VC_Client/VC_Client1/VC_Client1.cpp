// VC_Client1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <windows.h>
#include "../../VC_DLL/MYLIBAPI.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// �ʏ��Lib���g�p����DLL�֐��̌Ăяo�����@�B
	Test_MYLIBAPI(L"text", L"caption");

	return 0;
}