#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif


// External type names
struct UnitRecord;


// Note: The UnitBlock class can be used for creating blocks of units
//		 of certain predefined types.

class OP2 UnitBlock
{
public:
	UnitBlock(UnitRecord* unitRecordTable);
	UnitBlock& operator = (const UnitBlock& unitBlock);
	int CreateUnits(int playerNum, int bLightsOn) const;	// Returns numUnitsCreated
private:
	void SortAndInit(UnitRecord* unitRecordTable);	// Sort unitRecordTable and initialize classRange table

public:
	struct Range
	{
		int startIndex;
		int untilIndex;
	};

	static_assert(8== sizeof(Range), "Range is an unexpected size");

	int numUnits;					// 0x0
	Range classRange[16];			// 0x4  Range of unit indexes in the unitRecordTable for each class
	UnitRecord* unitRecordTable;	// 0x84
};

static_assert(4 + 8 * 16 + 4 == sizeof(UnitBlock), "UnitBlock is an unexpected size");
