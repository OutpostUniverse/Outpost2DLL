# Outpost2DLL

The Outpost2DLL library provides access to the methods exported by Outpost2.exe. These can be used by mission DLLs to setup game state, or by a shell library that controls the in-game menus. As code generally falls into one of the two categories, used for missions, or used for the shell, the library is divided into two main components.

Missions will be mainly interested in the `Outpost2DLL.h` header file, which is the master include file for the contents of the `game` folder.

Shell libraries will be mainly interested in the `Outpost2App.h` header file, which is the master include file for the contents of the `shell` folder.

# Usage

This library is normally used as part of the [Mission SDK](https://github.com/OutpostUniverse/OP2MissionSDK). For a template project that comes setup with the Mission SDK already pre-configured, please see the [LevelTemplate](https://github.com/OutpostUniverse/LevelTemplate) project. The level template project is where most people should start.
