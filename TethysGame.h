
// Note: This file contains the defintion of the TethysGame class and 
//		 GameMap class exported from Outpost2.exe. These two classes
//		 control the map and overall game environment of the level.


// Forward declares
enum map_id;
enum SongIds;
struct LOCATION;
class Unit;
class _Player;

// Note: The TethysGame class controls creation of units and disasters, 
//		 sending custom in game messages to the player, playing recorded 
//		 sounds for extra effects (you still have no control over the 
//		 default sounds the game engine plays by itself), morale controls,
//		 day and night controls, and more!
//		 It also provides some useful information on the current game.
//		 Basically anything related to the game as a whole is done through
//		 this class.
// Note: This class has all static member functions and no local variables.
//		 Don't try to create an instance of this class. You don't need to 
//		 create your own and you aren't meant to do it. Just use the 
//		 class namespace for all your Outpost 2 level needs. =)
//		 Example: numberOfPlayers = TethysGame::NoPlayers();

class OP2 TethysGame
{
public:
	TethysGame& operator = (const TethysGame& tethysGame);

	// Player Number and Number of Players
	static int __fastcall LocalPlayer();			// Returns the local player index
	static int __fastcall NoPlayers();				// Returns number of players (including both Human and AI)

	// Multiplayer game options  [Get Property]
	static int __fastcall UsesDayNight();
	static int __fastcall UsesMorale();
	static int __fastcall CanHaveDisasters();
	static int __fastcall InitialUnits();		// Number of Laser/Microwave Lynx to start with
	static int __fastcall CanAllowCheats();		// Useless

	// Game Time
	static int __fastcall Tick();	// Current time (tick is the smallest slice of game time)
	static int __fastcall Time();	// Current tick / 4  (most processing is only done every 4 ticks)

	// Game Sounds and Voice warnings
	//  Note: SoundIndex = 94..227 [Inclusive] are recorded voice messages
	static void __fastcall AddGameSound(int soundIndex, int toPlayerNum);			// Note: toPlayerNum: -1 = PlayerAll
	static void __fastcall AddMapSound(int soundIndex, LOCATION location);
	// Message log
	static void __fastcall AddMessage(int pixelX, int pixelY, char *message, int toPlayerNum, int soundIndex);	// Note: toPlayerNum: -1 = PlayerAll
	static void __fastcall AddMessage(Unit owner, char *message, int toPlayerNum, int soundIndex);				// Note: toPlayerNum: -1 = PlayerAll

	// Debug/Cheat flags
	static void __fastcall SetDaylightEverywhere(int boolOn);
	static void __fastcall SetDaylightMoves(int boolOn);
	// Cheat flags  [gutted and useless by official Sierra update]
	static void __fastcall SetCheatFastProduction(int boolOn);			// Useless
	static void __fastcall SetCheatFastUnits(int boolOn);				// Useless
	static void __fastcall SetCheatProduceAll(int boolOn);				// Useless
	static void __fastcall SetCheatUnlimitedResources(int boolOn);		// Useless

	// Unit Creation  [Returns: int numUnitsCreated]
	static int __fastcall CreateUnit(Unit& returnedUnit, map_id unitType, LOCATION location, int playerNum, map_id weaponCargoType, int rotation);	// Note: see enum UnitDirection
	static int __fastcall CreateBeacon(map_id beaconType, int tileX, int tileY, int commonRareType, int barYield, int barVariant);	// Note: see enums BeacondTypes, Yield, Variant
	static int __fastcall CreateWreck(int tileX, int tileY, map_id techID, int bInitiallyVisible);		// Note: techID must be >= 8000 but < (8000+4096) = 12096
	static int __fastcall PlaceMarker(Unit& returnedUnit, int tileX, int tileY, int markerType);		// Note: See enum MarkerTypes
	static int __fastcall CreateWallOrTube(int tileX, int tileY, int unused, map_id wallTubeType);		// Returns: 1 [true] always
	static int __fastcall CreateUnitBlock(_Player& ownerPlayer, const char* exportName, int bLightsOn);	// Returns: numUnitsCreated,  Note: see class UnitBlock

