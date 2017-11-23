// DISPLAY_DIALOG1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "opencv_dc_mfc.h"
#include "DISPLAY_DIALOG1.h"
#include "afxdialogex.h"
#include "opencv_dc_mfcDlg.h"

// DISPLAY_DIALOG1 �Ի���
CString file_address;  //#�ļ���ַ����#
int flag_1=0;//#�ж��Ƿ��Ѿ�����ļ�#
IMPLEMENT_DYNAMIC(DISPLAY_DIALOG1, CDialogEx)


DISPLAY_DIALOG1::DISPLAY_DIALOG1(CWnd* pParent /*=NULL*/)
	: CDialogEx(DISPLAY_DIALOG1::IDD, pParent)
{

}

DISPLAY_DIALOG1::~DISPLAY_DIALOG1()
{
}

void DISPLAY_DIALOG1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DISPLAY_DIALOG1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_READ, &DISPLAY_DIALOG1::OnBnClickedButtonRead)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &DISPLAY_DIALOG1::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, &DISPLAY_DIALOG1::OnBnClickedButtonPlay)
	ON_BN_CLICKED(IDCANCEL, &DISPLAY_DIALOG1::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &DISPLAY_DIALOG1::OnEnChangeEditFile)
	ON_EN_CHANGE(IDC_EDIT1, &DISPLAY_DIALOG1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// DISPLAY_DIALOG1 ��Ϣ�������

BOOL DISPLAY_DIALOG1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

void DISPLAY_DIALOG1::OnBnClickedButtonRead()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("mp4(*.mp4)|*.mp4|jpg(*.jpg)|*.jpg|bmp(*.bmp)|*.bmp|All files(*.*)|*.*||" ); //�ɹ�ѡ��ĺ�׺
	// ���챣���ļ��Ի���   
	
	CFileDialog fileDlg(TRUE, 0, 0, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	CString strFilePath;   //�ļ�·��

	// ��ʾ���ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetFileName();
		SetDlgItemText(IDC_EDIT1, strFilePath);
		//���ļ���ַ����ȫ�ֱ���
		file_address = strFilePath;
		flag_1 = 1;//��ʾ�Ѿ�����ļ�
	}
}


void DISPLAY_DIALOG1::OnBnClickedButtonReset()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	flag_1 = 0; //����������ɾ���Ѿ�ѡ����ļ�����flag_1��ֵΪ1
}


void DISPLAY_DIALOG1::OnBnClickedButtonPlay()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	if (flag_1 == 0){
		AfxMessageBox(_T("û��ѡ���κ��ļ���"));
		DISPLAY_DIALOG1 dlg;
		dlg.DoModal();
		//û������ļ��򷵻�ԭ������
	}
	else{
		CopencvdcmfcDlg dlg;
		dlg.DoModal();
		//�Ѿ�����ļ�����ת����Ƶ���Ž���
	}

}


void DISPLAY_DIALOG1::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}





void DISPLAY_DIALOG1::OnEnChangeEditFile()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void DISPLAY_DIALOG1::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
