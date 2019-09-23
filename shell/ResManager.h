#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif

// Outpost2 uses the ResManager to locate and load game resources.
// It also includes functions to check for the existence of the CD.
// (Most CD checks are no longer functional, allowing play without a CD).

class StreamIO;

class OP2 ResManager
{
public:
	ResManager & operator=(ResManager const &);
	unsigned int ChecksumStream(char const *);
	StreamIO* CreateStream(char const *);
	int FindCDRoot(char *);
	void GetCDDir(char *);
	int GetFilePath(char const *, char *);
	void GetInstalledDir(char *);
	int Init(void);
	int InitCDDir(void);
	void InitInstalledDir(void);
	void* LockStream(char const *, int *);
	StreamIO* OpenStream(char const *);
	void ReleaseStream(StreamIO *);
	void ShutDown(void);
	void UnlockStream(void *);
	void VerifyCD(void);
};

// Global ResManager object that should be used, instead of creating a new ResManager
OP2 ResManager g_ResManager;
