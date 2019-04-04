#pragma once

// TFrame related declarations.
// TFrame is the base class for a 'frame' window which generally contains / owns other windows.
// In Outpost2 the shell and Dans_RULE_UIFrame (the in game window) are both TFrames.

class OP2 TFrame : public IWnd
{
public:
	TFrame(TFrame const &);
	TFrame(void);
	virtual ~TFrame(void);
	TFrame & operator=(TFrame const &);
	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void OnIdle(void);
	virtual void PostCreateDlg(void);
	void PostDelayedLoadMessage(char const *);
	virtual void PreCreateDlg(void);
protected:
	void HandleMenuInit(HMENU,unsigned int,int);
	virtual void ShutDown(void);
	virtual long WndProc(unsigned int,unsigned int,long);
};