	// Morale Level
	//  Note: playerNum: -1 = PlayerAll
	//  Note: Calling ForceMoraleX functions after tick 0 will cause a "Cheated Game!" message to appear. FreeMoraleLevel can be called any time.
	//  Bug: ForceMoraleX is buggy if playerNum is not -1. You may need to call the function twice for the correct effect (see Forum post). FreeMoraleLevel is not affected by this bug.
	static void __fastcall ForceMoraleGreat(int playerNum);		
	static void __fastcall ForceMoraleGood(int playerNum);		
	static void __fastcall ForceMoraleOK(int playerNum);		
	static void __fastcall ForceMoralePoor(int playerNum);		
	static void __fastcall ForceMoraleRotten(int playerNum);	
	static void __fastcall FreeMoraleLevel(int playerNum);		// Let Morale vary according to colony state and events

	// Random number generation
	static void __fastcall SetSeed(unsigned int randNumSeed);	// Set random number seed
	static int __fastcall GetRand(int range);					// Returns a number from 0..(range-1)

	// Disaster Creation
	static void __fastcall SetMeteor(int tileX, int tileY, int size);
	static void __fastcall SetEarthquake(int tileX, int tileY, int magnitude);
	static void __fastcall SetEruption(int tileX, int tileY, int spreadSpeed);
	static void __fastcall SetLightning(int startTileX, int startTileY, int duration, int endTileX, int endTileY);
	static void __fastcall SetTornado(int startTileX, int startTileY, int duration, int endTileX, int endTileY, int bImmediate);
	// Disaster spread speed
	static void __fastcall SetLavaSpeed(int spreadSpeed);
	static void __fastcall SetMicrobeSpreadSpeed(int spreadSpeed);

	// EMP Missile
	//  Note: FindEMPMissileTarget searches aligned 8x8 blocks, for the block with the greatest weight. Target player military units weigh 64, non-target player military units weigh -32, and non-target player non-military units weigh 1.
	static LOCATION __fastcall FindEMPMissleTarget(int startTileX, int startTileY, int endTileX, int endTileY, int destPlayerNum);
	static void __fastcall SetEMPMissile(int launchTileX, int launchTileY, int setToZero, int destTileX, int destTileY);	// Set third param to 0

	// Save/Load Games
	static void __fastcall SaveGame(const char* savedGameName);		// Note: Unimplemented  [Useless]
	static void __fastcall LoadGame(const char* savedGameName);		// Note: Saved game names default to: "SGAME?.OP2" file name format

	// Misc
	static void __fastcall SetMusicPlayList(int numSongs, int repeatStartIndex, SongIds* songIdList);

private:
	static void __fastcall sIssueOptPacket(int variableId, int newValue);
};



// Note: This class is used to control the displayed tiles on the map as well
//		 as the movement/passability characteristics of the terrain.
// Note: This class has all static member functions and no local variables.
//		 Don't try to create an instance of this class. You don't need to 
//		 create your own and you aren't meant to do it. Just use the 
//		 class namespace for all your Outpost 2 level needs. =)
//		 Example: GameMap::SetInitialLightLevel(0);

class OP2 GameMap
{
public:
	GameMap& operator = (const GameMap& gameMap);
	static int __fastcall GetCellType(LOCATION location);
	static int __fastcall GetTile(LOCATION location);
	static void __fastcall InitialSetTile(LOCATION location, int tileIndex);
	static void __fastcall SetTile(LOCATION location, int tileIndex);
	static void __fastcall SetCellType(LOCATION location, int cellIndex);
	static void __fastcall SetLavaPossible(LOCATION location, int bLavaPossible);
	static void __fastcall SetVirusUL(LOCATION location, int spreadSpeed);
	static void __fastcall SetInitialLightLevel(int lightPosition);
};

