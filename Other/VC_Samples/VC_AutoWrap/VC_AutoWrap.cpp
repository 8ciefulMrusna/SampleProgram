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

// VC_AutoWrap.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B

#include "stdafx.h"
#include "atlstr.h"

#include <locale.h> 

//////////////////////////////////////////////////////////////////////////////////////////////////
// AutoWrap() - Automation helper function...�iIDispatch::Invoke�Ń��C�g�o�C���h����j
////////////////////////////////////////////////////////////////////////////////////////////////// 
// [HOWTO] Visual C++ ���g�p���ăI�[�g���[�V�����ŕ����v���p�e�B�ɃA�N�Z�X������@
// http://support.microsoft.com/kb/238393/ja
////////////////////////////////////////////////////////////////////////////////////////////////// 
HRESULT AutoWrap(int autoType, VARIANT *pvResult, IDispatch *pDisp, LPOLESTR ptName, int cArgs...) 
{

	// Begin variable-argument list...
	va_list marker;
	va_start(marker, cArgs);

	if(!pDisp) {
		printf("NULL IDispatch passed to AutoWrap\n");
		//MessageBox(NULL, "NULL IDispatch passed to AutoWrap()", L"Error", 0x10010);
		_exit(0);
	}

	// Variables used...
	DISPPARAMS dp = { NULL, NULL, 0, 0 };
	DISPID dispidNamed = DISPID_PROPERTYPUT;
	DISPID dispID;
	HRESULT hr;
	char buf[200];
	char szName[200];
   
	// Convert down to ANSI
	WideCharToMultiByte(CP_ACP, 0, ptName, -1, szName, 256, NULL, NULL);
   
	// Get DISPID for name passed...
	hr = pDisp->GetIDsOfNames(IID_NULL, &ptName, 1, LOCALE_USER_DEFAULT, &dispID);

	if(FAILED(hr)) {
		sprintf(buf, "IDispatch::GetIDsOfNames(\"%s\") failed w/err0x%08lx", szName, hr);
		//MessageBox(NULL, buf, "AutoWrap()", 0x10010);
		_exit(0);
		return hr;
	}
   
	// Allocate memory for arguments...
	VARIANT *pArgs = new VARIANT[cArgs+1];
	// Extract arguments...
	for(int i=0; i<cArgs; i++) {
		pArgs[i] = va_arg(marker, VARIANT);
	}
   
	// Build DISPPARAMS
	dp.cArgs = cArgs;
	dp.rgvarg = pArgs;
   
	// Handle special-case for property-puts!
	if(autoType & DISPATCH_PROPERTYPUT) {
		dp.cNamedArgs = 1;
		dp.rgdispidNamedArgs = &dispidNamed;
	}
   
	// Make the call!
	hr = pDisp->Invoke(dispID, IID_NULL, LOCALE_SYSTEM_DEFAULT, autoType, &dp, pvResult, NULL, NULL);
	
	if(FAILED(hr)) {
		sprintf(buf, "IDispatch::Invoke(\"%s\"=%08lx) failed w/err 0x%08lx", szName, dispID, hr);
		//MessageBox(NULL, buf, "AutoWrap()", 0x10010);
		_exit(0);
		return hr;
	}

	// End variable-argument section...
	va_end(marker);
   
	delete [] pArgs;
   
	return hr;
}

