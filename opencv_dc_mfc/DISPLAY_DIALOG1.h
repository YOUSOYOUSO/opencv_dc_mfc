#pragma once


// DISPLAY_DIALOG1 �Ի���

class DISPLAY_DIALOG1 : public CDialogEx
{
	DECLARE_DYNAMIC(DISPLAY_DIALOG1)

public:
	DISPLAY_DIALOG1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DISPLAY_DIALOG1();

// �Ի�������
	enum { IDD = IDD_DISPLAY1_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonPlay();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEditFile();
	afx_msg void OnEnChangeEdit1();
};
