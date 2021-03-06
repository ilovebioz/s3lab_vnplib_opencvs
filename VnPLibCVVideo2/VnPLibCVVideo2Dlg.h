/*
- Các tác giả : Binh Nguyen - Bioz, ...
- Bản quyền thuộc về : IEEV.org.
- Thông tin thêm : CD-01042010;UD-01042010;
- Mô tả : Chương trình minh họa cho việc sử dụng OpenCV để xử lý video 
*/
// VnPLibCVVideo2Dlg.h : header file
//
#pragma once
#include "imgproc.hpp"
#include "highgui\highgui.hpp"
#include "highgui\highgui_c.h"
#include "objdetect.hpp"

#include <time.h>
#include "afxwin.h"

using namespace cv;
using namespace std;


// CVnPLibCVVideo2Dlg dialog
class CVnPLibCVVideo2Dlg : public CDialog
{
// Construction
public:
	CVnPLibCVVideo2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_VNPLIBCVVIDEO2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:
	CString sRootPath;	
	CString sCascadeRootPath;
	int iCameraType; // 0: Cam / CCTV; 1: video; 2: IPNC	
	int iIsProcess;

	void LoadFileListToListBox(int iIListBoxId, CString iSRootPath, CString iSFileExt);
	void LoadFileListToComboBox(int iIComboBoxId, CString iSRootPath, CString iSFileExt);
	CString GetFileNameFromComboBox(int iIListBoxId, int* oPIId );
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
	CComboBox cmbCascades;
	afx_msg void OnBnClickedButtonCascadeBrowser();
	CStatic mSourceAnchor; 
	int mDisplayWindowSize;
	TCHAR mSDirectory[MAX_PATH] = "";
};
