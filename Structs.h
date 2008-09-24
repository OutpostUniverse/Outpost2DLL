
// Note: This file contains all the exported structures from Outpost2.exe.
// Note: Some of these structures are really more like full classes but
//		 since they called them struct's we'll let that one slide. =)



// Note: These first two structs have all member functions defined and
//		 exported by Outpost2.exe. (Essentially these structs are 
//		 really classes in disguise.)

struct OP2 LOCATION
{
public:
	LOCATION(int tileX, int tileY)	{ this->x = tileX; this->y = tileY; };
	LOCATION()						{ this->x = 0; this->y = 0; };
	struct LOCATION & operator = (struct LOCATION const &);
	void Add(struct LOCATION const &vector);
	void Clip();
	static struct LOCATION __fastcall Difference(struct LOCATION const &firstOperand, struct LOCATION const &secondOperand);
	int Norm();

	int x, y;
};

struct OP2 MAP_RECT
{
public:
	MAP_RECT(struct LOCATION const &topLeftTile, struct LOCATION const &bottomRightTile);
	MAP_RECT(int tileX1, int tileY1, int tileX2, int tileY2); // Top left: (tileX1, tileY1), Bottom right: (tileX2, tileY2)
	MAP_RECT();
	struct MAP_RECT & operator = (struct MAP_RECT const &);
	int Check(struct LOCATION &ptToCheck);
	void ClipToMap();
	void FromPtSize(struct LOCATION const &, struct LOCATION const &);
	int Height() const;
	void Inflate(int unitsWide, int unitsHigh);
	void Offset(int shiftRight, int shiftDown);
	struct LOCATION RandPt() const;
	struct LOCATION Size() const;
	int Width() const;

	int x1, y1, x2, y2;		// Top left: (x1, y1), Bottom right: (x2, y2)
};





// Note: These following structs have their names defined by the exported
//		 functions from Outpost2.exe but none of their fields are defined
//		 this way. (Only member functions are exported and these structs
//		 don't have any. Essentially these are the "true" structs.)



struct OP2 PatrolRoute 
{
	int unknown1;
	LOCATION *waypoints;
};

struct OP2 MrRec 
{
	map_id unitType;
	map_id weaponType;
	int unknown1; // -1 to terminate list
	int unknown2; // -1 to terminate list
};

struct OP2 PWDef 
{
	int x; // -1 to terminate list
	int y;
};

struct OP2 CommandPacket 
{
};

struct OP2 UnitRecord 
{
	map_id Type;
	int X, Y;
	int unknown1, unknown2;
	map_id Weapon;
	int unknown3;
	short Cargo;
	short Amount;
};


