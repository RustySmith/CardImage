
// Frame.h : interface of the Frame class
//

#pragma once

class Frame : public CFrameWnd
{
//Member Functions:
protected: // create from serialization only
	Frame() noexcept;
	DECLARE_DYNCREATE(Frame)
public:
	virtual ~Frame();

	// Overrides
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};


