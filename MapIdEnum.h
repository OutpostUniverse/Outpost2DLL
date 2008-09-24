
// Note: This file contains the all important map_id enum.
//		 This enum is used for almost all aspects of DLL 
//		 level programming. It provides the names used for
//		 all units (vehicles/buildings/disasters/resources)
//		 that can be created and placed on the map.
//		 It also names all weapon types and starship modules
//		 as well as a few other miscellaneous things.

// Uncommment this to use old names from enum map_id
// for a quick and dirty compile of old code (but not 
// necesarily all of it)
//#define CompatibleNames


enum map_id {
	mapAny = -1,					// FF Use to specify 'all' or 'any'

	mapNone = 0,
	mapCargoTruck,					// 01
	mapConVec,						// 02
	mapSpider,						// 03
	mapScorpion,					// 04
	mapLynx,						// 05
	mapPanther,						// 06
	mapTiger,						// 07
	mapRoboSurveyor,				// 08
	mapRoboMiner,					// 09
	mapGeoCon,						// 0A
	mapScout,						// 0B
	mapRoboDozer,					// 0C
	mapEvacuationTransport,			// 0D
	mapRepairVehicle,				// 0E
	mapEarthworker,					// 0F
	mapSmallCapacityAirTransport,	// 10 Crashes game when it moves (looks like a scout)

	mapTube,						// 11
	mapWall,						// 12
	mapLavaWall,					// 13
	mapMicrobeWall,					// 14

	mapCommonOreMine,				// 15
	mapRareOreMine,					// 16
	mapGuardPost,					// 17

	mapLightTower,					// 18
	mapCommonStorage,				// 19
	mapRareStorage,					// 1A
	mapForum,						// 1B
	mapCommandCenter,				// 1C
	mapMHDGenerator,				// 1D
	mapResidence,					// 1E
	mapRobotCommand,				// 1F
	mapTradeCenter,					// 20
	mapBasicLab,					// 21
	mapMedicalCenter,				// 22
	mapNursery,						// 23
	mapSolarPowerArray,				// 24
	mapRecreationFacility,			// 25
	mapUniversity,					// 26
	mapAgridome,					// 27
	mapDIRT,						// 28
	mapGarage,						// 29
	mapMagmaWell,					// 2A
	mapMeteorDefense,				// 2B
	mapGeothermalPlant,				// 2C
	mapArachnidFactory,				// 2D
	mapConsumerFactory,				// 2E
	mapStructureFactory,			// 2F
	mapVehicleFactory,				// 30
	mapStandardLab,					// 31
	mapAdvancedLab,					// 32
	mapObservatory,					// 33
	mapReinforcedResidence,			// 34
	mapAdvancedResidence,			// 35
	mapCommonOreSmelter,			// 36
	mapSpaceport,					// 37
	mapRareOreSmelter,				// 38
	mapGORF,						// 39
	mapTokamak,						// 3A

	mapAcidCloud,					// 3B
	mapEMP,							// 3C
	mapLaser,						// 3D
	mapMicrowave,					// 3E
	mapRailGun,						// 3F
	mapRPG,							// 40
	mapStarflare,					// 41
	mapSupernova,					// 42
	mapStarflare2,					// 43 Explosion of some kind (upgraded starflare?)
	mapSupernova2,					// 44 Bigger explosion (upgraded supernova?)
	//mapNormalExplosion,			// 45 Explosion (looks same as 43) Self destruct? (upgraded?)
	mapESG = 0x46,					// 46
	mapStickyfoam,					// 47
	mapThorsHammer,					// 48
	mapEnergyCannon,				// 49

	mapBlast,						// 4A EMP/Sticky foam blast

	//mapUnknown4B,					// 4B Unknown what this is
	mapLightning = 0x4C,			// 4C
	mapVortex,						// 4D
	mapEarthquake,					// 4E
	mapEruption,					// 4F
	mapMeteor,						// 50

	mapMiningBeacon,				// 51
	mapMagmaVent,					// 52
	mapFumarole,					// 53

	mapWreckage,					// 54

	mapDisasterousBuildingExplosion,	// 55
	mapCatastrophicBuildingExplosion,	// 56
	mapAtheistBuildingExplosion,		// 57

	mapEDWARDSatellite,				// 58  Lynx (in Cargo Truck)
	mapSolarSatellite,				// 59  Wreckage (in Cargo Truck)
	mapIonDriveModule,				// 5A  Gene Bank 5 (in Cargo Truck)
	mapFusionDriveModule,			// 5B
	mapCommandModule,				// 5C
	mapFuelingSystems,				// 5D
	mapHabitatRing,					// 5E
	mapSensorPackage,				// 5F
	mapSkydock,						// 60
	mapStasisSystems,				// 61
	mapOrbitalPackage,				// 62
	mapPhoenixModule,				// 63

	mapRareMetalsCargo,				// 64
	mapCommonMetalsCargo,			// 65
	mapFoodCargo,					// 66
	mapEvacuationModule,			// 67
	mapChildrenModule,				// 68

	mapSULV,						// 69
	mapRLV,							// 6A
	mapEMPMissile,					// 6B

