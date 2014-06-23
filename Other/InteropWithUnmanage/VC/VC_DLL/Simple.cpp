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

// �ȒP�ȕ����i�����I���[�h���K�v�j
// VC_DLL.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B

#include "stdafx.h"
#include <stdio.h>

// �ȉ��́A
// The try, catch, and throw Statements
// http://msdn.microsoft.com/en-us/library/6dekhbbc(VS.80).aspx
// ������p

class CTest {
public:
   CTest() {};
   ~CTest() {};
   const char *ShowReason() const { 
      return "Exception in CTest class."; 
   }
};

extern "C"{
	typedef struct _A{
		int m1;
		char m2_in[12]; // 11�����܂� (MarshalAs(UnmanagedType.ByValTStr, SizeConst=12)
	 	char m3_out[48]; // 47�����܂� (MarshalAs(UnmanagedType.ByValTStr, SizeConst=48)
	} A;

	// �����I���[�h��VC�ADOTNET����g�p����̂Ńw�b�_�[�t�@�C���͕s�v
	// �Ȃ��A__cdecl�ł�DOTNET���琳�����Ăяo���邱�Ƃ��m�F���Ă���B
	// �ʏ�A__stdcall��K�p����(__stdcall = WINAPI)�B
	__declspec(dllexport) int __stdcall TestArrayMethod(A a, A *pa, int len, A aa[]);

	int __stdcall TestArrayMethod(A a, A *pa, int len, A aa[]){

		// �z��̒�����0�����͂��肦�Ȃ��̂�
		// ��O�𔭍s����(C++�̗�O�𔭍s���Ă݂�)
		if(len < 0){
			throw CTest();
		} // extern "c" �Ōx�����\�������i__cdecl�ł�__stdcall�ł��j�B

		// �l�n���̍\���� a
		char *p_inputmessage = a.m2_in;
		int counter = a.m1;

		// �Q�Ɠn���̍\���� *pa�i�\���� a ����R�s�[�j
		pa->m1 = ++counter; // ��� ++ ���Ă�����
		sprintf_s(pa->m3_out, 47, "%s by pa->", p_inputmessage);

		// �Q�Ɠn���̍\���̔z�� aa[]�i�\���� a ����R�s�[�j
		int i;
		for (i = 0; i < len; i++){
			aa[i].m1 = ++counter; // ��� ++ ���Ă�����
			sprintf_s(aa[i].m3_out, 47, "%s by aa[%d].", p_inputmessage, i);
		}

		return counter;
	}
}
