// ���̃\�[�X�R�[�h�̊֐��ƕϐ����G�N�X�|�[�g
#define MYLIBAPI extern "C" __declspec(dllexport)

#include <stdafx.h>
#include <windows.h>
#include <stdio.h>

// �G�N�X�|�[�g�֐��̐錾
#include "MYLIBAPI.h"

// �ȉ��A�G�N�X�|�[�g�֐��̎���
// �ʏ�A__stdcall��K�p����(__stdcall = WINAPI)�B
void __stdcall Test_MYLIBAPI(LPCWSTR lpText, LPCWSTR lpCaption)
{
	// MessageBox���Ăяo�������B
	MessageBox(NULL, lpText, lpCaption, MB_OK);
}