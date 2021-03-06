﻿#pragma once
class Bullet;
class BulletManager;
class World;
class Collider;
class Metroid;
class Sprite;
class Samus;
class GameObject;
class GroupObject;
class Enemy;
class QNode;
class Loader;
class Brick;
class Bedgehog;

//================ SCREEN RESOLUTION ================
#define GAME_SCREEN_RESOLUTION_640_480_24   0
#define GAME_SCREEN_RESOLUTION_800_600_24   1
#define GAME_SCREEN_RESOLUTION_1024_768_24  2

#define GAME_SCREEN_RESOLUTION_640_480_32   10
#define GAME_SCREEN_RESOLUTION_800_600_32   11
#define GAME_SCREEN_RESOLUTION_1024_768_32  12
//================ END RESOLUTION ====================

//================ FACTOR OF QUADTREE NODE ===========
#define NODE_FACTOR 8;

//================== SAMUS ===================
#define SHOOTING_SPEED 15
#define SAMUS_SPEED 0.25f

#define SAMUS_SPRITES_PATH L"sprites\\samus\\samus_sprites.png"

#define APPEARING "sprites\\samus\\APPEARING.txt"
#define RUNNING_LEFT "sprites\\samus\\RUNNING_LEFT.txt"
#define RUNNING_RIGHT "sprites\\samus\\RUNNING_RIGHT.txt"
#define JUMP_LEFT "sprites\\samus\\JUMP_LEFT.txt"
#define JUMP_RIGHT "sprites\\samus\\JUMP_RIGHT.txt"
#define RUN_SHOOTING_LEFT "sprites\\samus\\RUN_SHOOTING_LEFT.txt"
#define RUN_SHOOTING_RIGHT "sprites\\samus\\RUN_SHOOTING_RIGHT.txt"
#define RUN_AIM_UP_LEFT "sprites\\samus\\RUN_AIM_UP_LEFT.txt"
#define RUN_AIM_UP_RIGHT "sprites\\samus\\RUN_AIM_UP_RIGHT.txt"
#define IDLE_AIM_UP_LEFT "sprites\\samus\\IDLE_AIM_UP_LEFT.txt"
#define IDLE_AIM_UP_RIGHT "sprites\\samus\\IDLE_AIM_UP_RIGHT.txt"
#define STANDING_LEFT "sprites\\samus\\STANDING_LEFT.txt"
#define STANDING_RIGHT "sprites\\samus\\STANDING_RIGHT.txt"
#define MORPH_BALL_LEFT "sprites\\samus\\MORPH_BALL_LEFT.txt"
#define MORPH_BALL_RIGHT "sprites\\samus\\MORPH_BALL_RIGHT.txt"
#define SOMERSAULT_LEFT "sprites\\samus\\SOMERSAULT_LEFT.txt"
#define SOMERSAULT_RIGHT "sprites\\samus\\SOMERSAULT_RIGHT.txt"
#define JUMPING_SHOOTING_LEFT "sprites\\samus\\JUMP_SHOOTING_LEFT.txt"
#define JUMPING_SHOOTING_RIGHT "sprites\\samus\\JUMP_SHOOTING_RIGHT.txt"
#define JUMP_AIM_UP_LEFT "sprites\\samus\\JUMP_AIM_UP_LEFT.txt"
#define JUMP_AIM_UP_RIGHT "sprites\\samus\\JUMP_AIM_UP_RIGHT.txt"
#define STAND_SHOOTING_LEFT "sprites\\samus\\STAND_SHOOTING_LEFT.txt"
#define STAND_SHOOTING_RIGHT "sprites\\samus\\STAND_SHOOTING_RIGHT.txt"
#define STAND_SHOOTING_UP_LEFT "sprites\\samus\\STAND_SHOOTING_UP_LEFT.txt"
#define STAND_SHOOTING_UP_RIGHT "sprites\\samus\\STAND_SHOOTING_UP_RIGHT.txt"
#define JUMP_SHOOTING_UP_LEFT "sprites\\samus\\JUMP_SHOOTING_UP_LEFT.txt"
#define JUMP_SHOOTING_UP_RIGHT "sprites\\samus\\JUMP_SHOOTING_UP_RIGHT.txt"

#define APPEARING_WIDTH 32
#define APPEARING_HEIGHT 64
#define RUNNING_WIDTH 36
#define RUNNING_HEIGHT 64
#define JUMP_WIDTH 36
#define JUMP_HEIGHT 50
#define RUN_SHOOTING_WIDTH 50
#define RUN_SHOOTING_HEIGHT 62
#define RUN_AIM_UP_WIDTH 34
#define RUN_AIM_UP_HEIGHT 76
#define IDLE_AIM_UP_WIDTH 29
#define IDLE_AIM_UP_HEIGHT 77
#define STANDING_WIDTH 42
#define STANDING_HEIGHT 64
#define MORPH_BALL_WIDTH 24
#define MORPH_BALL_HEIGHT 26
#define RUN_SHOOTING_WIDTH 44
#define RUN_SHOOTING_HEIGHT 62
#define SOMERSAULT_WIDTH 37
#define SOMERSAULT_HEIGHT 46
#define JUMPING_SHOOTING_WIDTH 46
#define JUMPING_SHOOTING_HEIGHT 50
#define JUMP_AIM_UP_WIDTH 37
#define JUMP_AIM_UP_HEIGHT 64
#define STANDING_SHOOTING_WIDTH 38
#define STANDING_SHOOTING_HEIGHT 64
#define STANDING_SHOOTING_UP_WIDTH 29
#define STANDING_SHOOTING_UP_HEIGHT 72
#define JUMP_SHOOTING_UP_WIDTH 37
#define JUMP_SHOOTING_UP_HEIGHT 60

