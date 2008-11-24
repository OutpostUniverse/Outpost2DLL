

enum UnitClassifications;



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
	LOCATION();						// { this->x = 0; this->y = 0; };
	struct LOCATION & operator = (struct LOCATION const &);
	void Add(struct LOCATION const &vector);
	void Clip();
	static struct LOCATION __fastcall Difference(struct LOCATION const &firstOperand, struct LOCATION const &secondOperand);
	int Norm();

public:
	int x, y;
};

struct OP2 MAP_RECT
{
public:
	MAP_RECT(struct LOCATION const &topLeftTile, struct LOCATION const &bottomRightTile);
	MAP_RECT(int tileX1, int tileY1, int tileX2, int tileY2); // Top left: (tileX1, tileY1), Bottom right: (tileX2, tileY2)
	MAP_RECT();
	struct MAP_RECT & operator = (struct MAP_RECT const &);
	int Check(struct LOCATION &ptToCheck);		// int bInRect  [Checks if the point is in the rect  [handles x wrap around for rect coordinates]]
	void ClipToMap();
	void FromPtSize(struct LOCATION const &, struct LOCATION const &);
	int Height() const;
	void Inflate(int unitsWide, int unitsHigh);
	void Offset(int shiftRight, int shiftDown);
	struct LOCATION RandPt() const;
	struct LOCATION Size() const;
	int Width() const;

public:
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
	int x1; // -1 to terminate list
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
	int time1;
	int time2;
	int time3;
};

// CommandPackets seem to have a set maximum of 0x74 bytes
// Note: The compiler must be told to pack this structure since the 
//		 short dataLength would otherwise have 2 padding bytes after
//		 it which would mess up the rest of the structure.
/*
#pragma pack(push, 1)
struct OP2 CommandPacket 
{
	int type;				// Type of command - see secret list :)
	short dataLength;		// Length of dataBuff
	int timeStamp;			// Game Tick (only seems to be used for network traffic)
	int unknown;			// **TODO** figure this out (only used for network traffic?)
	char dataBuff[0x66];	// Dependent on message type
};
#pragma pack(pop)
*/

// Size: 0x20  [0x20 = 32, or 8 dwords]  [Note: last 2 fields are shorts]
struct OP2 UnitRecord 
{
	map_id unitType;							// 0x0
	int x;										// 0x4
	int y;										// 0x8
	int unknown1;								// 0xC  ** [unused?]
	int rotation;								// 0x10 ** [Byte?]
	map_id weaponType;							// 0x14
	UnitClassifications unitClassification;		// 0x18
	short cargoType;							// 0x1C
	short cargoAmount;							// 0x1E
};

