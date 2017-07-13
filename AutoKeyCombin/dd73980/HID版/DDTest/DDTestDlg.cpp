
// DDTestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DDTest.h"
#include "DDTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDTestDlg �Ի���



CDDTestDlg::CDDTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDDTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDDTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDDTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_find, &CDDTestDlg::OnBnClickedButtonfind)
	ON_BN_CLICKED(IDC_BUTTON1, &CDDTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDDTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDDTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDDTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDDTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDDTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDDTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDDTestDlg::OnBnClickedButton8)

	ON_WM_COPYDATA()
	ON_WM_TIMER()
	ON_WM_HOTKEY()
END_MESSAGE_MAP()

void CDDTestDlg::SetHotKey(void)
{
	::RegisterHotKey(GetSafeHwnd(),6689,                0           ,  VK_F3 ); 
	::RegisterHotKey(GetSafeHwnd(),6690,                0           ,  VK_F4 ); 

}

// CDDTestDlg ��Ϣ�������

BOOL CDDTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetHotKey();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDDTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDDTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//����DDHID.dll
void CDDTestDlg::OnBnClickedButtonfind()
{
	CFileDialog 	dlg(TRUE,L"DD",L"", OFN_HIDEREADONLY  , L"DD����ļ�|*.dll" ,NULL,0,TRUE);

	WCHAR fileBuffer[MAX_PATH] = {0};
	dlg.m_ofn.lpstrFile = fileBuffer;
	dlg.m_ofn.nMaxFile= MAX_PATH;

	if (  dlg.DoModal() != IDOK)
	{
		return;
	}

	CString dllfile = dlg.GetPathName();
	(GetDlgItem(IDC_EDIT1))->SetWindowTextW(dllfile);
	int ret = dd.GetFunAddr(dllfile) ;

	if ( ret == 1 )
	{
		//DLL���سɹ�
		int r = dd.DD_int(0);
		if (1==r)
		{
			//����1����ʼ���ɹ�
			(GetDlgItem(IDC_BUTTON1))->EnableWindow(TRUE);
			(GetDlgItem(IDC_BUTTON2))->EnableWindow(TRUE);
			(GetDlgItem(IDC_BUTTON3))->EnableWindow(TRUE);
			(GetDlgItem(IDC_BUTTON4))->EnableWindow(TRUE);
			(GetDlgItem(IDC_BUTTON5))->EnableWindow(TRUE);
			(GetDlgItem(IDC_BUTTON6))->EnableWindow(TRUE);	
			(GetDlgItem(IDC_BUTTON7))->EnableWindow(TRUE);	
			//(GetDlgItem(IDC_BUTTON8))->EnableWindow(TRUE);		
		}
		else
		{
			//��ʼ������
			if (r==-4)
			{
				AfxMessageBox(L"���粻ͨ");
			} 
			else if(r==-7)
			{
				AfxMessageBox(L"������֤����,�Ժ����Ի������");
			}
			else
			{
				CString s;
				s.Format(L"��ʼ������: %d ", r);
				AfxMessageBox(s);
			}
		}
	}
}

//���̵���
void CDDTestDlg::OnBnClickedButton1()
{
	dd.DD_key(601 ,1);
	dd.DD_key(601 ,2);

}

//����ƶ�
void CDDTestDlg::OnBnClickedButton2()
{
	dd.DD_movR(100,100);
	//��������dx,dy .  -127 < ȡֵ��Χ < 127 

}

//������Ҽ�
void CDDTestDlg::OnBnClickedButton3()
{
	AfxMessageBox(L"==");
	Sleep(5000);

	dd.DD_btn(1);	dd.DD_btn(2);
	Sleep(1000);
	dd.DD_btn(4);	dd.DD_btn(8);

}

//����
void CDDTestDlg::OnBnClickedButton4()
{
	AfxMessageBox(L"==");
	Sleep(5000);

	dd.DD_whl(10);
	Sleep(1000);
	dd.DD_whl(-10);

}

//���̿ɼ��ַ���
void CDDTestDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(L"==");
	Sleep(5000);

	dd.DD_str("123ABCefg@dd");

	return;
}


BOOL CDDTestDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int len = pCopyDataStruct->cbData ;
	PCHAR ss = (PCHAR)pCopyDataStruct->lpData;
	char buf[255]={0};
	strcpy_s(buf, ss);

	dd.DD_str(buf);

	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}

//��ϼ�
void CDDTestDlg::OnBnClickedButton6()
{
	//ctrl+alt+del
	dd.DD_key(600,1);	
	dd.DD_key(602,1);	
	dd.DD_key(706,1);	
	dd.DD_key(706,2);
	dd.DD_key(602,2);
	dd.DD_key(600,2);
}

//�����ƶ�
void CDDTestDlg::OnBnClickedButton7()
{
	dd.DD_mov(500,500);
	//dd.DD_mov(0,0);
}

//����
void CDDTestDlg::OnBnClickedButton8()
{
	AfxMessageBox(L"==");
	Sleep(5000);
	//SetTimer(1,10,0);return;//�Զ�

	//�϶�
	dd.DD_mov(300,300);Sleep(500);
	dd.DD_btn(1);	Sleep(100);
	dd.DD_mov(100,100);Sleep(3000);
	dd.DD_btn(2);
}


void CDDTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent)
	{
	case 1:
		dd.DD_mov(1,0);
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CDDTestDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nHotKeyId)
	{
	case  6689:  // ģ����������Ͽɼ��ַ�
		dd.DD_mov(10,00);
		break;
	case 6690:
		dd.DD_mov(-10,0);
	}
	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}

