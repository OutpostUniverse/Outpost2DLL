#pragma once

// AIModDesc structure and related functions.
// Outpost2 uses an AIModDesc structure to store and pass information about a mission DLL.

// Structure declaration
struct AIModDesc
{
	DescBlock descBlock;
	char *pMapName;
	char *pLevelDesc;
	char *pTechtreeName;
	long unknown;
};

// Retrieves the AIModDesc for a given DLL name.
OP2 AIModDesc* __fastcall GetModuleDesc(char const *filename);

// Frees the AIModDesc returned from a previous GetModuleDesc call.
OP2 void __fastcall FreeModuleDesc(AIModDesc* desc);
