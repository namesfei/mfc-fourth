
// mytestView.h: CmytestView 类的接口
//

#pragma once


class CmytestView : public CView
{
protected: // 仅从序列化创建
	CmytestView() noexcept;
	DECLARE_DYNCREATE(CmytestView)\

// 特性
public:
	CmytestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CmytestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // mytestView.cpp 中的调试版本
inline CmytestDoc* CmytestView::GetDocument() const
   { return reinterpret_cast<CmytestDoc*>(m_pDocument); }
#endif

