#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif

// Note: This file is used to define the enumerator classes exported
//		 from Outpost2.exe. These classes can be used to search for
//		 or traverse a list of units one unit at a time.


#include "MapIdEnum.h"

// External type names
struct LOCATION;
struct MAP_RECT;
class ScGroup;
class Unit;

// Private UnitNode structure that should have no external access
struct UnitNode
{
	UnitNode* prev;		// ** Maybe? (Guessed)
	UnitNode* next;
	Unit* unit;
};

static_assert(12 == sizeof(UnitNode), "UnitNode is an unexpected size");


// ------------------------------------------------------------------------
// Note: All Enumerators implement a GetNext function, which returns
//	0 if no Unit was found, or non-zero if a Unit was found.
//	If a Unit was found, then it's index is returned in the Unit proxy/stub
//	passed as the first parameter.
// ------------------------------------------------------------------------


// Group (enumerate all units in a group)
class OP2 GroupEnumerator
{
public:
	GroupEnumerator(ScGroup& group);
	GroupEnumerator& operator = (const GroupEnumerator& groupEnum);
	int GetNext(Unit& currentUnit);
public:	// Why not? =)
	UnitNode* currentUnitNode;
};

static_assert(4 == sizeof(GroupEnumerator), "GroupEnumerator is an unexpected size");

// Vehicles (enumerate all vehicles for a certain player)
class OP2 PlayerVehicleEnum
{
public:
	PlayerVehicleEnum(int playerNum);
	PlayerVehicleEnum& operator = (const PlayerVehicleEnum& playerVehicleEnum);
	int GetNext(Unit& currentUnit);
public:	// Why not? =)
	void* currentUnit;
};

static_assert(4 == sizeof(PlayerVehicleEnum), "PlayerVehicleEnum is an unexpected size");

// Buildings (enumerate all buildings of a certain type for a certain player)
class OP2 PlayerBuildingEnum
{
public:
	PlayerBuildingEnum(int playerNum, map_id buildingType);
	PlayerBuildingEnum& operator = (const PlayerBuildingEnum& playerBuildingEnum);
	int GetNext(class Unit &currentUnit);
public:	// Why not? =)
	void* currentUnit;
	map_id buildingType;
};

static_assert(8 == sizeof(PlayerBuildingEnum), "PlayerBuildingEnum is an unexpected size");

// Units (enumerate all units of a certain player)
class OP2 PlayerUnitEnum
{
public:
	PlayerUnitEnum(int playerNum);
	PlayerUnitEnum& operator = (const PlayerUnitEnum& playerUnitEnum);
	int GetNext(Unit& currentUnit);
public:	// Why not? =)
	void* currentUnit;
	int playerNum;
};

static_assert(8 == sizeof(PlayerUnitEnum), "PlayerUnitEnum is an unexpected size");

// InRange (enumerate all units within a given distance of a given location)
class OP2 InRangeEnumerator
{
public:
	InRangeEnumerator(const LOCATION& centerPoint, int maxTileDistance);
	InRangeEnumerator& operator = (const InRangeEnumerator& inRangeEnum);
	int GetNext(class Unit &currentUnit);
private:
	int unknown[13];	// **TODO** Fill in details
};

static_assert(4 * 13 == sizeof(InRangeEnumerator), "InRangeEnumerator is an unexpected size");

// InRect (enumerate all units within a given rectangle)
class OP2 InRectEnumerator
{
public:
	InRectEnumerator(const MAP_RECT& rect);
	InRectEnumerator& operator = (const InRectEnumerator& inRectEnum);
	int GetNext(Unit& currentUnit);
private:
	int unknown[13];	// **TODO** Fill in details
};

static_assert(4 * 13 == sizeof(InRectEnumerator), "InRectEnumerator is an unexpected size");

// Location (enumerate all units at a given location)
class OP2 LocationEnumerator
{
public:
	LocationEnumerator(const LOCATION& location);
	LocationEnumerator& operator = (const LocationEnumerator& locationEnum);
	int GetNext(Unit& currentUnit);
private:
	int unknown[13];	// **TODO** Fill in details
};

static_assert(4 * 13 == sizeof(LocationEnumerator), "LocationEnumerator is an unexpected size");

// Closest (enumerate all units ordered by their distance to a given location)
class OP2 ClosestEnumerator
{
public:
	ClosestEnumerator(const LOCATION& location);
	ClosestEnumerator& operator = (const ClosestEnumerator& closestEnum);
	int GetNext(Unit& currentUnit, unsigned long &pixelDistance);
private:
	int unknown[13];	// **TODO** Fill in details
};

static_assert(4 * 13 == sizeof(ClosestEnumerator), "ClosestEnumerator is an unexpected size");
