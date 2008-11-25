#pragma once

// Note: This file is used to define all the group related classes exported
//		 from Outpost2.exe. It also contains the Pinwheel class (which is
//		 like a group class in many ways) and the Trigger class (which
//		 derives from the same base class as all the others).


#include "ScStub.h"


// Forward declare
enum map_id;
enum UnitClassifactions;
struct LOCATION;
struct MAP_RECT;
struct MrRec;
struct PWDef;
struct PatrolRoute;
class UnitBlock;
class Unit;


// Note: ScGroup is the main parent class of all other group classes.
//		 Any functions defined here on this class are available to any
//		 instance of the derived classes.
// Note: Do not try to create an instance of this class. It was meant
//		 simply as a base parent class from which other classes inherit
//		 functions from. Creating an instance of this class serves little
//		 (or no) purpose and may even crash the game.

class OP2 ScGroup : public ScStub
{
public:
	ScGroup();
	~ScGroup() {};
	ScGroup& operator = (const ScGroup& scGroup);

	void AddUnits(UnitBlock& unitsToAdd);
	void ClearTargCount();
	int GetFirstOfType(Unit& returnedUnit, UnitClassifactions unitType);
	int GetFirstOfType(Unit& returnedUnit, map_id unitType, map_id cargoOrWeapon);
	int HasBeenAttacked();
	void RemoveUnit(Unit unitToRemove);
	void SetDeleteWhenEmpty(int boolDelete);
	void SetLights(int boolOn);
	void SetTargCount(UnitBlock& unitTypes);
	void SetTargCount(map_id unitType, map_id weaponType, int targetCount);
	void TakeAllUnits(ScGroup& groupToAdd);
	void TakeUnit(Unit unitToAdd);
	int TotalUnitCount();
	int UnitCount(UnitClassifactions criteria);
};


// Note: Do not try to create any of the following classes using only their
//		 constructors. Doing so will likely crash the game. Instead, create
//		 these classes by calling the group creation functions defined in
//		 Functions.h.


// Note: The BuildingGroup class is used to control Structure Factories,
//		 ConVecs, and Earthworkers to build/rebuild a base.

class OP2 BuildingGroup : public ScGroup
{
public:
	BuildingGroup();
	~BuildingGroup() {};
	BuildingGroup& operator = (const BuildingGroup& buildingGroup);

	void RecordBuilding(LOCATION &buildingLocation, map_id unitType, map_id cargoOrWeapon);
	void RecordBuilding(LOCATION &buildingLocation, map_id unitType, map_id cargoOrWeapon, ScGroup&);
	void RecordTube(LOCATION& tubeLocation);
	void RecordTubesTouching(LOCATION &startLocation);
	void RecordUnitBlock(UnitBlock&);
	void RecordUnitBlock(UnitBlock&, ScGroup&);
	void RecordVehReinforceGroup(ScGroup& targetGroup, int priority); // 0 = lowest priority, 0xFFFF = highest
	void RecordWall(LOCATION& location, map_id);
	void SetRect(MAP_RECT &defaultLocation);
	void UnRecordVehGroup(ScGroup& group);
};


// Note: The MiningGroup is a class used to setup mining routes with
//		 cargo trucks.

class OP2 MiningGroup : public ScGroup
{
public:
	MiningGroup();
	~MiningGroup() {};
	MiningGroup& operator = (const MiningGroup& miningGroup);

	void Setup(LOCATION& mine, LOCATION& smelter, MAP_RECT&);
	void Setup(LOCATION& mine, LOCATION& smelter, map_id mineType, map_id smelterType, MAP_RECT &);
	void Setup(Unit mine, Unit smelter, MAP_RECT& smelterArea);
};


// Note: The FightGroup class is used to control military units and is
//		 used to attack or defend a base. It can be used to cause an AI
//		 to produce units at a Vehicle Factory to attack with.

class OP2 FightGroup : public ScGroup
{
public:
	FightGroup();
	~FightGroup() {};
	FightGroup& operator = (const FightGroup& fightGroup);

	void AddGuardedRect(MAP_RECT&);
	void ClearCombineFire();
	void ClearGuarderdRects();
	void ClearPatrolMode();
	void DoAttackEnemy();
	void DoAttackUnit();
	void DoExitMap();
	void DoGuardGroup();
	void DoGuardRect();
	void DoGuardUnit();
	void DoPatrolOnly();
	void SetAttackType(map_id);	// Use in combination with DoAttackEnemy()
	void SetCombineFire();
	void SetFollowMode(int);
	void SetPatrolMode(PatrolRoute &waypts);
	void SetRect(MAP_RECT&);
	void SetTargetGroup(ScGroup); // Use in combination with DoGuardGroup()
	void SetTargetUnit(Unit);
};


// Note: The Pinwheel class seems to be used for controlling waves
//		 of attacks.

class OP2 Pinwheel : public ScStub
{
public:
	Pinwheel();
	~Pinwheel() {};
	Pinwheel& operator = (const Pinwheel& pinwheel);

	void SendWaveNow(int);
	void SetAttackComp(int, int, MrRec*);
	void SetAttackFraction(int attackFraction);
	void SetContactDelay(int);
	void SetGuardComp(int, int, MrRec*);
	void SetNoRange(int, int);
	void SetPoints(PWDef*);
	void SetSapperComp(int, int, MrRec*);
	void SetWavePeriod(int minTime, int maxTime);
};


// Group creation functions
// ************************

OP2 class MiningGroup __fastcall CreateMiningGroup(class _Player owner);
OP2 class BuildingGroup __fastcall CreateBuildingGroup(class _Player owner);
OP2 class FightGroup __fastcall CreateFightGroup(class _Player owner);
OP2 class Pinwheel __fastcall CreatePinwheel(class _Player &owner);

