
// View.h : interface of the View class
//

#pragma once


class View : public CView
{
protected: // create from serialization only
	View() noexcept;
	DECLARE_DYNCREATE(View)

// Attributes
public:
	Save* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeal();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in View.cpp
inline Save* View::GetDocument() const
   { return reinterpret_cast<Save*>(m_pDocument); }
#endif

