#pragma once
#ifndef _METROID_H_
#define _METROID_H_

#define SAMUS_SPEED 0.25f
#define SHOOTING_SPEED 15
#define BACKGROUND_FILE L"background\\temp.png"


#include "Game.h"
#include "Samus.h"
#include "Tiles.h"
#include "Bullet.h"
#include "Enemy_Fly.h"
#include "Enemy_Stick_Bottom.h"
#include "Enemy_Stick_Up.h"
#include "Enemy_Stick_Left.h"
#include "Enemy_Stick_Right.h"

#include "BulletManager.h"
class Metroid : public Game
{
protected:
	LPDIRECT3DSURFACE9 Background;
	Samus * samus;
	Tiles * tiles;
	Enemy * enemy_fly,* enemy_stick_bottom,
		*enemy_stick_up,*enemy_stick_left,
		*enemy_stick_right;

	BulletManager * bulletManager;

private:
	void _InitBackground();
	void _InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void _InitPositions();

	DWORD start_jump;
	DWORD now_jump;
	DWORD tick_per_frame;

	DWORD start_shoot;
	DWORD now_shoot;

	void _Shoot(BULLET_DIRECTION dir);

public:
	Metroid(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate);
	~Metroid();

	LPDIRECT3DSURFACE9 _Background;


	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

	virtual void OnKeyDown(int KeyCode);

};

#endif // !_METROID_
	