	mapImpulseItems,				// 6C
	mapWares,						// 6D
	mapLuxuryWares,					// 6E

	mapInterColonyShuttle,			// 6F
	mapSpider3Pack,					// 70
	mapScorpion3Pack,				// 71

	mapPrettyArt					// 72

#ifdef CompatibleNames
	,
	map_Any = -1,

	map_None = 0,
	map_Cargo_Truck,			// 01
	map_ConVec,					// 02
	map_Spider,					// 03
	map_Scorpion,				// 04
	map_Lynx,					// 05
	map_Panther,				// 06
	map_Tiger,					// 07
	map_Robo_Surveyor,			// 08
	map_Robo_Miner,				// 09
	map_GeoCon,					// 0A
	map_Scout,					// 0B
	map_Robo_Dozer,				// 0C
	map_Evacuation_Transport,	// 0D
	map_Repair_Vehicle,			// 0E
	map_Earthworker,			// 0F
	map_SmallCapacityAirTransport,	// 10 Crashes game when it moves (looks like a scout)

	map_Tube,					// 11
	map_Wall,					// 12
	map_Lava_Wall,				// 13
	map_Microbe_Wall,			// 14
	map_Mine,					// 15
	map_Common_Ore_Mine = 0x15,	// Duplicate name
	map_Rare_Ore_Mine,			// 16
	map_Guard_Post,				// 17
	map_Light_Tower,			// 18
	map_Common_Storage,			// 19
	map_Rare_Storage,			// 1A
	map_Forum,					// 1B
	map_Command_Center,			// 1C
	map_MHD_Generator,			// 1D
	map_Residence,				// 1E
	map_Robot_Command,			// 1F
	map_Trade_Center,			// 20
	map_Basic_Lab,				// 21
	map_Medical_Center,			// 22
	map_Nursery,				// 23
	map_Solar_Power_Array,		// 24
	map_Recreation_Facility,	// 25
	map_University,				// 26
	map_Agridome,				// 27
	map_DIRT,					// 28
	map_Garage,					// 29
	map_Magma_Well,				// 2A
	map_Meteor_Defense,			// 2B
	map_Geothermal_Plant,		// 2C
	map_Arachnid_Factory,		// 2D
	map_Consumer_Factory,		// 2E
	map_Structure_Factory,		// 2F
	map_Vehicle_Factory,		// 30
	map_Standard_Lab,			// 31
	map_Advanced_Lab,			// 32
	map_Observatory,			// 33
	map_Reinforced_Residence,	// 34
	map_Advanced_Residence,		// 35
	map_Common_Ore_Smelter,		// 36
	map_Spaceport,				// 37
	map_Rare_Ore_Smelter,		// 38
	map_GORF,					// 39
	map_Tokamak,				// 3A

	map_Acid_Cloud = 0x3B,		// 3B
	map_EMP,					// 3C
	map_Laser,					// 3D
	map_Microwave,				// 3E
	map_Rail_Gun,				// 3F
	map_RPG,					// 40
	map_Starflare,				// 41
	map_Supernova,				// 42
	map_Starflare2,				// 43
	map_Supernova2,				// 44
	// map_Normal_Explosion
	map_ESG = 0x46,				// 46
	map_Stickyfoam,				// 47
	map_Thors_Hammer,			// 48
	map_Energy_Cannon,			// 49

	map_Blast,					// 4A EMP/Sticky foam blast

	map_Lightning = 0x4C,		// 4C
	map_Vortex,					// 4D
	map_Earthquake,				// 4E
	map_Eruption,				// 4F
	map_Meteor,					// 50

	map_Mining_Beacon,			// 51
	map_Magma_Vent,				// 52
	map_Fumarole,				// 53

	map_Wreckage,				// 54

	map_Disasterous_Building_Explosion,		// 55
	map_Catastrophic_Building_Explosion,	// 56
	map_Atheist_Building_Explosion,			// 57

	map_EDWARD_Satellite,		// 58 Lynx (in Cargo Truck)
	map_Solar_Satellite,		// 59 Wreckage (in Cargo Truck)
	map_Ion_Drive_Module,		// 5A Gene Bank 5 (in Cargo Truck)
	map_Fusion_Drive_Module,	// 5B
	map_Command_Module,			// 5C
	map_Fueling_Systems,		// 5D
	map_Habitat_Ring,			// 5E
	map_Sensor_Package,			// 5F
	map_Skydock,				// 60
	map_Stasis_Systems,			// 61
	map_Orbital_Package,		// 62
	map_Phoenix_Module,         // 63

	map_Rare_Metals_Cargo,		// 64
	map_Common_Metals_Cargo,	// 65
	map_Food_Cargo,				// 66
	map_Evacuation_Module,		// 67
	map_Children_Module,		// 68

	map_SULV,					// 69
	map_RLV,					// 6A
	map_EMP_Missile,			// 6B

	map_Impulse_Items,			// 6C
	map_Wares,					// 6D
	map_Luxury_Wares,			// 6E

	map_Inter_Colony_Shuttle,	// 6F
	map_Spider_3_Pack,			// 70
	map_Scorpion_3_Pack,		// 71

	map_Pretty_Art				// 72
#endif
};
