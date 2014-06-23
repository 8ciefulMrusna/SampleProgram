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

// ClassTest.h : CClassTest �̐錾

#pragma once
#include "resource.h"       // ���C�� �V���{��

#include "VC_COM_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM �̊��S�T�|�[�g���܂�ł��Ȃ� Windows Mobile �v���b�g�t�H�[���̂悤�� Windows CE �v���b�g�t�H�[���ł́A�P��X���b�h COM �I�u�W�F�N�g�͐������T�|�[�g����Ă��܂���BATL ���P��X���b�h COM �I�u�W�F�N�g�̍쐬���T�|�[�g���邱�ƁA����т��̒P��X���b�h COM �I�u�W�F�N�g�̎����̎g�p�������邱�Ƃ���������ɂ́A_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ���`���Ă��������B���g�p�� rgs �t�@�C���̃X���b�h ���f���� 'Free' �ɐݒ肳��Ă���ADCOM Windows CE �ȊO�̃v���b�g�t�H�[���ŃT�|�[�g�����B��̃X���b�h ���f���Ɛݒ肳��Ă��܂����B"
#endif

// ATL �ō쐬���� Active X �R���g���[���̃T���v��
// http://www.koutou-software.co.jp/junk/atl-actxctrl-sample.html
// �i�R���g���[�������S�ł���ƃ}�[�L���O�FIObjectSafety�j

// CClassTest

class ATL_NO_VTABLE CClassTest :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CClassTest, &CLSID_ClassTest>,
	public ISupportErrorInfo,
	public IDispatchImpl<IClassTest, &IID_IClassTest, &LIBID_VC_COMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<CClassTest, INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA> // IObjectSafety�Ή��Œǉ�
{
public:
	CClassTest()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CLASSTEST)


BEGIN_COM_MAP(CClassTest)
	COM_INTERFACE_ENTRY(IClassTest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IObjectSafety) // IObjectSafety�Ή��Œǉ�
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(MethodTest)(BSTR bstrText, BSTR bstrCaption, BSTR* rtnval);
};

OBJECT_ENTRY_AUTO(__uuidof(ClassTest), CClassTest)
