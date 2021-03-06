
// opencv_dc_mfcDlg.h: 头文件
//

#pragma once
#include "afxwin.h"
#include "opencv2/opencv.hpp"

// CopencvdcmfcDlg 对话框
class CopencvdcmfcDlg : public CDialog
{
// 构造
public:
	CopencvdcmfcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENCV_DC_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Display(IplImage * img, UINT ID);
	afx_msg void OnBnClickedPluseVideo();
	afx_msg void OnBnClickedEndVideo();
	CButton PluseButton;
	afx_msg void OnBnClickedStartVideo();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonReturn();
	afx_msg void OnBnClickedConvert();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedStartVideo1();
	afx_msg void OnBnClickedPluseVideo1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedEndVideo1();
	CButton PluseButton1;
};
