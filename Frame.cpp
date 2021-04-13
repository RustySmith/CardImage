
// Frame.cpp : implementation of the Frame class
//

#include "pch.h"
#include "framework.h"
#include "Main.h"

#include "Frame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Frame

IMPLEMENT_DYNCREATE(Frame, CFrameWnd)

BEGIN_MESSAGE_MAP(Frame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// Frame construction/destruction

Frame::Frame() noexcept
{
	// TODO: add member initialization code here
}

Frame::~Frame()
{
}


BOOL Frame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPEDWINDOW;

	return TRUE;
}

// Frame diagnostics

#ifdef _DEBUG
void Frame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void Frame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// Frame message handlers

int Frame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}

