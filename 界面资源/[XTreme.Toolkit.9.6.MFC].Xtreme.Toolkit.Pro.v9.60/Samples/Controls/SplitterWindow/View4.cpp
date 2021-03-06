// View4.cpp : implementation file
//
// This file is a part of the XTREME TOOLKIT PRO MFC class library.
// �1998-2005 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SplitterWindow.h"
#include "View4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CView4

IMPLEMENT_DYNCREATE(CView4, CView)

CView4::CView4()
{
}

CView4::~CView4()
{
}


BEGIN_MESSAGE_MAP(CView4, CView)
	//{{AFX_MSG_MAP(CView4)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView4 drawing

void CView4::OnDraw(CDC* pDC)
{
	// TODO: add draw code here
	CRect r;
	GetClientRect(&r);
	pDC->SetBkMode(TRANSPARENT);

	int x = r.Width()/2 -50;
	int y = r.Height()/2-25;

	CRect rcSquare(x,y,x+100,y+50);

	int iSavedDC = pDC->SaveDC();
	pDC->FillSolidRect(&rcSquare, GetXtremeColor(XPCOLOR_HIGHLIGHT));
	pDC->Draw3dRect(&rcSquare, GetXtremeColor(COLOR_HIGHLIGHT), GetXtremeColor(COLOR_HIGHLIGHT));
	pDC->SelectObject(&XTAuxData().fontBold);
	pDC->SetTextColor(GetXtremeColor(XPCOLOR_HIGHLIGHT_TEXT));
	pDC->SetBkMode(TRANSPARENT);
	pDC->DrawText(_T("View Four"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	pDC->RestoreDC(iSavedDC);
}

/////////////////////////////////////////////////////////////////////////////
// CView4 diagnostics

#ifdef _DEBUG
void CView4::AssertValid() const
{
	CView::AssertValid();
}

void CView4::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView4 message handlers

void CView4::OnPaint()
{
	// standard paint routine
	CPaintDC dc(this);

	// Get the client rect.
	CRect rectClient;
	GetClientRect(&rectClient);

	// Paint to a memory device context to reduce screen flicker.
	CXTMemDC memDC(&dc, rectClient, GetXtremeColor(COLOR_WINDOW));

	OnPrepareDC(&memDC);
	OnDraw(&memDC);
}

BOOL CView4::OnEraseBkgnd(CDC* pDC)
{
	UNUSED_ALWAYS(pDC);
	return FALSE;
}