#define APPEARING_COUNT 5
#define RUNNING_COUNT 3
#define JUMP_COUNT 1
#define RUN_SHOOTING_COUNT 3
#define RUN_AIM_UP_COUNT 3
#define IDLE_AIM_UP_COUNT 1
#define STANDING_COUNT 1
#define MORPH_BALL_COUNT 4
#define RUN_SHOOTING_COUNT 3
#define SPRITE_PER_ROW 1
#define SOMERSAULT_COUNT 4
#define JUMPING_SHOOTING_COUNT 1
#define JUMP_AIM_UP_COUNT 1
#define STAND_SHOOTING_COUNT 1
#define STAND_SHOOTING_UP_COUNT 1
#define JUMP_SHOOTING_UP_COUNT 1

#define ANIMATE_RATE 15

#define JUMP_VELOCITY_BOOST 0.05f
#define JUMP_VELOCITY_BOOST_FIRST 0.8f
#define FALLDOWN_VELOCITY_DECREASE 0.2f
//================== END SAMUS ====================

//================== ENEMY =====================
//================== BEDGEHOG =====================
#define ENEMY_SPRITE_PATH L"sprites\\enemy\\metroid_enemies_sheet.png"

#define BEDGEHOG_WIDTH 32
#define BEDGEHOG_HEIGHT 25

#define BEDGEHOG_SPRITE_COUNT 2

//--YElLOW
#define BEDGEHOG_YELLOW_UP "sprites\\enemy\\BEDGEHOG_YELLOW_UP.txt"
#define BEDGEHOG_YELLOW_BOTTOM "sprites\\enemy\\BEDGEHOG_YELLOW_BOTTOM.txt"
#define BEDGEHOG_YELLOW_LEFT "sprites\\enemy\\BEDGEHOG_YELLOW_LEFT.txt"
#define BEDGEHOG_YELLOW_RIGHT "sprites\\enemy\\BEDGEHOG_YELLOW_RIGHT.txt"

//PINK
#define BEDGEHOG_PINK_UP "sprites\\enemy\\BEDGEHOG_PINK_UP.txt"
#define BEDGEHOG_PINK_BOTTOM "sprites\\enemy\\BEDGEHOG_PINK_BOTTOM.txt"
#define BEDGEHOG_PINK_LEFT "sprites\\enemy\\BEDGEHOG_PINK_LEFT.txt"
#define BEDGEHOG_PINK_RIGHT "sprites\\enemy\\BEDGEHOG_PINK_RIGHT.txt"
//================== END BEDGEHOG =================

//================== BIRD  =====================

//--IDLE
#define BIRD_WIDTH 32
#define BIRD_HEIGHT 52

#define BIRD_IDLE_SPRITE_COUNT 1

#define BIRD_IDLE "sprites\\enemy\\BIRD_IDLE.txt"

//--FLY
#define BIRD_WIDTH 32
#define BIRD_HEIGHT 52

#define BIRD_FLY_SPRITE_COUNT 3

#define BIRD_FLY "sprites\\enemy\\BIRD_FLY.txt"
//================== END BIRD =================

//================== BLOCK =====================

#define BLOCK_WIDTH 36
#define BLOCK_HEIGHT 20

#define BLOCK_SPRITE_COUNT 1

//--YElLOW
#define BLOCK_LEFT "sprites\\enemy\\BLOCK_LEFT.txt"
#define BLOCK_RIGHT "sprites\\enemy\\BLOCK_RIGHT.txt"
//================== END BLOCK =================

//================== END ENEMY =================

//================= BRICK ====================
#define BRICK_1_PATH L"map\\brick_blue.png"
#define BRICK_1_WIDTH_COUNT 5
#define BRICK_1_HEIGHT_COUNT 4
#define BRICK_WIDTH 32
#define BRICK_HEIGHT 32

enum BRICK_TYPE
{
	BLUE = 1
};
//================ END BRICK ==================


//================ SAMUS BULLET ===============
enum BULLET_DIRECTION
{
	NONE,
	ON_LEFT,
	ON_RIGHT,
	ON_UP
};
//================= END SAMUS BULLET ===========

//================= OBJECT TYPE ================
enum OBJECT_TYPE
{
	SAMUS = 1,
	ENEMY = 2,
	BRICK = 3,
	PROJECTILE = 4
};
//================= END OBJECT TYPE ============

//================= ENEMY TYPE =================
enum ENEMY_TYPE
{
	//--TO DO: Bổ sung các type enemy
	BEDGEHOG_YELLOW,
	BEDGEHOG_PINK,
	BIRD,
	BLOCK
};
//================= END ENEMY TYPE =============