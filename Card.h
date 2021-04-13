#pragma once
#include <afxwin.h>

class Card : public CWnd
{
//Member Functons:
public:
	Card(HWND hView, CPoint CardLoc);	//Constructor.
private:
	ATOM RegisterCardClass();			//Create a window class for Card windows.

//Member Variables:
private:
	static ATOM mWinClassReg;//Window class registration atom.
	static int mCardID;		//Unique identifier for each card.
	CString mCardWinClass = L"Card";//Name of the window class for Card window creation.

	const COLORREF mBlack = RGB(0, 0, 0);			//Black color.
	const COLORREF mRed = RGB(255, 0, 0);			//Red color.
	const COLORREF mWhite = RGB(255, 255, 255);		//White color.
	const COLORREF mBlue = RGB(64, 64, 255);		//Blue color.
	CBrush mCardBrush{ mWhite };					//Solid brush for card background.
	CBrush mBlackBrush{ mBlack };

	CBitmap mCardBmp{};								//Card face bitmap image
	CDC mMemDC;										//Memory device context.
	UINT mBmpID{ 311 };


public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

