
// Note: This file is used to define the Unit class and the UnitBlock class
//		 exported from Outpost2.exe. Use these classes to manipulate all the
//		 units in the game.
// Note: The Unit class is also used in conjunction with the enumerator
//		 classes used to find units and traverse lists of units, one unit
//		 at a time. See Enumerator.h for details.


// Note: This class controls units and provides info on them. This class can
//		 be used to set cargo in ConVecs, Cargo Trucks, or factory bays.
//		 It can also be used to move units around the map and perform simple
//		 operations such as self destruct and headlight control.

class OP2 Unit
{
public:
	Unit() { unitID = 0; };
	class Unit & operator=(class Unit const &);
	int operator == (class Unit const &)const;
	void ClearSpecialTarget();
	void DoAttack(class Unit);
	void DoBuild(enum map_id buildingType,struct LOCATION location);
	void DoDeath();
	void DoDevelop(enum map_id);
	void DoIdle();
	void DoInfect();
	void DoLaunch(int,int,int);
	void DoMove(struct LOCATION location);
	void DoSelfDestruct();
	void DoSetLights(int boolOn);
	void DoStop();
	void DoTransfer(int playerNum);
	void DoUnIdle();
	enum map_id GetCargo() const;
	enum map_id GetObjectOnPad() const;
	enum map_id GetType() const;
	enum map_id GetWeapon() const;
	int HasOccupiedBay() const;
	int IsBuilding() const;
	int IsBusy() const;
	int IsLive();
	int IsVehicle() const;
	struct LOCATION Location() const;
	int OwnerID() const;
	void PutInGarage(int bay, int tileX, int tileY);
	void SetCargo(enum map_id cargoType, enum map_id weaponType);
	void SetDamage(int damage);
	void SetFactoryCargo(int bay, enum map_id unitType, enum map_id cargoOrWeaponType);
	void SetId(int newUnitId);
	void SetOppFiredUpon(int);
	void SetTruckCargo(enum Truck_Cargo cargoType, int amount);
	void SetWeapon(enum map_id weaponType);
	int isDiscovered() const;		// Checks if a Wreckage unit has been discovered
	int isEMPed() const;

protected:
	void DoSimpleCommand(int commandPacketType);
private:
	char* StoreSelf(struct CommandPacket &) const;

public:	// Why not? :)
	int unitID;
};


// Note: The UnitBlock class can be used for creating blocks of units
//		 of certain predefined types.

class OP2 UnitBlock
{
public:
	UnitBlock(struct UnitRecord* unitRecordTable);
	UnitBlock& operator=(UnitBlock const &unitBlock);
	int CreateUnits(int playerNum, int bLightsOn) const;	// Returns numUnitsCreated
private:
	void SortAndInit(struct UnitRecord* unitRecordTable);	// Sort unitRecordTable and initialize classRange table

public:
	struct Range
	{
		int startIndex;
		int untilIndex;
	};

	int numUnits;							// 0x0
	Range classRange[16];					// 0x4 Range of unit indexes in the unitRecordTable for each class
	struct UnitRecord* unitRecordTable;		// 0x84
};


