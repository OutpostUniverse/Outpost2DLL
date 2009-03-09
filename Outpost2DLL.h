#pragma once

// Add reference to the import library
#pragma comment(lib, "../../API/Outpost2DLL/Lib/Outpost2DLL")
// Replace the C-RunTime (CRT) with a customized smaller one
#pragma comment(lib, "../../API/Outpost2DLL/Lib/LibCTiny")
#pragma comment(linker, "/nodefaultlib:libcmt.lib")


// Note: This is the main DLL SDK include file. Including this file
//		 will in turn include every other header file which defines
//		 the exports from Outpost2.exe needed for level programming
//		 and the header files that define the exports from the 
//		 level DLLs needed for Outpost2.exe to recognize the level.


// Include all the header files which contain 
// defintions of exports from Outpost2.exe
#include "MapIdEnum.h"
#include "Enums.h"
#include "Structs.h"
#include "Player.h"
#include "Unit.h"
#include "UnitBlock.h"
#include "ScStub.h"
#include "Groups.h"
#include "Trigger.h"
#include "Enumerators.h"
#include "TethysGame.h"
#include "GameMap.h"
#include "NonExportedEnums.h"
#include "Globals.h"
// Include the header file which contains definitions
// of required exports from the level DLL
#include "RequiredExports.h"
