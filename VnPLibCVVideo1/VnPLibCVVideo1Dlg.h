/*
- Các tác giả : Binh Nguyen - Bioz, ...
- Bản quyền thuộc về : IEEV.org.
- Thông tin thêm : CD-01042010;UD-01042010;
- Mô tả : Chương trình minh họa cho việc sử dụng OpenCV để xử lý video 
*/
// VnPLibCVVideo1Dlg.h : header file
//
#pragma once
//#include "afxwin.h"
#include "imgproc.hpp"
#include "highgui\highgui.hpp"
#include "highgui\highgui_c.h"

#include <time.h>

using namespace cv;
using namespace std;


// CVnPLibCVVideo1Dlg dialog
class CVnPLibCVVideo1Dlg : public CDialog
{
// Construction
public:
	CVnPLibCVVideo1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_VNPLIBCVVIDEO1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:
	CString sRootPath;	
	int iCameraType; // 0: Cam / CCTV; 1: video; 2: IPNC	
	int iIsProcess;

	void LoadFileListToListBox(int iIListBoxId, CString iSRootPath, CString iSFileExt);
	CString GetFileNameFromListBox(int iIListBoxId , int* oPICamId );
	void ShowImageOnIFace(Mat pIImgDisp, Mat pIImgSour, int iIROIXPad, int iIROIYPad,
							int iIROIWidth, int iIROIHeight, const char* cPCView);
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedImageBrowserBtn();
	afx_msg void OnLbnSelchangeListSourceImage();	
	afx_msg void OnClose();	
	afx_msg void OnBnClickedCancelProcessBtn();
	afx_msg void OnBnClickedCamBrowserBtn();
	CStatic mSourceAnchor;
	int mDisplayWindowSize;
	TCHAR mSDirectory[MAX_PATH] = "";
};
