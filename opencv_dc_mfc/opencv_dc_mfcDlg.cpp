
// opencv_dc_mfcDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "opencv_dc_mfc.h"
#include "opencv_dc_mfcDlg.h"
#include "afxdialogex.h"
#include "opencv2/opencv.hpp"
#include <opencv2\core\core.hpp>

#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


#include "CvvImage.h"
#include "DISPLAY_DIALOG1.h" //#添加的#


CEvent start_event;
CEvent start_event1;

int terminate_flag;

int terminate_flag1;//控制前景视频窗口的

extern int testBJC();

extern CString file_address; //#添加的#
extern int flag_1; //#添加的#
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CopencvdcmfcDlg 对话框



CopencvdcmfcDlg::CopencvdcmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_OPENCV_DC_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CopencvdcmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, ID_PLUSE_VIDEO, PluseButton);
	DDX_Control(pDX, ID_PLUSE_VIDEO1, PluseButton1);
}

BEGIN_MESSAGE_MAP(CopencvdcmfcDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_PLUSE_VIDEO, &CopencvdcmfcDlg::OnBnClickedPluseVideo)
	ON_BN_CLICKED(ID_END_VIDEO, &CopencvdcmfcDlg::OnBnClickedEndVideo)
	ON_BN_CLICKED(ID_START_VIDEO, &CopencvdcmfcDlg::OnBnClickedStartVideo)
	ON_BN_CLICKED(IDOK, &CopencvdcmfcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CopencvdcmfcDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_RETURN, &CopencvdcmfcDlg::OnBnClickedButtonReturn)
	ON_BN_CLICKED(IDC_CONVERT, &CopencvdcmfcDlg::OnBnClickedConvert)
	ON_BN_CLICKED(ID_START_VIDEO1, &CopencvdcmfcDlg::OnBnClickedStartVideo1)
	ON_BN_CLICKED(ID_PLUSE_VIDEO1, &CopencvdcmfcDlg::OnBnClickedPluseVideo1)
	ON_BN_CLICKED(ID_END_VIDEO1, &CopencvdcmfcDlg::OnBnClickedEndVideo1)
END_MESSAGE_MAP()


// CopencvdcmfcDlg 消息处理程序

BOOL CopencvdcmfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CopencvdcmfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CopencvdcmfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CopencvdcmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



DWORD WINAPI PlayVideo(LPVOID lpParam) {

	CopencvdcmfcDlg* pThis = (CopencvdcmfcDlg*)lpParam;
	CvCapture* pCapture;
	IplImage* pFrame;
	//const char* ABC;
	//ABC = "233.mp4";//测试下

	const wchar_t* wstr = (LPCTSTR)file_address;     //一定得是unicode，否则这句话会错的
	char str[20] = { 0 };
	wcstombs(str, wstr, wcslen(wstr));
	//以上是完成了从CString 到 char* 的转换，将file_address的值传给str

	pCapture = cvCreateFileCapture(str);

	if (pCapture == NULL)
	{
		return -1;
	}

	pFrame = cvQueryFrame(pCapture);
	while (pFrame)
	{
		WaitForSingleObject(start_event, INFINITE);
		start_event.SetEvent();
		if (terminate_flag == -1)
		{
			terminate_flag = 0;
			_endthreadex(0);
		};
		pThis->Display(pFrame, IDC_STATIC);
		Sleep(33);
		pFrame = cvQueryFrame(pCapture);
	}

	cvReleaseCapture(&pCapture);

}


void CopencvdcmfcDlg::Display(IplImage * img, UINT ID) {

	CDC* pDC = GetDlgItem(ID)->GetDC();  //CDC是一个类  
										 //GetDlgItem(ID)获取控件窗口对象,GetDC()由窗口对象得到DC,然后可以用来在控件中画图  
										 //上一句等价于CWnd* pWin=GetDlgItem(ID);  CDC* pDC=pWin->GetDC();  

	HDC hDC = pDC->GetSafeHdc();//HDC是一个句柄     
	CRect rect;
	CWnd  *pWnd;

	int picWidth;
	int picHeight;

	pWnd = GetDlgItem(ID);
	pWnd->GetClientRect(&rect);

	//求图片控件的宽和高  
	picWidth = rect.Width();
	picHeight = rect.Height();

	IplImage*dst = cvCreateImage(cvSize(picWidth, picHeight), img->depth, img->nChannels);
	cvResize(img, dst, CV_INTER_LINEAR);

	//  cvFlip(dst,NULL,0);       
	//在控件里显示图片  
	CvvImage cimg;
	cimg.CopyOf(dst);
	cimg.DrawToHDC(hDC, &rect);
	cvReleaseImage(&dst);
	ReleaseDC(pDC);
}

