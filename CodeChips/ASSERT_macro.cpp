
#include <Windows.h>
#include <crtdbg.h>  // _CrtDbgReport 、 _CRT_ASSERT 、 _CrtDbgBreak


#define ASSERT(f)          DEBUG_ONLY((void) ((f) || !::AfxAssertFailedLine(THIS_FILE, __LINE__) || (AfxDebugBreak(), 0)))


/////////////////////////////////////////////////////////////////////////////////
#ifndef AFXAPI
#define AFXAPI __stdcall
#endif

#define THIS_FILE          __FILE__
#define DEBUG_ONLY(f)      (f)


#ifdef _DEBUG  

BOOL AFXAPI AfxAssertFailedLine(LPCSTR lpszFileName, int nLine);

#endif // _DEBUG


#ifdef _DEBUG  

// NOTE: in separate module so it can replaced if needed

BOOL AFXAPI AfxAssertFailedLine(LPCSTR lpszFileName, int nLine)
{
#ifndef _AFX_NO_DEBUG_CRT
	// we remove WM_QUIT because if it is in the queue then the message box
	// won't display
	MSG msg;
	BOOL bQuit = PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
	BOOL bResult = _CrtDbgReport(_CRT_ASSERT, lpszFileName, nLine, NULL, NULL);
	if (bQuit)
		PostQuitMessage((int)msg.wParam);
	return bResult;
#else
	// Not supported.
#error _AFX_NO_DEBUG_CRT is not supported.
#endif // _AFX_NO_DEBUG_CRT
}
#endif // _DEBUG



/////////////////////////////////////////////////////////////////////////////
// Special AfxDebugBreak: used to break into debugger at critical times

#ifndef AfxDebugBreak
#ifdef _AFX_NO_DEBUG_CRT
// by default, debug break is asm int 3, or a call to DebugBreak, or nothing
#if defined(_M_IX86) && !defined(_AFX_PORTABLE)
#define AfxDebugBreak() _asm { int 3 }
#else
#define AfxDebugBreak() DebugBreak()
#endif
#else
#define AfxDebugBreak() _CrtDbgBreak()
#endif
#endif

#ifndef _DEBUG
#ifdef AfxDebugBreak
#undef AfxDebugBreak
#endif
#define AfxDebugBreak()
#endif  // _DEBUG




int main()
{
	ASSERT(FALSE);

	return 0;
}
