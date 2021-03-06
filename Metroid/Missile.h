#pragma once
#ifndef _MISSILE_H_
#define _MISSILE_H_

#include "GameObject.h"
#include "Sprite.h"
#include "Parameters.h"

#define MISSILE_SPRITE_PATH L"sprites\\bullet\\missile.png"
#define MISSILE_UP_SPRITE "sprites\\bullet\\MISSILE_UP.txt"
#define MISSILE_LEFT_SPRITE "sprites\\bullet\\MISSILE_LEFT.txt"
#define MISSILE_RIGHT_SPRITE "sprites\\bullet\\MISSILE_RIGHT.txt"

#define MISSILE_WIDTH 26
#define MISSILE_HEIGHT 20

#define MISSILE_UP_WIDTH 20
#define MISSILE_UP_HEIGHT 26

#define MISSILE_COUNT 1
#define SPRITE_PER_ROW 1

#define SPEED 0.3f
#define LIMIT_DISTANCE 200


class Missile : public GameObject
{
private:
	int pos_x_holder;
	int pos_y_holder;

	int limit_dist_x;		//limit distance of x
	int limit_dist_y;		//limit distance of y;



	LPD3DXSPRITE _SpriteHandler;
	BULLET_DIRECTION direction;
	Sprite * missile_up;
	Sprite * missile_left;
	Sprite * missile_right;

public:
	bool isRendering;		//determine if the bullet is in rendering (in case out of distance_limit -> not render)

	Missile();
	Missile(int x_holder, int y_holder);
	~Missile();

	void InitSprites(LPDIRECT3DDEVICE9 d3ddv);
	void InitPosition(int posX, int posY);

	BULLET_DIRECTION GetDirection();
	void SetDirection(BULLET_DIRECTION value);
	void Update(int t, int posX, int posY);
	void Render();
	void ResetPosition();
	void Reset();
	void Release();		//destroy the missile
	void Shoot(BULLET_DIRECTION dir);
};

#endif // !_BULLET_H

