#pragma once

// Note: This file is used to define the required exports from each level
//		 DLL that are needed in order for Outpost 2 to recognize the DLL
//		 as a level.


// A define used to make exporting functions and variables easier
#define Export extern "C" __declspec(dllexport)


// Mission types, and the corresponding DLL name prefix
// Note: For campaign games, use a positive level number, and a prefix of e (Eden) or p (Plymouth)
// Note: Multiplayer games include the max number of players (denoted by <x>).
//   Example: ml6_99.dll  (Multiplayer, Last One Standing, Max of 6 players)
enum MissionTypes
{
	Colony					= -1, //0xFF	// c
	AutoDemo				= -2, //0xFF	// a
	Tutorial				= -3, //0xFD	// t

	MultiLandRush			= -4, //0xFC	// mu<x>
	MultiSpaceRace			= -5, //0xFB	// mf<x>
	MultiResourceRace		= -6, //0xFA	// mr<x>
	MultiMidas				= -7, //0xF9	// mm<x>
	MultiLastOneStanding	= -8, //0xF8	// ml<x>
};

#pragma pack(push, 1)

// Structure for important data exports needed for OP2 to recognize the level
struct AIModDesc
{
	// Important level details
	int missionType;			// Mission type (defined above) or mission number (positive values) for campaign games
	int numPlayers;				// Number of players (on a multipalyer map)
	int maxTechLevel;			// Maximum tech level (Set to 12 to enable all techs)
	int boolUnitMission;		// Set to 1 to disable most reports (suitable for unit-only missions)
	// Extra baggage that doesn't need to be set properly
	const char* mapName;
	const char* levelDesc;
	const char* techtreeName;
	int checksum;
};

static_assert(32 == sizeof(AIModDesc), "AIModDesc is an unexpected size");

// Struct introduced in the official Sierra release update pack 1 (1.2.0.7)
// Set aiPlayerCount to 1 to allow a computer controlled AI in a multiplayer scenario
// Example: Export AIModDescEx aiModDescEx = { 1 };
struct AIModDescEx {
	int aiPlayerCount;
	int unused[7];
};

static_assert(32 == sizeof(AIModDescEx), "AIModDesc is an unexpected size");

#pragma pack(pop)

// Helper Macros to define the required data exports

// Full level details for Outpost 2 version 1.2.0.5 and up
// Needed for unit only missions, or non-standard tech level settings
// Does not support multiplayer AI (added in Outpost 2 versions 1.2.0.7)
#define ExportLevelDetailsFull(levelDesc, mapName, techTreeName, missionType, numPlayers, maxTechLevel, bUnitOnlyMission) \
	Export const char MapName[] = mapName; \
	Export const char LevelDesc[] = levelDesc; \
	Export const char TechtreeName[] = techTreeName; \
	Export const AIModDesc DescBlock = { missionType, numPlayers, maxTechLevel, bUnitOnlyMission, MapName, LevelDesc, TechtreeName, 0 };

// Simplified level details for Outpost 2 version 1.2.0.5 and up
// Suitable for most levels (colony, campaign, multiplayer), except unit only missions
#define ExportLevelDetails(levelDesc, mapName, techTreeName, missionType, numPlayers) \
	ExportLevelDetailsFull(levelDesc, mapName, techTreeName, missionType, numPlayers, (missionType > 0) ? missionType : 12, false)

// Deprecated macro. Renamed to ExportLevelDetailsFull
// The name is potentially confusing as it did not create a `DescBlockEx` export
// May be replaced by an incompatible macro in future versions of the SDK
#define ExportLevelDetailsEx(levelDesc, mapName, techTreeName, missionType, numPlayers, maxTechLevel, bUnitOnlyMission) \
	__pragma(message("Warning: `ExportLevelDetailsEx` has been deprecated. Please use `ExportLevelDetailsFull` instead")) \
	ExportLevelDetailsFull(levelDesc, mapName, techTreeName, missionType, numPlayers, maxTechLevel, bUnitOnlyMission)

// Full level details for Outpost 2 version 1.2.0.7 and up
// Needed for multiplayer AI support
// Supports all level configurations, including multiplayer AI
#define ExportLevelDetailsFullEx(levelDesc, mapName, techTreeName, missionType, numPlayers, maxTechLevel, bUnitOnlyMission, numAiPlayers) \
	ExportLevelDetailsFull(levelDesc, mapName, techTreeName, missionType, numPlayers, maxTechLevel, bUnitOnlyMission) \
	Export const AIModDescEx DescBlockEx = { numAiPlayers };

#pragma pack(push, 1)

// This struct defined a memory region to be Saved/Loaded to/from saved game files.
// Note: See GetSaveRegions exported function
// Note: This implies all level data must be statically declared. Avoid using "new".
// Note: Setting bufferStart to 0 means no data (include buffer size) is present in the saved game file
// Note: Setting bufferStart to non-zero and length to 0 means the size (4 bytes) is written to the saved game file.
struct BufferDesc
{
	void *bufferStart;	// pointer to beginning of DLL data buffer
	int length;			// length of this buffer
};

static_assert(8 == sizeof(BufferDesc), "BufferDesc is an unexpected size");

#pragma pack(pop)

// Generate function to return global variable struct to Outpost2.exe for game save/load
#define ExportSaveLoadData(globalVarStructName) \
	Export void __cdecl GetSaveRegions(BufferDesc& bufferDesc) \
	{ \
		bufferDesc.bufferStart = &globalVarStructName; \
		bufferDesc.length = sizeof(globalVarStructName); \
	}
// Generate function to return a lack of global variables for game save/load
#define ExportSaveLoadDataNone() \
	Export void __cdecl GetSaveRegions(BufferDesc& bufferDesc) \
	{ \
		bufferDesc.bufferStart = 0; \
		bufferDesc.length = 0; \
	}
