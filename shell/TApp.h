#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>


enum GameTermReasons {
	GameTermRunning             = 0,  // Still running

	GameTermMissionAccomplished = 3,  // Mission Accomplished
	GameTermMissionFailed       = 4,  // Mission Failed

	GameTermMissionAborted      = 6,  // Mission aborted  (single player abort?)
	GameTermVictory             = 7,  // Victory is sweet
	GameTermDefeat              = 8,  // You have been defeated
	GameTermControlTerminated   = 9,  // Control terminated  (multiplayer abort?)
	GameTermDemo1               = 10, // Outpost 2 Demo
	GameTermDemo2               = 11, // Outpost 2 Demo

	// ...                            // other: Game Over
};

struct MissionResults;
struct CommandPacket;
class TFileDialog;
class TLobby;
class UIState;
struct GameStartInfo;


// The TApp object represents the core of Outpost2.exe.
// It is called into directly from WinMain and is responsible for main application control.
class OP2 TApp
{
public:
	TApp & operator=(TApp const &);
	int ActivateGame();
	int ActivateShell(GameTermReasons,MissionResults *);
	int AppActive() const;
	int AppPaused() const;
	void BeginWaitCursor();
	unsigned int ChecksumExe();
	unsigned int ChecksumShell();
	int CreateFrames();
	int DirectDrawActive() const;
	int DisableModeSwitching();
	int DoNetGame(int, char const *);
	int EnableModeSwitching();
	void EndWaitCursor();
	static long __stdcall F1DetectHook(int, unsigned int, long);
	HINSTANCE GetAccelInst() const;
	void GetAppDesc(char *);
	HINSTANCE GetBmpInst() const;
	HINSTANCE GetCurInst() const;
	struct IDirectDraw * GetDirectDraw() const;
	HINSTANCE GetDlgInst() const;
	void GetHelp();
	HINSTANCE GetIconInst() const;
	int GetLoadName();
	HINSTANCE GetMainInst() const;
	HINSTANCE GetMenuInst() const;
	int HandleCommand(unsigned int);
	int HideDirectDraw(HWND);
	int Init();
	int __stdcall InstallFilterFunc(int, int);
	int LoadGame(char const *);
	int LobbyActive();
	void LobbyShutdown();
	int ModeSwitch();
	int NetActive();
	void NetShutdown(int);
	void NewGame();
	void OnActivateApp(int);
	int OnLoadGame();
	void OnLoadScript(char *);
	int OnLoadSlot();
	void OnPauseGame(int);
	void OnSaveGame();
	void OnSaveSlot();
	void ParseCommandLine(char *);
	int PlaybackCommand(CommandPacket *, int);
	int PumpMessage();
	int RestoreDirectDraw(HWND);
	void Run();
	void SaveGame(char const *, TFileDialog *);
	void SetLobby(TLobby *);
	void SetMainInst(HINSTANCE);
	int SetUIState(UIState *);
	void ShutDown();
	int StartSingleGame(GameStartInfo *);
	unsigned long Version();

private:
	int InitForDirectDraw();
};

// Use this TApp instance, instead of creating your own.
OP2 TApp gTApp;
