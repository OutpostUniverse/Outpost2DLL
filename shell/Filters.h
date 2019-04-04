#pragma once

// OP2 "filter" objects
class OP2 Filter
{
public:
	Filter(Filter const &);
	Filter(void);
	Filter & operator=(class Filter const &);
	static Filter * __fastcall GetCapture(void);
	virtual int OnUIEvent(IWnd *,unsigned int,unsigned int,long,int);
	void ReleaseCapture(IWnd *);
	void SetCapture(IWnd *,int);
private:
	static FilterNode *pCaptureNode;
};

class OP2 GroupFilter
{
public:
	GroupFilter(GroupFilter const &);
	GroupFilter(void);
	class GroupFilter & operator=(GroupFilter const &);
	class SubFilter * GetSubFilter(void)const ;
	virtual int OnUIEvent(IWnd *,unsigned int,unsigned int,long,int);
	void SetSubFilter(SubFilter *);
};

class OP2 SubFilter
{
public:
	SubFilter(SubFilter const &);
	SubFilter(void);
	SubFilter & operator=(SubFilter const &);
	virtual int OnUIEvent(IWnd *,unsigned int,unsigned int,long,int);
	void ReleaseCapture(GroupFilter *,IWnd *);
	void SetCapture(GroupFilter *,IWnd *,int);
};
