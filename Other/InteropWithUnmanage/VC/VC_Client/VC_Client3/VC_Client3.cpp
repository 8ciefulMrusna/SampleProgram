// VC_Client3.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B

// C++��COM�N���C�A���g
// http://www.asahi-net.or.jp/~kv8s-yjm/another/yja106.htm
// http://www.asahi-net.or.jp/~kv8s-yjm/another/yja107.htm
// http://www.asahi-net.or.jp/~kv8s-yjm/another/yja108.htm
// http://www.asahi-net.or.jp/~kv8s-yjm/another/yja109.htm
// http://www.asahi-net.or.jp/~kv8s-yjm/another/yja110.htm

// Interface ������
// http://www.sol.dti.ne.jp/~yoshinor/ni/ni0003.html

#include "stdafx.h"

#include "stdio.h"
#include "windows.h"
#include "objbase.h"

// ���L�̃C���N���[�h�ł͂Ȃ��Atlh����������
//#include "../../VC_COM/VC_COM_i.h"

//VC_COM.dll�����ɁA�K�v�Ȓ�`�t�@�C���𐶐�����
#import "../../VC_COM/Debug/VC_COM.dll" no_namespace named_guids raw_interfaces_only

int _tmain(int argc, _TCHAR* argv[])
{
    HRESULT hr;             // COM �߂�l�p�ϐ�
    IClassTest* pClassTest; // COM�C���^�[�t�F�C�X�|�C���^

    // COM�̏����� �����ǉ�
	hr = ::CoInitialize(NULL);
    if(FAILED(hr)){
        printf("CoInitialize ���s\n");
        return 0;
    }

	// ----------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------

	// <�ȉ��̃R�[�h�́A�A�[���[�o�C���f�B���O�����ł̌Ăяo��>

	// �C���X�^���X�̍쐬(CLSID:[CLSID_ClassTest]��IID:[IID_IClassTest]���w�肵�āA�|�C���^���擾)
    hr = ::CoCreateInstance((REFCLSID) CLSID_ClassTest, 0, CLSCTX_INPROC_SERVER,
							(REFIID) IID_IClassTest, (LPVOID*)&pClassTest);

    if(FAILED(hr)){
        printf("CoCreateInstance ���s\n");
        return 0;
    }

	// BSTR����������ꍇ�́A_bstr_t���y�i����Ȃǁj
	// http://mzs184.blogspot.com/2008/04/bstrbstrt.html

	// _bstr_t Class
	// http://msdn.microsoft.com/ja-jp/library/zthfhkd6.aspx
	// _bstr_t::operator =
	// http://msdn.microsoft.com/ja-jp/library/7bh2f8sk.aspx
	_bstr_t bstrText =  L"��������";
	_bstr_t bstrCaption = L"�ɂ���";
	_bstr_t bstrRetVal;

	// ���\�b�h�Ăяo��

	// _bstr_t::wchar_t*, _bstr_t::char*
	// BSTR��OLECHAR�i= WCHAR�j�̃|�C���^�Ȃ̂œK�p�\�B
	// http://msdn.microsoft.com/ja-jp/library/btdzb8eb.aspx
	// _bstr_t::GetAddress
	// http://msdn.microsoft.com/ja-jp/library/t2x13207.aspx
	hr = pClassTest->MethodTest(bstrText, bstrCaption, bstrRetVal.GetAddress());

	if(FAILED(hr)){
        printf("MethodTest ���s\n");
        return 0;
    }

	MessageBox(NULL, bstrRetVal, L"�߂�l", MB_OK);

	// bstrRetVal���N���A�iDetach����SysFreeString�j

	// _bstr_t::Detach
    // http://msdn.microsoft.com/en-us/library/3c73x1sf.aspx
	// SysFreeString
	// http://msdn.microsoft.com/ja-jp/site/ms221481

	BSTR bstr = bstrRetVal.Detach();

	if(bstr != NULL)
	{
		SysFreeString(bstr);
	}

	// bstrCaption�̍Đݒ�
	bstrCaption = L"";

	// ���\�b�h�Ăяo���i����j
	hr = pClassTest->MethodTest(bstrText, bstrCaption, bstrRetVal.GetAddress());
	
	// Dr.GUI Online
	// Dr.GUI �� COM �I�[�g���[�V�����A
	// �� 3 ���F�� COM �̂��΂炵���f�[�^�^
	// http://msdn.microsoft.com/ja-jp/library/cc482694.aspx
	// ISupportErrorInfo�AIErrorInfo�ŃG���[�����擾

	if(FAILED(hr))
	{
		// IID_ISupportErrorInfo�C���^�[�t�F�C�X���擾
		ISupportErrorInfo *pSupport;
		hr = pClassTest->QueryInterface(IID_ISupportErrorInfo, (void**)&pSupport);

		if (SUCCEEDED(hr)) {

			hr = pSupport->InterfaceSupportsErrorInfo(IID_IClassTest);

			if (hr == S_OK) { // can't use SUCCEEDED here! S_FALSE succeeds!

				IErrorInfo *pErrorInfo;
				hr = GetErrorInfo(0, &pErrorInfo);

				if (SUCCEEDED(hr)) {
					// FINALLY can call methods on pErrorInfo! ...and handle the error!

					_bstr_t bstrErrorDescription;
					pErrorInfo->GetDescription(bstrErrorDescription.GetAddress());

					// �G���[���
					MessageBox(NULL, bstrErrorDescription, L"ErrorDescription", MB_OK);

					// don't forget to release!
					pErrorInfo->Release();
				}
			}

			// don't forget to release!
			pSupport->Release();
		}
	}

	// don't forget to release!
	pClassTest->Release();

	// ----------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------

	// <�ȉ��̃R�[�h�́A���C�g�o�C���f�B���O�����ł̌Ăяo��>

	// CLSID �̎擾
    CLSID clsid;
    hr = CLSIDFromProgID(L"VC_COM.ClassTest", &clsid);

    if(FAILED(hr)){
        printf("CLSIDFromProgID ���s\n");
        return 0;
    }

	// �C���X�^���X�̍쐬(CLSID��IID:[IID_IDispatch]���w�肵�āA�|�C���^���擾)
    IDispatch* pDisp = NULL;
    hr = ::CoCreateInstance(clsid, NULL, CLSCTX_ALL, IID_IDispatch, (void**)&pDisp);

    if(FAILED(hr)){
        printf("CoCreateInstance ���s\n");
        return 0;
    }
	
	// COM�f�B�X�p�b�`���ʎq�̎擾
	DISPID dispID;
	OLECHAR* wszName = L"MethodTest";
	hr = pDisp->GetIDsOfNames(IID_NULL, &wszName, 1, LOCALE_USER_DEFAULT, &dispID);

	if(FAILED(hr)){
        printf("GetIDsOfNames ���s\n");
        exit(1);
    }
	
	// CComVariant �N���X�iCComVariant �� VARIANT �^����h���j
	// http://msdn.microsoft.com/ja-jp/library/ac97df2h.aspx

	// ������ VARIANT �z��ɐݒ�
    CComVariant pvArgs[2];
	pvArgs[0] = L"��������";
	pvArgs[1] = L"�ɂ���";

	// �߂�l�� VARIANT�ϐ�
	CComVariant pvResult;

	// DISPPARAMS �̐ݒ�
    DISPPARAMS dispParams;

    dispParams.rgvarg = pvArgs;
    dispParams.rgdispidNamedArgs = NULL;
    dispParams.cArgs = 2;
    dispParams.cNamedArgs = 0;

	// ���\�b�h�Ƀ��C�g�o�C���h�iInvoke�j
	hr = pDisp->Invoke(dispID, IID_NULL,
		LOCALE_USER_DEFAULT, DISPATCH_METHOD,
		&dispParams, &pvResult, NULL, NULL);

	if(FAILED(hr)){
        printf("MethodTest ���s\n");
        return 0;
    }

	// BSTR�Ŋi�[����Ă��鎞�AtagVARIANT�̃����o�AbstrVal�Ŏ擾�\�B
	// BSTR��OLECHAR�i= WCHAR�j�̃|�C���^�Ȃ̂�LPWSTR�ɃL���X�g�\�B
	MessageBox(NULL, (LPWSTR)pvResult.bstrVal, L"�߂�l", MB_OK);

	// don't forget to release!
	pDisp->Release();

	// ----------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------

    // COM�̏I������ �����ǉ�
    ::CoUninitialize();

    return 0;
}