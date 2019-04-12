#pragma once

#include "IWnd.h"


// IDlgWnd is the base class for most dialogs in Outpost2.
class OP2 IDlgWnd : public IWnd
{
public:
	IDlgWnd(IDlgWnd const &);
	IDlgWnd(void);
	virtual ~IDlgWnd(void);
	IDlgWnd & operator=(IDlgWnd const &);
	static IDlgWnd * __fastcall DlgFromHWND(HWND);
	virtual int DlgProc(unsigned int, unsigned int, long);
	virtual int DoModal(char const *, HINSTANCE);
	virtual int DoModeless(char const *, HINSTANCE, HWND);
	static HWND __fastcall GetModalParent(void);
	int IsModalParentSet(void) const ;
	static int __fastcall PretranslateModeless(struct tagMSG *);
	void SetAsModalParent(int);

private:
	void InsertHWNDChain(void);
	void RemoveHWNDChain(void);
	static int __stdcall _DlgProc(HWND,unsigned int, unsigned int, long);
	static int nModelessCount;
	static IDlgWnd *pFirst;
};
