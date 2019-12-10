#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif

#include "IWnd.h"


// TFrame is the base class for a 'frame' window which generally contains / owns other windows.
// In Outpost2 the shell and Dans_RULE_UIFrame (the in game window) are both TFrames.
class OP2 TFrame : public IWnd
{
public:
	TFrame(TFrame const &);
	TFrame();
	virtual ~TFrame();
	TFrame & operator=(TFrame const &);
	virtual void Activate();
	virtual void Deactivate();
	virtual void OnIdle();
	virtual void PostCreateDlg();
	void PostDelayedLoadMessage(char const *);
	virtual void PreCreateDlg();

protected:
	void HandleMenuInit(HMENU, unsigned int, int);
	virtual void ShutDown();
	virtual long WndProc(unsigned int, unsigned int, long);
};
