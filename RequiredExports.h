
// Note: This file is used to define the required exports from each level
//		 DLL that are needed in order for Outpost 2 to recognize the DLL
//		 as a level.


// A define used to make exporting functions and variables easier
#define SCRIPT_API extern "C" __declspec(dllexport)
#define Export extern "C" __declspec(dllexport)


// missionType defines (and prefix needed on the DLL name)
// Note: For campaign games, use a positive number
//		 which corresponds to the level number.
enum MissionTypes
{
	Colony					= -1, //0xFF	// c
	AutoDemo				= -2, //0xFF	// a
	Tutorial				= -3, //0xFD	// t

	MultiLandRush			= -4, //0xFC	// mu(x)
	MultiSpaceRace			= -5, //0xFB	// mf(x)
	MultiResourceRace		= -6, //0xFA	// mr(x)
	MultiMidas				= -7, //0xF9	// mm(x)
	MultiLastOneStanding	= -8, //0xF8	// ml(x)
};


// Structure for important data exports needed for OP2 to recognize the level
struct AIModDesc
{
	// Important level details
	int missionType;			// Mission type (defined above) or mission number (positive values) for campaign games
	int numPlayers;				// Number of players (on a multipalyer map)
	int maxTechLevel;			// Maximum tech level (Set to 12 to enable all techs)
	int boolUnitMission;		// Set to 1 to disable most reports (suitable for unit-only missions)
	// Extra baggage that doesn't need to be set properly
	char* mapName;
	char* levelDesc;
	char* techtreeName;
	int checksum;
};

// ** Debug **  (Deprecated)
typedef AIModDesc SDescBlock;


#define ExportLevelDetails(levelDesc, mapName, techTreeName, missionType, numPlayers) \
	Export char MapName[] = mapName; \
	Export char LevelDesc[] = levelDesc; \
	Export char TechtreeName[] = techTreeName; \
	Export AIModDesc DescBlock = { missionType, numPlayers, (missionType > 0) ? missionType : 12, false, MapName, LevelDesc, TechtreeName, 0 }; \

#define ExportLevelDetailsEx(levelDesc, mapName, techTreeName, missionType, numPlayers, maxTechLevel, bUnitOnlyMission) \
	Export char MapName[] = mapName; \
	Export char LevelDesc[] = levelDesc; \
	Export char TechtreeName[] = techTreeName; \
	Export AIModDesc DescBlock = { missionType, numPlayers, maxTechLevel, bUnitOnlyMission, MapName, LevelDesc, TechtreeName, 0 };


// Structure for specifying DLL specific data to write to saved game files.
// It is used as a return parameter in the GetSaveRegions export.
struct BufferDesc
{
	void *bufferStart;	// pointer to beginning of DLL data buffer
	int length;			// length of this buffer
};


// Note: These are the required exported variables. They define important
//		 level parameters such as what map file is used, what tech file is
//		 used, and what description to place in the level list box. A
//		 structure is also exported to give additional mission info
//		 (some of which corresponds to the naming of the DLL).

// ** DEBUG **  (Deprecated)
Export char MapName[];			// Holds the file name of the .map file
Export char LevelDesc[];		// Description that appears in the list/menu 
Export char TechtreeName[];		// The tech tree to use for this level
Export AIModDesc DescBlock;		// Exports game info


// Note: These functions are required exports from all level DLLs.
//		 If these functions are not found by Outpost2.exe, the game
//		 will not load the level.
// Note: These functions control the initial startup of the level, anything
//		 that may require continual execution (like AI procedures, even though
//		 this function is usually left empty) and specifying the data that
//		 needs to be stored to saved game files.

// ** DEBUG **  (Deprecated)
Export int  __cdecl InitProc();			// Called on mission startup
Export void __cdecl AIProc();			// Can be used to implement an AI (Called every game cycle)
Export void __cdecl GetSaveRegions(struct BufferDesc &bufDesc);	// Used to return a buffer description to OP2 for storing data to saved game files

// Note: The following two exports are not strictly required but are
//		 usually found in all level DLLs.
//Export int  __cdecl StatusProc();			// Unused, returns 0
//Export void __cdecl NoResponseToTrigger();	// Used for triggers with no custom effects

