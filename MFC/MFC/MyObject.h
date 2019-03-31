#pragma once

#include "stdafx.h"

class AFX_NOVTABLE CMyObject
{
public:

	// Object model (types, destruction, allocation)
	virtual CRuntimeClass* GetRuntimeClass() const;
	virtual ~CMyObject() = 0;  // virtual destructors are necessary

	// Diagnostic allocations
	void* PASCAL operator new(size_t nSize);
	void* PASCAL operator new(size_t, void* p);
	void PASCAL operator delete(void* p);
	void PASCAL operator delete(void* p, void* pPlace);

#if defined(_DEBUG)
	// for file name/line number tracking using DEBUG_NEW
	void* PASCAL operator new(size_t nSize, LPCSTR lpszFileName, int nLine);
	void PASCAL operator delete(void *p, LPCSTR lpszFileName, int nLine);
#endif

	// Disable the copy constructor and assignment by default so you will get
	//   compiler errors instead of unexpected behavior if you pass objects
	//   by value or assign objects.
protected:
	CMyObject();
private:
	CMyObject(const CMyObject& objectSrc);              // no implementation
	void operator=(const CMyObject& objectSrc);       // no implementation

// Attributes
public:
	BOOL IsSerializable() const;
	BOOL IsKindOf(const CRuntimeClass* pClass) const;

	// Overridables
	virtual void Serialize(CArchive& ar);

#if defined(_DEBUG) || defined(_AFXDLL)
	// Diagnostic Support
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Implementation
public:
	static const CRuntimeClass classCMyObject;
#ifdef _AFXDLL
	static CRuntimeClass* PASCAL _GetBaseClass();
	static CRuntimeClass* PASCAL GetThisClass();
#endif
};

class CMyDerived : public CMyObject
{
public:
	CMyDerived();
	~CMyDerived();
};