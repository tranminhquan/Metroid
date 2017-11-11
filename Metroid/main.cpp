#include <windows.h>
#include "Game.h"
#include "Metroid.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Metroid metroid(hInstance, L"Metroid game", GAME_SCREEN_RESOLUTION_800_600_24, 0, 24);

	metroid.Init();
	metroid.Run();

	return 0;
}