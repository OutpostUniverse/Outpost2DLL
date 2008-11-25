#pragma once

// Note: This file contains the _Player class definition exported from
//		 Outpost2.exe. Use this class to modify anything associated
//		 with a player (human or AI).
// Note: The AI in Outpost 2 is sadly faked. Using _Player.GoAI() is
//		 essentially creating a computer controlled player that cheats.
//		 It's given essentially unlimited population resources and so
//		 it doesn't have to worry about food or idling buildings due
//		 to lack of workers. You can make a much more realistic AI
//		 if you leave the player set as human and just program all
//		 the actions yourself (which you'd have to do anyways since 
//		 Outpost 2 has no real AI and all computer actions are
//		 hardcoded into each DLL).


// Forward declares
enum map_id;
struct MAP_RECT;
class ScGroup;		// **


class OP2 _Player
{
public:
	// Object Construction/Assignment
	_Player(int playerNum);
	_Player& operator = (const _Player& player);

	// [Get] Game Settings
	int Difficulty() const;
	int IsEden();
	int IsHuman();
	// [Get] Population
	int Kids() const;
	int Workers() const;
	int Scientists() const;
	// [Get] Resources
	int Ore() const;
	int RareOre() const;
	int FoodStored() const;
	enum FoodStatus FoodSupply() const;
	// [Get] Misc
	enum MoraleLevels MoraleLevel() const;
	int GetRLVCount();
	// [Get] Indirect property lookups
	ScGroup GetDefaultGroup();
	int HasTechnology(int techID) const;
	// [Get] Player Strength  [Calculational]
	int GetPlayerStrength(MAP_RECT& mapRect);
	int GetTotalPlayerStrength();
	// [Get] Checks  [Prerequisite searching]
	int canAccumulateOre();
	int canAccumulateRareOre();
	int canBuildBuilding();
	int canBuildSpace();
	int canBuildVehicle(int);
	int canDoResearch(int);
	int hasActiveCommand();
	int hasVehicle(map_id, map_id);

	// [Set] Game Settings
	void SetColorNumber(int colorId);
	// [Set] Population
	void SetKids(int numKids);
	void SetWorkers(int numWorkers);
	void SetScientists(int numScis);
	// [Set] Resources
	void SetOre(int commonOreAmt);
	void SetRareOre(int rareOreAmt);
	void SetFoodStored(int foodAmt);
	// [Set] Misc
	void SetSolarSat(int numSats);
	// [Set] Indirect property setting
	void SetTechLevel(int techLevelId);
	void MarkResearchComplete(int techID);
	void SetDefaultGroup(ScGroup& newDefaultGroup);

	// [Method]
	void GoEden();
	void GoPlymouth();
	void GoAI();
	void GoHuman();
	void AllyWith(int playerNum);
	void CaptureRLV(int);
	void CenterViewOn(int tileX, int tileY);
	void resetChecks();

public:	// Why not? :)
	int playerNum;
	int unknown2;	// **
	int unknown3;	// **
};
