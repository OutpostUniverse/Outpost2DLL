#pragma once
#ifndef OP2
#define OP2 __declspec(dllimport)
#endif


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
	int ActivateGame(void);
	int ActivateShell(GameTermReasons,MissionResults *);
	int AppActive(void) const;
	int AppPaused(void) const;
	void BeginWaitCursor(void);
	unsigned int ChecksumExe(void);
	unsigned int ChecksumShell(void);
	int CreateFrames(void);
	int DirectDrawActive(void) const;
	int DisableModeSwitching(void);
	int DoNetGame(int,char const *);
	int EnableModeSwitching(void);
	void EndWaitCursor(void);
	static long __stdcall F1DetectHook(int, unsigned int, long);
	HINSTANCE GetAccelInst(void) const;
	void GetAppDesc(char *);
	HINSTANCE GetBmpInst(void) const;
	HINSTANCE GetCurInst(void) const;
	struct IDirectDraw * GetDirectDraw(void) const;
	HINSTANCE GetDlgInst(void) const;
	void GetHelp(void);
	HINSTANCE GetIconInst(void) const;
	int GetLoadName(void);
	HINSTANCE GetMainInst(void) const;
	HINSTANCE GetMenuInst(void) const;
	int HandleCommand(unsigned int);
	int HideDirectDraw(HWND);
	int Init(void);
	int __stdcall InstallFilterFunc(int, int);
	int LoadGame(char const *);
	int LobbyActive(void);
	void LobbyShutdown(void);
	int ModeSwitch(void);
	int NetActive(void);
	void NetShutdown(int);
	void NewGame(void);
	void OnActivateApp(int);
	int OnLoadGame(void);
	void OnLoadScript(char *);
	int OnLoadSlot(void);
	void OnPauseGame(int);
	void OnSaveGame(void);
	void OnSaveSlot(void);
	void ParseCommandLine(char *);
	int PlaybackCommand(CommandPacket *, int);
	int PumpMessage(void);
	int RestoreDirectDraw(HWND);
	void Run(void);
	void SaveGame(char const *, TFileDialog *);
	void SetLobby(TLobby *);
	void SetMainInst(HINSTANCE);
	int SetUIState(UIState *);
	void ShutDown(void);
	int StartSingleGame(GameStartInfo *);
	unsigned long Version(void);

private:
	int InitForDirectDraw(void);
};

// Use this TApp instance, instead of creating your own.
OP2 TApp gTApp;
