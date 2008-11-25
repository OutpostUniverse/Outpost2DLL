#pragma once

// Note: This file is used to define the Unit class and the UnitBlock class
//		 exported from Outpost2.exe. Use these classes to manipulate all the
//		 units in the game.
// Note: The Unit class is also used in conjunction with the enumerator
//		 classes used to find units and traverse lists of units, one unit
//		 at a time. See Enumerator.h for details.

// Forward declares
enum map_id;
enum Truck_Cargo;
struct LOCATION;
struct CommandPacket;


// Note: This class controls units and provides info on them. This class can
//		 be used to set cargo in ConVecs, Cargo Trucks, or factory bays.
//		 It can also be used to move units around the map and perform simple
//		 operations such as self destruct and headlight control.

class OP2 Unit
{
public:
	Unit() { unitID = 0; };
	Unit& operator = (const Unit& unit);
	int operator == (const Unit& unit) const;

	void ClearSpecialTarget();
	void DoAttack(Unit);
	void DoBuild(map_id buildingType, LOCATION location);
	void DoDeath();
	void DoDevelop(map_id);
	void DoIdle();
	void DoInfect();
	void DoLaunch(int, int, int);
	void DoMove(LOCATION location);
	void DoSelfDestruct();
	void DoSetLights(int boolOn);
	void DoStop();
	void DoTransfer(int playerNum);
	void DoUnIdle();
	map_id GetCargo() const;
	map_id GetObjectOnPad() const;
	map_id GetType() const;
	map_id GetWeapon() const;
	int HasOccupiedBay() const;
	int IsBuilding() const;
	int IsBusy() const;
	int IsLive();
	int IsVehicle() const;
	LOCATION Location() const;
	int OwnerID() const;
	void PutInGarage(int bay, int tileX, int tileY);
	void SetCargo(map_id cargoType, map_id weaponType);
	void SetDamage(int damage);
	void SetFactoryCargo(int bay, map_id unitType, map_id cargoOrWeaponType);
	void SetId(int newUnitId);
	void SetOppFiredUpon(int);
	void SetTruckCargo(Truck_Cargo cargoType, int amount);
	void SetWeapon(map_id weaponType);
	int isDiscovered() const;		// Checks if a Wreckage unit has been discovered
	int isEMPed() const;

protected:
	void DoSimpleCommand(int commandPacketType);
private:
	char* StoreSelf(CommandPacket& commandPacket) const;

public:	// Why not? :)
	int unitID;
};
