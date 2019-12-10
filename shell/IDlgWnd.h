#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif

#include "IWnd.h"


// IDlgWnd is the base class for most dialogs in Outpost2.
class OP2 IDlgWnd : public IWnd
{
public:
	IDlgWnd(IDlgWnd const &);
	IDlgWnd();
	virtual ~IDlgWnd();
	IDlgWnd & operator=(IDlgWnd const &);
	static IDlgWnd * __fastcall DlgFromHWND(HWND);
	virtual int DlgProc(unsigned int, unsigned int, long);
	virtual int DoModal(char const *, HINSTANCE);
	virtual int DoModeless(char const *, HINSTANCE, HWND);
	static HWND __fastcall GetModalParent();
	int IsModalParentSet() const ;
	static int __fastcall PretranslateModeless(struct tagMSG *);
	void SetAsModalParent(int);

private:
	void InsertHWNDChain();
	void RemoveHWNDChain();
	static int __stdcall _DlgProc(HWND,unsigned int, unsigned int, long);
	static int nModelessCount;
	static IDlgWnd *pFirst;
};
