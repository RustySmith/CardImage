#include "pch.h"
#include "Card.h"

//Static member variables:
int Card::mCardID;				//Unique ID used by Create().
ATOM Card::mWinClassReg;		//Window class registration atom.

//Callback function referenced in RegisterCardClass().
LRESULT CALLBACK event(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	return DefWindowProc(hwnd, msg, wparam, lparam);
}


Card::Card(HWND hView, CPoint CardLoc)
{
	//Set card size and location.
	CRect CardRect{ 0, 0, 200, 300 };
	CardRect.MoveToXY(CardLoc);

	//If the window class hasn't been registerd, register it.
	if (mWinClassReg == 0)
	{
		mWinClassReg = RegisterCardClass();
	}

	//Create the window:
	CWnd* pParentWnd = FromHandle(hView);
	Create
	(
		mCardWinClass,					//Registered window class name.
		NULL,							//Window name is not used for child windows.
		WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE,	//Window style.
		CardRect,						//Initial location and size.
		pParentWnd,						//Pointer to the main window.
		++mCardID						//CardID starts at 1 and increments for each card.
	);
	UpdateWindow();

}

ATOM Card::RegisterCardClass()
{
	/*CWnd requires that windows have a "class" that defines certain characteristics for
	groups of windows. This function creates a window class for Card windows.
	*/

	//Window class structure:
	WNDCLASSEXW WinClassStruct;
	WinClassStruct.cbSize = sizeof(WNDCLASSEX);
	WinClassStruct.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_BYTEALIGNCLIENT;
	WinClassStruct.lpfnWndProc = event;	//Windows message handler for Card windows.
	WinClassStruct.cbClsExtra = 0;
	WinClassStruct.cbWndExtra = 0;
	WinClassStruct.hInstance = AfxGetInstanceHandle();
	WinClassStruct.hIcon = NULL;
	WinClassStruct.hCursor = LoadCursor(nullptr, IDC_ARROW);
	WinClassStruct.hbrBackground = (HBRUSH)mCardBrush;
	WinClassStruct.lpszMenuName = NULL;
	WinClassStruct.lpszClassName = mCardWinClass;
	WinClassStruct.hIconSm = NULL;

	return RegisterClassExW(&WinClassStruct);
}


BEGIN_MESSAGE_MAP(Card, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void Card::OnPaint()
{
	CPaintDC dc(this);		// device context for painting
	HDC hDC = dc.m_hDC;		//Get the device context handle.
	HINSTANCE hInst = AfxGetInstanceHandle();	//Get the program instance handle.
	//Load the bitmap image indicated by ResourceID;
	HANDLE hBMP = LoadImageW(hInst, MAKEINTRESOURCE(mBmpID), IMAGE_BITMAP, 200, 300, LR_DEFAULTCOLOR);

	HDC hMemDC = CreateCompatibleDC(hDC);
	::SelectObject(hMemDC, hBMP);
	BOOL RetVal = BitBlt(hDC, 0, 0, 200, 300, hMemDC, 0, 0, SRCCOPY);
	::DeleteDC(hMemDC);
}
