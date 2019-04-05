#pragma once


enum FilterPositions {
	FilterPosLast = 0,
	FilterPosFirst = 1,
};

enum FilterOptions {
	FilterOptMouseMessage = 1,
	FilterOptKeyboardMessage = 2,
};

class Filter;
struct FilterNode;


// IWnd declarations.
// The IWnd class is the base class for most windows in Outpost2.
// It abstracts the Win32 windowing calls (though not much, since you still have to use the API).

class OP2 IWnd
{
public:
	IWnd(IWnd const &);
	IWnd(void);
	virtual ~IWnd(void);
	IWnd & operator=(IWnd const &);
	virtual int CallFilters(unsigned int, unsigned int, long);
	virtual int CreateEx(unsigned long,char const *, unsigned long, int, int, int, int, HWND, HMENU, void *, HINSTANCE);
	virtual void Destroy(void);
	FilterNode * FindNode(Filter *,int);
	static IWnd * __fastcall FromHWND(HWND);
	static long __stdcall IWndCbtFilterHook(int, unsigned int, long);
	void InstallFilter(Filter *, int, FilterPositions, FilterOptions);
	void RemoveFilter(Filter *, int);
	virtual long WndProc(unsigned int,unsigned int, long);
	static long __stdcall _WndProc(HWND,unsigned int, unsigned int, long);

private:
	virtual char const* RegisterClassA(void);
};
