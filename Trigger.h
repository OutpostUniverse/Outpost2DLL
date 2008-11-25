#pragma once

#include "ScStub.h"

// Forward declares
class Unit;
class ScGroup;

// Note: This is the trigger class returned by all the trigger creation
//		 functions. It can be used to control an active trigger.
// Note: The trigger class is only a stub that refers to an internal
//		 class that handles the trigger. It is seldom necessary to use
//		 this class to control a trigger and it is usually destroyed
//		 shortly after it is returned from the trigger creation function.

class OP2 Trigger : public ScStub
{
public:
	Trigger();
	~Trigger() {};
	Trigger& operator = (const Trigger& trigger);

	void Disable();
	void Enable();
	int HasFired(int);
};


// Trigger creation functions
// **************************

// Victory/Failure condition triggers
OP2 Trigger __fastcall CreateVictoryCondition(int boolEnable, int /*Must be zero*/, Trigger& victoryTrigger, char const *missionObjective);
OP2 Trigger __fastcall CreateFailureCondition(int boolEnable, int ignoredParam, Trigger& failureTrigger, char const *notUsed);

// Other triggers
OP2 Trigger __fastcall CreateBuildingCountTrigger(int bEnabled, int bOneShot, int playerNum, int refCount, enum compare_mode, char const *triggerFunction);
OP2 Trigger __fastcall CreateVehicleCountTrigger(int bEnabled, int bOneShot, int playerNum, int refCount, enum compare_mode compareType, char const *triggerFunction);
OP2 Trigger __fastcall CreateCountTrigger(int bEnabled, int bOneShot, int playerNum, enum map_id unitType, enum map_id cargoOrWeapon, int refCount, enum compare_mode compareType, char const *triggerFunction);
OP2 Trigger __fastcall CreateAttackedTrigger(int bEnabled, int bOneShot, ScGroup& group, char const *triggerFunction);
OP2 Trigger __fastcall CreateDamagedTrigger(int bEnabled, int bOneShot, ScGroup& group, int damage, char const *triggerFunction);
OP2 Trigger __fastcall CreateEscapeTrigger(int bEnabled, int bOneShot, int playerNum, int x, int y, int width, int height, int refValue, enum map_id unitType, int cargoType, int cargoAmount, char const *triggerFunction);
OP2 Trigger __fastcall CreateEvacTrigger(int bEnabled, int bOneShot, int playerNum, char const *triggerFunction);
OP2 Trigger __fastcall CreateKitTrigger(int bEnabled, int bOneShot, int playerNum, enum map_id, int refCount, char const *triggerFunction);
OP2 Trigger __fastcall CreateMidasTrigger(int bEnabled, int bOneShot, int time, char const *triggerFunction);
OP2 Trigger __fastcall CreateOnePlayerLeftTrigger(int bEnabled, int bOneShot, char const *triggerFunction);
OP2 Trigger __fastcall CreateOperationalTrigger(int bEnabled, int bOneShot, int playerNum, enum map_id buildingType, int refValue, enum compare_mode compareType, char const *triggerFunction);
OP2 Trigger __fastcall CreatePointTrigger(int bEnabled, int bOneShot, int playerNum, int x, int y, char const *triggerFunction);
OP2 Trigger __fastcall CreateRectTrigger(int bEnabled, int bOneShot, int playerNum, int x, int y, int width, int height, char const *triggerFunction);
OP2 Trigger __fastcall CreateResearchTrigger(int bEnabled, int bOneShot, int techID, int playerNum, char const *triggerFunction);
OP2 Trigger __fastcall CreateResourceTrigger(int bEnabled, int bOneShot, enum trig_res resourceType, int refAmount, int playerNum, enum compare_mode compareType, char const *triggerFunction);
OP2 Trigger __fastcall CreateTimeTrigger(int bEnabled, int bOneShot, int timeMin, int timeMax, char const *triggerFunction);
OP2 Trigger __fastcall CreateTimeTrigger(int bEnabled, int bOneShot, int time, char const *triggerFunction);
OP2 Trigger __cdecl CreateSetTrigger(int bEnabled, int bOneShot, int totalTriggers, int neededTriggers, char const *triggerFunction, ...); // +list of triggers

OP2 Trigger __fastcall CreateSpecialTarget(int boolEnable, int boolNoRepeat, Unit& specialTarget /* Lab */, enum map_id sourceUnitType /* mapScout */, char const *triggerFunction);
OP2 void __fastcall GetSpecialTargetData(Trigger& specialTargetTrigger, Unit& sourceUnit /* Scout */);

