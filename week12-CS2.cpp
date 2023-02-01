
// project1View.cpp : implementation of the Cproject1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "project1.h"
#endif

#include "project1Doc.h"
#include "project1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cproject1View

IMPLEMENT_DYNCREATE(Cproject1View, CView)

BEGIN_MESSAGE_MAP(Cproject1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cproject1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cproject1View construction/destruction

Cproject1View::Cproject1View()
	: m_rectEllipse(0,0,200,200)
	, startpt(-1)
	, endpt(-1)
{
	// TODO: add construction code here
	m_color = GRAY_BRUSH;


}

Cproject1View::~Cproject1View()
{
}

BOOL Cproject1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cproject1View drawing

void Cproject1View::OnDraw(CDC* pDC)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	//d
	pDC->SelectStockObject(m_color);
	pDC->Ellipse(m_rectEllipse);

	//c
	pDC->MoveTo(100,100);
	pDC->LineTo(100,200);
	pDC->LineTo(200,200);
	pDC->LineTo(200,100);
	pDC->LineTo(100,100);
	pDC->LineTo(200,200);
	pDC->TextOutW(200,200,_T("I like VC++"));
	pDC->TextOutW(220,220,_T("I like VC++"));




}


// Cproject1View printing


void Cproject1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cproject1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cproject1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cproject1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cproject1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cproject1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cproject1View diagnostics

#ifdef _DEBUG
void Cproject1View::AssertValid() const
{
	CView::AssertValid();
}

void Cproject1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cproject1Doc* Cproject1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cproject1Doc)));
	return (Cproject1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cproject1View message handlers


void Cproject1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_rectEllipse.PtInRect(point)) {
		if (m_color == GRAY_BRUSH){ 
			m_color = WHITE_BRUSH;
		}else{
			m_color = GRAY_BRUSH;
		}

		InvalidateRect(m_rectEllipse);

	}
	////////////////////////////
	startpt.x = point.x;
	startpt.y = point.y;



	CView::OnLButtonDown(nFlags, point);
}


void Cproject1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	startpt = -1;

	CView::OnLButtonUp(nFlags, point);
}


void Cproject1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	endpt.x = point.x;
	endpt.y = point.y;
	if (startpt.x != -1) {
		dc.MoveTo(startpt.x,startpt.y);
		dc.LineTo(endpt.x,endpt.y);
		startpt.x = endpt.x;
		startpt.y = endpt.y;

	}

	CView::OnMouseMove(nFlags, point);
}
