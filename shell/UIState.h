#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// OP2 UI state objects
class OP2 UIState
{
public:
	UIState(UIState const &);
	UIState(unsigned int);
	UIState & operator=(UIState const &);
	virtual void Enable(int);
	virtual void SetCheck(int);
	virtual void SetText(char const *);
};

class OP2 BoolState
{
public:
	BoolState(class BoolState const &);
	BoolState(unsigned int);
	BoolState & operator=(BoolState const &);
	virtual void Enable(int);
};

class OP2 MenuState
{
public:
	MenuState(MenuState const &);
	MenuState(HMENU, unsigned int);
	MenuState & operator=(MenuState const &);
	virtual void Enable(int);
	virtual void SetCheck(int);
	virtual void SetText(char const *);
};
