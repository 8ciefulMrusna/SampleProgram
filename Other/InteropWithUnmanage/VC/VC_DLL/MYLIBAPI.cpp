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