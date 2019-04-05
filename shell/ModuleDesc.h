#pragma once

// Outpost2 uses an AIModDesc structure to store and pass information about a mission DLL.
// See RequiredExports.h for the full definition of AIModDesc.

struct AIModDesc;


// Retrieves the AIModDesc for a given DLL name.
// When done, pass the returned pointer to FreeModuleDesc
OP2 AIModDesc* __fastcall GetModuleDesc(char const *filename);

// Frees the AIModDesc returned from a previous GetModuleDesc call.
OP2 void __fastcall FreeModuleDesc(AIModDesc* desc);
