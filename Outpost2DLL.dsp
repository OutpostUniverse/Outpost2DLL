# Microsoft Developer Studio Project File - Name="Outpost2DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=OUTPOST2DLL - WIN32 RELEASE
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Outpost2DLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Outpost2DLL.mak" CFG="OUTPOST2DLL - WIN32 RELEASE"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Outpost2DLL - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /O1 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
# Begin Target

# Name "Outpost2DLL - Win32 Release"
# Begin Group "Master Header"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Outpost2DLL.h
# End Source File
# End Group
# Begin Group "Sub Headers"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Enumerators.h
# End Source File
# Begin Source File

SOURCE=.\Enums.h
# End Source File
# Begin Source File

SOURCE=.\GameMap.h
# End Source File
# Begin Source File

SOURCE=.\Globals.h
# End Source File
# Begin Source File

SOURCE=.\Groups.h
# End Source File
# Begin Source File

SOURCE=.\MapIdEnum.h
# End Source File
# Begin Source File

SOURCE=.\NonExportedEnums.h
# End Source File
# Begin Source File

SOURCE=.\Player.h
# End Source File
# Begin Source File

SOURCE=.\RequiredExports.h
# End Source File
# Begin Source File

SOURCE=.\ScStub.h
# End Source File
# Begin Source File

SOURCE=.\Structs.h
# End Source File
# Begin Source File

SOURCE=.\TethysGame.h
# End Source File
# Begin Source File

SOURCE=.\Trigger.h
# End Source File
# Begin Source File

SOURCE=.\Unit.h
# End Source File
# Begin Source File

SOURCE=.\UnitBlock.h
# End Source File
# End Group
# End Target
# End Project
