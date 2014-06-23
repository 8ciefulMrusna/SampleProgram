// ClassTest.cpp : CClassTest �̎���

#include "stdafx.h"
#include "ClassTest.h"

// ���Q�l�T�C�g��
// COM������Ďg���i���ȒP��FVC�ō쐬�AVBS�Ŏ��s�j
// http://www.dinop.com/vc/com003.html
// �yVC++�z COM �̍쐬�̊�{
// http://maglog.jp/lightbox/Article437075.html
// ATL �ō쐬���� Active X �R���g���[���̃T���v��
// http://www.koutou-software.co.jp/junk/atl-actxctrl-sample.html
// COM - Hirotake Itoh's memo by PukiWiki
// http://aki.issp.u-tokyo.ac.jp/itoh/PukiWiki/pukiwiki.php?COM

// ATL �ō쐬���� Active X �R���g���[���̃T���v��
// http://www.koutou-software.co.jp/junk/atl-actxctrl-sample.html
// �i�R���g���[�������S�ł���ƃ}�[�L���O�FIObjectSafety�j

#include "atlstr.h"

// CClassTest

STDMETHODIMP CClassTest::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IClassTest
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CClassTest::MethodTest(BSTR bstrText, BSTR bstrCaption, BSTR* rtnval)
{
	// TODO: �����Ɏ����R�[�h��ǉ����Ă��������B

	// BSTR��OLECHAR�i= WCHAR�j�̃|�C���^
	// typedef OLECHAR FAR * BSTR;
	// http://msdn.microsoft.com/ja-jp/site/ms221069

	// Web/DB �v���O���~���O�O����
	// Windows �O���� > COM+ �̘b�� > BSTR �Ƃ́H
	// http://keicode.com/com/bstr-alloc-free.php

	// CAtlString�FCSimpleString���p������
	// �e���v���[�g�N���X CStringT �����̉�������
	// http://myoga.web.fc2.com/prog/cpplib/shared01.htm

	CAtlString casText;
	CAtlString casCaption;
	
	// CStringT::operator =
	// http://msdn.microsoft.com/ja-jp/library/wxeexhs7.aspx
	casText = (WCHAR*)bstrText;
	casCaption = (WCHAR*)bstrCaption;

	// VB��Err.Raise�I�ȁB
	if(casCaption == L"")
	{
		return Error(TEXT("bstrCaption����ł��B"));
	}

	// CAtlString �� LPTSTR
	// CSimpleStringT::operator PCXSTR
	// http://msdn.microsoft.com/ja-jp/library/tk1z2hd9.aspx
	MessageBox(NULL, casText, casCaption, MB_OK);
	
	// rtnval��COM��retval

	// How to pass BSTR* as the return value
	// from the ATL\COM application to vb6.0 application.
	// http://social.msdn.microsoft.com/Forums/en/vclanguage/thread/0cbb0f96-5d2d-43e9-a9c4-86af905cfe0f

	// SysAllocString��OLECHAR�i= WCHAR�j�̃|�C���^��Ԃ��B
	// http://msdn.microsoft.com/ja-jp/site/ms221458
	*rtnval = SysAllocString( L"�����I" );

	return S_OK;
}
