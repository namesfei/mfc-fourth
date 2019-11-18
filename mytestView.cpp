
// mytestView.cpp: CmytestView 类的实现
//


#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mytest.h"
#endif

#include "mytestDoc.h"
#include "mytestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
double scale=1;
// CmytestView

IMPLEMENT_DYNCREATE(CmytestView, CView)

BEGIN_MESSAGE_MAP(CmytestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_MOUSEHWHEEL()
ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CmytestView 构造/析构

CmytestView::CmytestView() noexcept
{
	// TODO: 在此处添加构造代码

}

CmytestView::~CmytestView()
{
}

BOOL CmytestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmytestView 绘图

void CmytestView::OnDraw(CDC* pDC)
{
	CmytestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	 //TODO: 在此处为本机数据添加绘制代码
	sta_shipdata mship = { "阳光",{'1','2','3','4','5','6','7','8','9','\0'}, {'8','8','8','8','\0'},90,18,5,2000 };
	Ship myship(mship);
	myship.set_position(123, 35);
	myship.set_speed_course(20, 90);
	myship.set_ship_profile();
	CString str;
	CString strname("船名："),strnum("呼号："),strmmsi("MMSI：");
	CString strlen("船长："),strwid("船宽："),strdraf("吃水：");
	CString strdis("排水："), strcous("航向："), strspe("航速：");
	CString strpos("船舶位置：");

	strname += myship.outsm()->name;
	strnum += myship.outsm()->number;
	strmmsi += myship.outsm()->MMSI;
	str.Format(_T("%.3f"), myship.outsm()->length); strlen += str; strlen += "米";
	str.Format(_T("%.3f"), myship.outsm()->width); strwid += str; strwid += "米";
	str.Format(_T("%.3f"), myship.outsm()->draft); strdraf += str; strdraf += "米";
	str.Format(_T("%.3f"), myship.outsm()->displacement); strdis += str; strdis += "吨";
	str.Format(_T("%.3f"), myship.outdm()->course); strcous += str; strcous += "°";
	str.Format(_T("%.3f"), myship.outdm()->speed); strspe += str; strspe += "Km/h";
	str.Format(_T("%.3f"), myship.outdm()->latitude); strpos += str; strpos += "° ";
	if (myship.outdm()->latitude < 0)
		strpos += "S   ";
	else
		strpos += "N   ";
	str.Format(_T("%.3f"), myship.outdm()->longitude); strpos += str; strpos += "° ";
	if (myship.outdm()->longitude < 0)
		strpos += "W";
	else
		strpos += "E";

	pDC->TextOutW(0, 30, strname);
	pDC->TextOutW(0, 60, strnum);
	pDC->TextOutW(0, 90, strmmsi);
	pDC->TextOutW(0, 120, strlen);
	pDC->TextOutW(0, 150, strwid);
	pDC->TextOutW(0, 180, strdraf);
	pDC->TextOutW(0, 210, strdis);
	pDC->TextOutW(0, 240, strcous);
	pDC->TextOutW(0, 270, strspe);
	pDC->TextOutW(0, 300, strpos);

	pDC->BeginPath();
	pDC->Rectangle(0, 0, 300, 400);
	pDC->EndPath();
	pDC->SelectClipPath(RGN_DIFF);

	double inpo = 400;//调整起始位置
	//double scale;

	for (int i = 0; i < 5; i++) {

		pDC->MoveTo(int(myship.outdm()->ship_profile[i].x*scale +  2*inpo), int(myship.outdm()->ship_profile[i].y * scale + inpo));
		if (4 == i) {
			pDC->LineTo(int(myship.outdm()->ship_profile[0].x * scale + 2 * inpo), int(myship.outdm()->ship_profile[0].y * scale + inpo));
		}
		else {
			pDC->LineTo(int(myship.outdm()->ship_profile[i + 1].x * scale + 2 * inpo), int(myship.outdm()->ship_profile[i + 1].y * scale + inpo));
		}
	}
	//pDC->TextOutW(0, 30, str2);

	
}


// CmytestView 打印

BOOL CmytestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmytestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmytestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CmytestView 诊断

#ifdef _DEBUG
void CmytestView::AssertValid() const
{
	CView::AssertValid();
}

void CmytestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmytestDoc* CmytestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmytestDoc)));
	return (CmytestDoc*)m_pDocument;
}
#endif //_DEBUG


// CmytestView 消息处理程序




BOOL CmytestView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (zDelta > 0) {
		scale += 1;
	}
	else {
		scale -= 1;
		if (scale < 0) {
			scale = 1;
		}
	}
	Invalidate();
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
