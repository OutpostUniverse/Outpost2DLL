#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif

// OP2 INI config class.
class OP2 CConfig
{
public:
	CConfig(char const *filename);
	~CConfig();
	CConfig & operator=(CConfig const &);
	int CopyIniFile(char const *);
	int FileExists();
	void Flush();
	int GetInt(char const *, char const *, int);
	int GetInt(char const *, int);
	int GetString(char const *, char const *, char *, unsigned int, char const *);
	int GetString(char const *, char *, unsigned int, char const *);
	int SetInt(char const *, char const *, int);
	int SetInt(char const *, int);
	int SetString(char const *, char const *, char const *);
	int SetString(char const *, char const *);
};

OP2 CConfig gConfigFile;
