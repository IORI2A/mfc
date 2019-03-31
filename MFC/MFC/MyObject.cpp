#include "MyObject.h"



const struct CRuntimeClass CMyObject::classCMyObject =
{ "CMyObject", sizeof(CMyObject), 0xffff, NULL, NULL, NULL };

CRuntimeClass* CMyObject::GetRuntimeClass() const
{
	return _RUNTIME_CLASS(CMyObject);
}

void CMyObject::AssertValid() const
{
	ASSERT(this != NULL);
}

void CMyObject::Dump(CDumpContext& dc) const
{
	dc << "a " << GetRuntimeClass()->m_lpszClassName <<
		" at " << (void*)this << "\n";

	UNUSED(dc); // unused in release build
}


#ifdef _AFX_INLINE
#ifndef AFX_INL_INCLUDE_GUARD
#define AFX_INL_INCLUDE_GUARD

// CMyObject
_AFX_INLINE CMyObject::CMyObject()
{ }
_AFX_INLINE CMyObject::~CMyObject()
{ }
_AFX_INLINE void CMyObject::Serialize(CArchive&)
{ /* CMyObject does not serialize anything by default */
}
_AFX_INLINE void* PASCAL CMyObject::operator new(size_t, void* p)
{
	return p;
}
#ifndef _DEBUG
// _DEBUG versions in afxmem.cpp
_AFX_INLINE void PASCAL CMyObject::operator delete(void* p)
{
	::operator delete(p);
}
_AFX_INLINE void PASCAL CMyObject::operator delete(void* p, void*)
{
	::operator delete(p);
}
_AFX_INLINE void* PASCAL CMyObject::operator new(size_t nSize)
{
	return ::operator new(nSize);
}
// _DEBUG versions in objcore.cpp
#ifdef _AFXDLL
_AFX_INLINE void CMyObject::AssertValid() const
{ /* no asserts in release builds */
}
_AFX_INLINE void CMyObject::Dump(CDumpContext&) const
{ /* no dumping in release builds */
}
#endif //_AFXDLL
#endif //!_DEBUG
_AFX_INLINE const CMyObject* AFX_CDECL AfxDynamicDownCast(CRuntimeClass* pClass, const CMyObject* pObject)
{
	return (const CMyObject*)AfxDynamicDownCast(pClass, (CMyObject*)pObject);
}
#ifdef _DEBUG
_AFX_INLINE const CMyObject* AFX_CDECL AfxStaticDownCast(CRuntimeClass* pClass, const CMyObject* pObject)
{
	return (const CMyObject*)AfxStaticDownCast(pClass, (CMyObject*)pObject);
}
#endif



/////////////////////////////////////////////////////////////////////////////
#endif //AFX_INL_INCLUDE_GUARD
#endif //_AFX_INLINE








//CMyDerived::CMyDerived()
//{}
//
//CMyDerived::~CMyDerived()
//{}