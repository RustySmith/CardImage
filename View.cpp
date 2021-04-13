#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Main.h"
#endif

#include "Save.h"
#include "View.h"
#include "Card.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// View

IMPLEMENT_DYNCREATE(View, CView)

BEGIN_MESSAGE_MAP(View, CView)
	ON_COMMAND(ID_Deal, &View::OnDeal)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// View construction/destruction

View::View() noexcept
{
	// TODO: add construction code here

}

View::~View()
{
}

BOOL View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// View drawing

void View::OnDraw(CDC* pDC)
{
	Save* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect ViewRect;
	GetClientRect(ViewRect);
	int ImgWidth = ViewRect.Width()/10;
	int ImgHeight = ImgWidth * 3 / 2;

	HDC hDC = pDC->m_hDC;						//Get the device context handle.

	HINSTANCE hInst = AfxGetInstanceHandle();	//Get the program instance handle.
	//Load the bitmap image indicated by ResourceID;
	HANDLE hBMP = LoadImageW(hInst, MAKEINTRESOURCE(311), IMAGE_BITMAP, ImgWidth, ImgHeight, LR_DEFAULTCOLOR);

	HDC hMemDC = CreateCompatibleDC(hDC);
	::SelectObject(hMemDC, hBMP);
	BOOL RetVal = BitBlt(hDC, 0, 0, ImgWidth, ImgHeight, hMemDC, 0, 0, SRCCOPY);
	::DeleteDC(hMemDC);

}


// View diagnostics

#ifdef _DEBUG
void View::AssertValid() const
{
	CView::AssertValid();
}

void View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Save* View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Save)));
	return (Save*)m_pDocument;
}
#endif //_DEBUG


// View message handlers


void View::OnDeal()
{
	HWND hView = GetSafeHwnd();
	CPoint CardLoc{ 300, 100 };
	Card* Card1= new Card(hView, CardLoc);
}


void View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
}