// 
//////////////////////////////////////////////////////////////////////////////////////////////////
// _tmain()
////////////////////////////////////////////////////////////////////////////////////////////////// 
// VC_AutoWrap.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//////////////////////////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	// TODO: �����Ɏ����R�[�h��ǉ����Ă��������B

	// http://cx5software.com/article_vcpp_unicode/
	// OS�̃f�t�H���g���P�[��
	_tsetlocale(LC_ALL, _T(""));
	
	// printf�̃e�X�g
	printf("Hello World!\n"); 
	printf("����ɂ��͐��E!\n");
	printf("%s\n", argv[1]); 
	wprintf(L"%s\n", argv[1]); 
	_tprintf(_T("%s\n"), argv[1]);

	// Initialize COM for this thread...
    CoInitialize(NULL);

    // Get CLSID for Word.Application...
    CLSID clsid;
    HRESULT hr = CLSIDFromProgID(L"Excel.Application", &clsid);
    
	if(FAILED(hr)) {
      //::MessageBox(NULL, "CLSIDFromProgID() failed", "Error", 0x10010);
      return -1;
    }
    
	// Start Excel and get IDispatch...
    IDispatch *pDisp;
    hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_IDispatch, (void **)&pDisp);

    if(FAILED(hr)) {
      //::MessageBox(NULL, "Word not registered properly", "Error", 0x10010);
      return -2;
    }

	//----------------------------------------------------------------------------------------------------

	// �v���p�e�B�iset�j�Ăяo���iExcel.Application.DisplayAlerts�j
    {
		// ����
		VARIANT x;
		x.vt = VT_BOOL;
		x.boolVal = VARIANT_FALSE;
		
		// DisplayAlerts�v���p�e�B�̐ݒ�
		AutoWrap(DISPATCH_PROPERTYPUT, NULL, pDisp, L"DisplayAlerts", 1, x);
	}
	
	// �v���p�e�B�iget�j�Ăяo���iExcel.Application.Workbooks�j
	IDispatch *pWorkbooks;
    {
		// �߂�l
		VARIANT result;
		VariantInit(&result);
		
		// Workbooks�v���p�e�B�̎擾
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDisp, L"Workbooks", 0);
		pWorkbooks = result.pdispVal;
    }

	// ���\�b�h�Ăяo���iExcel.Application.Workbooks.Open�j
	{
		// ����
		VARIANT x;
		x.vt = VT_BSTR;
		BSTR _bstr = SysAllocString((OLECHAR *)argv[1]);
		x.bstrVal = _bstr;

		// �߂�l
		VARIANT result;
		VariantInit(&result);

		// Open���\�b�h�̌Ăяo��
		AutoWrap(DISPATCH_METHOD, &result, pWorkbooks, L"Open", 1, x);

		SysFreeString(_bstr);
	}

	// �v���p�e�B�Ăяo���iExcel.Application.ActiveWorkbook�j
	IDispatch *pActiveWorkbook;
    {
		// �߂�l
		VARIANT result;
		VariantInit(&result);

		// ActiveWorkbook�v���p�e�B�̎擾
		AutoWrap(DISPATCH_PROPERTYGET, &result, pDisp, L"ActiveWorkbook", 0);
		pActiveWorkbook = result.pdispVal;
    }

	// ���\�b�h�Ăяo���iExcel.Application.ActiveWorkbook.SaveAs�j
	{
		// ����
		VARIANT x1;
		x1.vt = VT_BSTR;
		BSTR _bstr = SysAllocString((OLECHAR *)argv[2]);
		x1.bstrVal = _bstr;
		
		VARIANT x2;
		x2.vt = VT_INT;
		x2.intVal = -4143;

		VARIANT x3;
		x3.vt = VT_BSTR;
		x3.bstrVal = L"test";

		// �߂�l
		VARIANT result;
		VariantInit(&result);

		// SaveAs���\�b�h�̌Ăяo��
		AutoWrap(DISPATCH_METHOD, &result, pActiveWorkbook, L"SaveAs", 3, x3, x2, x1);

		SysFreeString(_bstr);
	}

	// �v���p�e�B�Ăяo���iExcel.Application.DisplayAlerts�j
    {
		// ����
		VARIANT x;
		x.vt = VT_BOOL;
		x.boolVal = VARIANT_TRUE;

		// DisplayAlerts�v���p�e�B�̐ݒ�
		AutoWrap(DISPATCH_PROPERTYPUT, NULL, pDisp, L"DisplayAlerts", 1, x);
    }

	// ���\�b�h�Ăяo���iExcel.Application.Quit�j
	{
		// ����
		VARIANT result;
		VariantInit(&result);

		// Quit���\�b�h�̌Ăяo��
		AutoWrap(DISPATCH_METHOD, &result, pDisp, L"Quit", 0);
    }

	//----------------------------------------------------------------------------------------------------

	// don't forget to release!
	pDisp->Release();

    // COM�̏I������ �����ǉ�
    ::CoUninitialize();

	return 0;
}

