#include "stdafx.h"

#include "Globals.h"
#include "Register.h"
#include "WeaselTSF.h"
#include <VersionHelpers.h>

void DllAddRef()
{
	OutputDebugString(_T("DllAddRef"));
	InterlockedIncrement(&g_cRefDll);
}

void DllRelease()
{
	OutputDebugString(_T("DllRelease"));
	InterlockedDecrement(&g_cRefDll);
}

class CClassFactory: public IClassFactory
{
public:
	// IUnknown methods
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// IClassFactory methods
	STDMETHODIMP CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject);
	STDMETHODIMP LockServer(BOOL fLock);
};

STDAPI CClassFactory::QueryInterface(REFIID riid, void **ppvObject)
{
	OutputDebugString(_T("CClassFactory::QueryInterface\n"));
	if (IsEqualIID(riid, IID_IClassFactory) || IsEqualIID(riid, IID_IUnknown))
	{
		*ppvObject = this;
		DllAddRef();
		OutputDebugString(_T("CClassFactory::QueryInterface OK\n"));
		return NOERROR;
	}
	*ppvObject = NULL;
	OutputDebugString(_T("CClassFactory::QueryInterface NOT FOUND\n"));
	return E_NOINTERFACE;
}

STDAPI_(ULONG) CClassFactory::AddRef()
{
	OutputDebugString(_T("CClassFactory::AddRef() \n"));
	DllAddRef();
	return g_cRefDll + 1;
}

STDAPI_(ULONG) CClassFactory::Release()
{
	OutputDebugString(_T("CClassFactory::Release() \n"));
	DllRelease();
	return g_cRefDll + 1;
}

STDAPI CClassFactory::CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject)
{
	OutputDebugString(_T("CClassFactory::CreateInstance \n"));
	WeaselTSF *pCase;
	HRESULT hr;
	if (ppvObject == NULL) {
		OutputDebugString(_T("CClassFactory::CreateInstance Invalidarg"));
		return E_INVALIDARG;
	}
	*ppvObject = NULL;
	if (pUnkOuter != NULL) {
		OutputDebugString(_T("CClassFactory::CreateInstance NoArgg"));
		return CLASS_E_NOAGGREGATION;
	}
	if ((pCase = new WeaselTSF()) == NULL)
		return E_OUTOFMEMORY;
	hr = pCase->QueryInterface(riid, ppvObject);
	pCase->Release(); // caller still holds ref if hr == S_OK
	return hr;
}

STDAPI CClassFactory::LockServer(BOOL fLock)
{
	OutputDebugString(_T("CClassFactory::LockServer \n"));
	if (fLock)
		DllAddRef();
	else
		DllRelease();
	return S_OK;
}

static CClassFactory *g_classFactory = NULL;

static void BuildGlobalObjects()
{
	g_classFactory = new CClassFactory();
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppvObject)
{
	OutputDebugString(_T("CClassFactory::DllGetClassObject \n"));
	if (g_classFactory == NULL)
	{
		EnterCriticalSection(&g_cs);
		if (g_classFactory == NULL)
			BuildGlobalObjects();
		LeaveCriticalSection(&g_cs);
	}
	if (IsEqualIID(riid, IID_IClassFactory) || IsEqualIID(riid, IID_IUnknown))
	{
		*ppvObject = g_classFactory;
		DllAddRef();
		return NOERROR;
	}
	*ppvObject = NULL;
	return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI DllCanUnloadNow()
{
	if (g_cRefDll >= 0)
		return S_FALSE;
	return S_OK;
}

STDAPI DllRegisterServer()
{
	//InitVersion();
	OutputDebugString(_T("DllRegisterServer"));
	if (!RegisterServer() || !RegisterProfiles() || !RegisterCategories())
	{
		DllUnregisterServer();
		return E_FAIL;
	}
	return S_OK;
}

STDAPI DllUnregisterServer()
{
	UnregisterProfiles();
	UnregisterCategories();
	UnregisterServer();
	return S_OK;
}