//     ----------------------------------------------------我是分割线---------------------------------------------------------


DWORD WINAPI PlayVideo1(LPVOID lpParam) {
	//这个函数负责前景视频的播放
	CopencvdcmfcDlg* pThis = (CopencvdcmfcDlg*)lpParam;
	CvCapture* pCapture;
	IplImage* pFrame;
	
	pCapture = cvCreateFileCapture("QJ.avi");

	if (pCapture == NULL)
	{
		return -1;
	}

	pFrame = cvQueryFrame(pCapture);
	while (pFrame)
	{
		WaitForSingleObject(start_event1, INFINITE);
		start_event1.SetEvent();
		if (terminate_flag1 == -1)
		{
			terminate_flag1 = 0;
			_endthreadex(0);
		};
		pThis->Display(pFrame, IDC_STATIC2);
		Sleep(33);
		pFrame = cvQueryFrame(pCapture);
	}

	cvReleaseCapture(&pCapture);

}

// ------------------------------------------------------我是分割线-----------------------------------------------------

void CopencvdcmfcDlg::OnBnClickedPluseVideo()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码  
	CString buttonText;
	PluseButton.GetWindowText(buttonText);

	if (buttonText.Compare(_T("暂停")) == 0)
	{
		start_event.ResetEvent();
		PluseButton.SetWindowTextW(_T("继续"));

	}
	else
	{
		start_event.SetEvent();
		PluseButton.SetWindowText(_T("暂停"));
	}
}


void CopencvdcmfcDlg::OnBnClickedEndVideo()
{
	// TODO: 在此添加控件通知处理程序代码  
	terminate_flag = -1;
}


void CopencvdcmfcDlg::OnBnClickedStartVideo()
{
	// TODO: 在此添加控件通知处理程序代码


		HANDLE hThreadSend;         //创建独立线程发送数据  
		DWORD ThreadSendID;

		start_event.SetEvent();

		hThreadSend = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PlayVideo, (LPVOID)this, 0, &ThreadSendID);
		CloseHandle(hThreadSend);

}


void CopencvdcmfcDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialog::OnOK();
}


void CopencvdcmfcDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


void CopencvdcmfcDlg::OnBnClickedButtonReturn()
{
	// TODO:  在此添加控件通知处理程序代码
	flag_1 = 0;  //返回后撤销已经选择的文件，回到初始状态
	CDialog::OnCancel();
	DISPLAY_DIALOG1 dlg;//wait
	dlg.DoModal();
}


void CopencvdcmfcDlg::OnBnClickedConvert()
{	
	AfxMessageBox(_T("正在转换，请等一段时间！"));
	testBJC();
	AfxMessageBox(_T("转换完成！"));
}




void CopencvdcmfcDlg::OnBnClickedStartVideo1()
{
	HANDLE hThreadSend;         //创建独立线程发送数据  
	DWORD ThreadSendID;

	start_event1.SetEvent();

	hThreadSend = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PlayVideo1, (LPVOID)this, 0, &ThreadSendID);
	CloseHandle(hThreadSend);
}


void CopencvdcmfcDlg::OnBnClickedPluseVideo1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString buttonText;
	PluseButton1.GetWindowText(buttonText);

	if (buttonText.Compare(_T("暂停")) == 0)
	{
		start_event1.ResetEvent();
		PluseButton1.SetWindowText(_T("继续"));

	}
	else
	{
		start_event1.SetEvent();
		PluseButton1.SetWindowText(_T("暂停"));
	}
}



void CopencvdcmfcDlg::OnBnClickedEndVideo1()
{
	// TODO:  在此添加控件通知处理程序代码
	terminate_flag1 = -1;
	//结束前景视频播放窗口
}
