// �ȒP�ȕ����i�����I���[�h���K�v�j
// BridgeDLL.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

// �� char��String�^�ϊ�
// http://homepage1.nifty.com/MADIA/vc/vc_bbs/200604/200604_06040016.html

// C++-CLI Tips  �����񑀍�
// http://vene.wankuma.com/prog/CppCli_strings.aspx

// ���@: System::String �� wchar_t* �܂��� char* �ɕϊ�����
// http://msdn.microsoft.com/ja-jp/library/d1ae6tz5.aspx

// Visual C++ �� SystemString ���� char �ɕϊ�������@
// http://support.microsoft.com/kb/311259/ja

#include "stdafx.h"

// convert_string_to_wchar.cpp
// compile with: /clr
#include < vcclr.h > // managed C++ ����� vcclr.h

// VisualStudio 2008 �ɂȂ��āAC++/CLI �ł� marshal_as<> �����p�ł���悤�ɂȂ�܂����B
// ����͑g�ݍ��݊֐��ł��� marshal_as ���Z�q�ƃ}�[�V�������O�E�I�u�W�F�N�g marshal_context ���쐬���A
// �l�C�e�B�u�E�f�[�^�̐������Ԃ��Ǘ����� marshal �I�u�W�F�N�g�ɂ���č\������Ă��܂��B

// marshal_as
// http://msdn.microsoft.com/ja-jp/library/bb384859.aspx
// marshal_context �N���X
// http://msdn.microsoft.com/ja-jp/library/bb384854.aspx

// marshal_as, marshal_context - Schima�̓��L
// http://d.hatena.ne.jp/Schima/20090422#1240359965

using namespace System;
using namespace TargetAssembly;

extern "C"{

	// �����I���[�h��VC�ADOTNET����g�p����̂Ńw�b�_�[�t�@�C���͕s�v
	// �Ȃ��A__cdecl�ł�DOTNET���琳�����Ăяo���邱�Ƃ��m�F���Ă���B
	// �ʏ�A__stdcall��K�p����(__stdcall = WINAPI)�B
	__declspec(dllexport) LPCWSTR __stdcall TestMethod(LPCWSTR message);

	LPCWSTR __stdcall TestMethod(LPCWSTR message){

		// LPCWSTR��System::String�iGC�Ώہj
		String^ gc_message = gcnew String( message );

		// .NET�̃N���X�𐶐�����B
		TargetClass^ obj = gcnew TargetClass();

		// .NET�̃��\�b�h���Ăяo���B
		String^ gc_return = obj->MessageBox_Show(gc_message);
		
		// �ݗ��̊֐����Ă΂��ԂɁAGC�������
		// �ړ������邱�Ƃ��ł��Ȃ��悤�ɁA���������s���ŗ��߁B
		pin_ptr<const wchar_t> wc_return = PtrToStringChars(gc_return);

		// pin_ptr����������΁A�s�����O���gc_return��GC����锤�B
		return wc_return;
	}
}