#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif

class IWnd;
struct FilterNode;


class OP2 Filter
{
public:
	Filter(Filter const &);
	Filter();
	Filter & operator=(class Filter const &);
	static Filter * __fastcall GetCapture();
	virtual int OnUIEvent(IWnd *,unsigned int, unsigned int, long, int);
	void ReleaseCapture(IWnd *);
	void SetCapture(IWnd *, int);

private:
	static FilterNode *pCaptureNode;
};

class OP2 GroupFilter
{
public:
	GroupFilter(GroupFilter const &);
	GroupFilter();
	class GroupFilter & operator=(GroupFilter const &);
	class SubFilter * GetSubFilter() const ;
	virtual int OnUIEvent(IWnd *, unsigned int, unsigned int, long, int);
	void SetSubFilter(SubFilter *);
};

class OP2 SubFilter
{
public:
	SubFilter(SubFilter const &);
	SubFilter();
	SubFilter & operator=(SubFilter const &);
	virtual int OnUIEvent(IWnd *, unsigned int, unsigned int, long, int);
	void ReleaseCapture(GroupFilter *, IWnd *);
	void SetCapture(GroupFilter *, IWnd *, int);
};
