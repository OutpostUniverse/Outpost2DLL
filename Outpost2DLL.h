#pragma once


// Note: This is the main DLL SDK include file. Including this file
//		 will in turn include every other header file which defines
//		 the exports from Outpost2.exe needed for level programming
//		 and the header files that define the exports from the
//		 level DLLs needed for Outpost2.exe to recognize the level.


// Include all the header files which contain
// defintions of exports from Outpost2.exe
#include "game/MapIdEnum.h"
#include "game/Enums.h"
#include "game/Structs.h"
#include "game/Player.h"
#include "game/Unit.h"
#include "game/UnitBlock.h"
#include "game/ScStub.h"
#include "game/Groups.h"
#include "game/Trigger.h"
#include "game/Enumerators.h"
#include "game/TethysGame.h"
#include "game/GameMap.h"
#include "game/NonExportedEnums.h"
#include "game/Globals.h"
// Include the header file which contains definitions
// of required exports from the level DLL
#include "game/RequiredExports.h"
