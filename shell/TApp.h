#pragma once

// TApp declarations.
// The TApp object represents the core of Outpost2.exe.
// It is called into directly from WinMain and is responsible for main application control.

// These are declared in OP2 but not exported.
enum GameTermReasons
{
};
struct MissionResults;
struct CommandPacket;
class TFileDialog;
class TLobby;
class UIState;
struct GameStartInfo;


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
