
// VideoConferenceDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CVideoConferenceDlg 对话框
class CVideoConferenceDlg : public CDialog
{
// 构造
public:
	CVideoConferenceDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_VIDEOCONFERENCE_DIALOG };

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
	CStatic mStatus;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit mVideoView;
	CEdit mDialNum;
	afx_msg void OnBnClickedButtonDial();
	CButton mURImode;
	afx_msg void OnBnClickedButtonHangup();
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	//CEdit mUserName;
	//CEdit mSecret;
	//CEdit mSipServer;
	afx_msg void OnBnClickedButtonCapturePic();
	CListCtrl mCallList;
	CString Sec2Time(int sec);
	void OnNMRClickCallList(NMHDR *pNMHDR, LRESULT *pResult);
	int mCurrentCallPos;
	afx_msg void OnCallistDropCall();
	afx_msg void OnCallistAcceptCall();
	afx_msg void OnCallistHoldCall();
	afx_msg void OnCallistResumeCall();
	afx_msg void OnCallistJoinToConf();
	CButton mVideoCallChk;
	afx_msg void OnBnClickedCheckEnabledVideo();
	CComboBox mVideoDevices;
	afx_msg void OnCbnSelchangeComboVideoDevices();
	afx_msg void OnBnClickedButtonStartConf();
	afx_msg void OnBnClickedButtonConfPlayAudio();
	afx_msg void OnBnClickedButtonConfRecordFile();
	CComboBox mSndCap;
	CComboBox mSndPlay;
	afx_msg void OnCbnSelchangeComboAudipCap();
	afx_msg void OnCbnSelchangeComboAudioPlay();
	afx_msg void OnCallistExitConf();
	afx_msg void OnBnClickedButtonConfVad();
	afx_msg void OnBnClickedButtonConfAgc();
	afx_msg void OnBnClickedButtonHalfDuplex();
	afx_msg void OnBnClickedButtonDirectMode();
	afx_msg void OnBnClickedButtonVadProbStart();
	afx_msg void OnBnClickedButton6();
	CButton mChkVideoConf;
	CComboBox mMaxConfMembers;
	afx_msg void OnCbnSelchangeComboBandwidth();
	CComboBox m_bandwidth;
	CButton mLocaMode;
	CButton mchkVideoLocalMonitor;
	CButton mConfVideoAutoLayout;
	afx_msg void OnBnClickedButtonIKey();
	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnBnClickedButtonAddCam();
	afx_msg void OnBnClickedButtonRemoveCam();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheckHdMode();
	CButton mHDMode;
	afx_msg void OnBnClickedButtonPlayVideoFile();
	afx_msg void OnBnClickedButtonPlayer();
	CSliderCtrl m_pos;
//	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButtonEcc();
	afx_msg void OnBnClickedButtonRecord();
	CSliderCtrl mInputValue;
	CSliderCtrl mOutputValue;
	afx_msg void OnEnChangeEditVideoView();
	afx_msg void OnBnClickedButtonUdt();
	afx_msg void OnBnClickedCheckVideoConf();
	CEdit mCallVideoView;
	CStatic mMCUURL;
	CButton mLine_all;
	CButton mLine_1;
	CButton mLine_2;
	CButton mLine_3;
	CButton mLine_4;
	CButton mLine_5;
	CButton mLine_6;
	CButton mLine_7;
	CButton mLine_8;
	CButton mLine_9;
	afx_msg void OnCbnSelchangeComboComMaxUsers();
	void CVideoConferenceDlg::SetPartyControl(int max_users);
	afx_msg void OnBnClickedRadioAllParty();
	afx_msg void OnBnClickedRadioLine1();
	afx_msg void OnBnClickedRadioLine2();
	afx_msg void OnBnClickedRadioLine3();
	afx_msg void OnBnClickedRadioLine4();
	afx_msg void OnBnClickedRadioLine5();
	afx_msg void OnBnClickedRadioLine6();
	afx_msg void OnBnClickedRadioLine7();
	afx_msg void OnBnClickedRadioLine8();
	afx_msg void OnBnClickedRadioLine9();
	afx_msg void OnBnClickedButtonRegister();
	afx_msg void OnBnClickedButtonUnregister();
	CEdit mUserName;
	CEdit mSecret;
	CEdit mSipServer;
	CEdit mRTMPUrl;
	afx_msg void OnBnClickedButtonConfRecord();
	CButton mBntConfRecdoing;
};
