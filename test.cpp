// test.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "test.h"
#include "afxdialogex.h"


// test-Dialogfeld

IMPLEMENT_DYNAMIC(test, CDialogEx)

test::test(CWnd* pParent /*=NULL*/)
	: CDialogEx(test::IDD, pParent)
{

}

test::~test()
{
}

void test::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(test, CDialogEx)
END_MESSAGE_MAP()


// test-Meldungshandler
