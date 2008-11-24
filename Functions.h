

// Note: The following are all the functions exported from Outpost2.exe that
//		 don't belong to a class, and a data export for the players. The
//		 functions largely deal with creating groups and triggers (which 
//		 can't be created using only their constructors and will crash the
//		 game if you try it this way). There is also the very useful 
//		 scr_snprintf used for collecting output into a string buffer that 
//		 may then be displayed using a method such as TethysGame::AddMessage.



// Group creation functions
// ************************

OP2 class BuildingGroup __fastcall CreateBuildingGroup(class _Player owner);
OP2 class FightGroup __fastcall CreateFightGroup(class _Player owner);
OP2 class MiningGroup __fastcall CreateMiningGroup(class _Player owner);
OP2 class Pinwheel __fastcall CreatePinwheel(class _Player &owner);

// Trigger creation functions
// **************************

// Victory/Failure condition triggers
OP2 class Trigger __fastcall CreateVictoryCondition(int boolEnable, int /*Must be zero*/, class Trigger &victoryTrigger, char const *missionObjective);
OP2 class Trigger __fastcall CreateFailureCondition(int boolEnable, int ignoredParam, class Trigger &failureTrigger, char const *notUsed);

// Other triggers
OP2 class Trigger __fastcall CreateBuildingCountTrigger(int bEnabled, int bOneShot, int playerNum, int refCount, enum compare_mode, char const *triggerFunction);
OP2 class Trigger __fastcall CreateVehicleCountTrigger(int bEnabled, int bOneShot, int playerNum, int refCount, enum compare_mode compareType, char const *triggerFunction);
OP2 class Trigger __fastcall CreateCountTrigger(int bEnabled, int bOneShot, int playerNum, enum map_id unitType, enum map_id cargoOrWeapon, int refCount, enum compare_mode compareType, char const *triggerFunction);
OP2 class Trigger __fastcall CreateAttackedTrigger(int bEnabled, int bOneShot, class ScGroup &, char const *triggerFunction);
OP2 class Trigger __fastcall CreateDamagedTrigger(int bEnabled, int bOneShot, class ScGroup &, int damage, char const *triggerFunction);
OP2 class Trigger __fastcall CreateEscapeTrigger(int bEnabled, int bOneShot, int playerNum, int x, int y, int width, int height, int refValue, enum map_id unitType, int cargoType, int cargoAmount, char const *triggerFunction);
OP2 class Trigger __fastcall CreateEvacTrigger(int bEnabled, int bOneShot, int playerNum, char const *triggerFunction);
OP2 class Trigger __fastcall CreateKitTrigger(int bEnabled, int bOneShot, int playerNum, enum map_id, int refCount, char const *triggerFunction);
OP2 class Trigger __fastcall CreateMidasTrigger(int bEnabled, int bOneShot, int time, char const *triggerFunction);
OP2 class Trigger __fastcall CreateOnePlayerLeftTrigger(int bEnabled, int bOneShot, char const *triggerFunction);
OP2 class Trigger __fastcall CreateOperationalTrigger(int bEnabled, int bOneShot, int playerNum, enum map_id buildingType, int refValue, enum compare_mode compareType, char const *triggerFunction);
OP2 class Trigger __fastcall CreatePointTrigger(int bEnabled, int bOneShot, int playerNum, int x, int y, char const *triggerFunction);
OP2 class Trigger __fastcall CreateRectTrigger(int bEnabled, int bOneShot, int playerNum, int x, int y, int width, int height, char const *triggerFunction);
OP2 class Trigger __fastcall CreateResearchTrigger(int bEnabled, int bOneShot, int techID, int playerNum, char const *triggerFunction);
OP2 class Trigger __fastcall CreateResourceTrigger(int bEnabled, int bOneShot, enum trig_res resourceType, int refAmount, int playerNum, enum compare_mode compareType, char const *triggerFunction);
OP2 class Trigger __fastcall CreateTimeTrigger(int bEnabled, int bOneShot, int timeMin, int timeMax, char const *triggerFunction);
OP2 class Trigger __fastcall CreateTimeTrigger(int bEnabled, int bOneShot, int time, char const *triggerFunction);
OP2 class Trigger __cdecl CreateSetTrigger(int bEnabled, int bOneShot, int totalTriggers, int neededTriggers, char const *triggerFunction, ...); // +list of triggers

OP2 class Trigger __fastcall CreateSpecialTarget(int boolEnable, int boolNoRepeat, class Unit & specialTarget /* Lab */, enum map_id sourceUnitType /* mapScout */, char const *triggerFunction);
OP2 void __fastcall GetSpecialTargetData(class Trigger & specialTargetTrigger, class Unit & sourceUnit /* Scout */);

// Output preparation function
// See the "snprintf" documentation in a C language reference.
// Note: This function does not actually output any text to the screen.
//		 All it does is collect input into a single string which may then
//		 be passed to a method such as TethysGame::AddMessage to actually
//		 output the text.
OP2 int __cdecl scr_snprintf(char *writeBuffer, unsigned int bufferLength, char const *formatString, ...);





// Note: Here is the only exported variable from Outpost2.exe used for
//		 level programming. It consists of an array of 7 players
//		 (numbered 0-6) which can be used to manipulate all the players
//		 in the level. See Player.h for details.

OP2 class _Player Player[7];



