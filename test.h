#pragma once
#include "resource.h"

// test-Dialogfeld

class test : public CDialogEx
{
	DECLARE_DYNAMIC(test)

public:
	test(CWnd* pParent = NULL);   // Standardkonstruktor
	virtual ~test();

// Dialogfelddaten
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
};
