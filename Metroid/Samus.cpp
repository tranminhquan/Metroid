﻿#include "Samus.h"
#include "trace.h"
#include <limits>

void Samus::_Render()
{
	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	switch (state)
	{
	case RIGHTING:
		running_right->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case LEFTING:
		running_left->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case AIMING_UP_LEFT:
		run_aim_up_left->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case AIMING_UP_RIGHT:
		run_aim_up_right->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case IDLING_AIM_UP_LEFT:
		idle_aim_up_left->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case IDLING_AIM_UP_RIGHT:
		idle_aim_up_right->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case IDLE_LEFT:
		idle_left->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case IDLE_RIGHT:
		idle_right->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	}

	
	_SpriteHandler->End();
}

Samus::Samus()
{
	appearing = NULL;
	running_left = NULL;
	running_right = NULL;
	jump_left = NULL;
	jump_right = NULL;
}


Samus::~Samus()
{
	delete(appearing);
	delete(running_left);
	delete(running_right);
	delete(jump_left);
	delete(jump_right);
}

void Samus::InitSprites(LPDIRECT3DDEVICE9 d3ddv)
{
	if (d3ddv == NULL) return;
	//Create sprite handler
	HRESULT result =  D3DXCreateSprite(d3ddv, &_SpriteHandler);
	if (result != D3D_OK) return;

	//Create instance of sprites
	appearing = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, APPEARING, APPEARING_WIDTH, APPEARING_HEIGHT, APPEARING_COUNT, SPRITE_PER_ROW);
	running_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUNNING_LEFT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	running_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUNNING_RIGHT, RUNNING_WIDTH, RUNNING_HEIGHT, RUNNING_COUNT, SPRITE_PER_ROW);
	jump_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, JUMP_LEFT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	jump_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, JUMP_LEFT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	run_shooting_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_LEFT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_shooting_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_RIGHT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_aim_up_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_AIM_UP_LEFT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	run_aim_up_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_AIM_UP_RIGHT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, IDLE_AIM_UP_LEFT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, IDLE_AIM_UP_RIGHT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, STANDING_LEFT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
	idle_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, STANDING_RIGHT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
}

void Samus::InitPostition()
{
	//--TO DO: This code will be edited soon
	pos_x = 50;
	pos_y = 450;

	vx = 0;
	vx_last = 1.0f;
	vy = 0;

	//Init state of samus
	state = IDLE_RIGHT;
}

void Samus::SetVelocityX(float value)
{
	vx = value;
}

float Samus::GetVelocityX()
{
	return vx;
}

void Samus::SetVelocityXLast(float value)
{
	vx_last = value;
}

float Samus::GetVelocityXLast()
{
	return vx_last;
}

SAMUS_STATE Samus::GetState()
{
	return state;
}

void Samus::SetState(SAMUS_STATE value)
{
	state = value;
}

void Samus::ResetAllSprites()
{
	appearing->Reset();
	running_left->Reset();
	running_right->Reset();
	jump_left->Reset();
	jump_right->Reset();
	run_shooting_left->Reset();
	run_shooting_right->Reset();
	run_aim_up_left->Reset();
	run_aim_up_right->Reset();
	idle_aim_up_left->Reset();
	idle_aim_up_right->Reset();
	idle_left->Reset();
	idle_right->Reset();
}


void Samus::Update(int t)
{
	//
	// Update mario status
	//
	pos_x += vx*t;
	pos_y += vy*t;

	// Animate samus if he is running
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		switch (state)
		{
		case RIGHTING:
			running_right->Next();
			break;
		case LEFTING:
			running_left->Next();
			break;
		case AIMING_UP_LEFT:
			run_aim_up_left->Next();
			break;
		case AIMING_UP_RIGHT:
			run_aim_up_right->Next();
			break;
		case IDLING_AIM_UP_LEFT:
			idle_aim_up_left->Next();
			break;
		case IDLING_AIM_UP_RIGHT:
			idle_aim_up_right->Next();
			break;
		}

		last_time = now;
	}

	//Render
	_Render();

}

bool Samus::isColliding(GameObject object)
{
	float left = object.getPos_x - (this->pos_x + this->width);
	float right = (object.getPos_x + object.getWidth) - this->pos_x;
	float top = object.getPos_y - (this->getPos_y + this->height);
	float bottom = (object.getPos_y + object.getHeight) - this->pos_y;

	return !(left > 0 || right < 0 || top < 0 || bottom > 0);
}

float Samus::sweptAABB(GameObject object, float & normalx, float & normaly)
{
	float dxEntry, dxExit;
	float dyEntry, dyExit;

	// khoảng cách tới vật thể
	if (this->pos_x > 0.0f)
	{
		dxEntry = object.getPos_x - (this->pos_x + this->width);
		dxExit = (object.getPos_x + object.getWidth) - this->pos_x;
	}
	else
	{
		dxEntry = (object.getPos_x + object.getWidth) - this->pos_x;
		dxExit = object.getPos_x - (this->pos_x + this->width);
	}
	if (this->pos_y > 0.0f)
	{
		dyEntry = object.getPos_y - (this->pos_y + this->height);
		dyExit = (object.getPos_y + object.getHeight) - this->pos_y;
	}
	else
	{
		dyEntry = (object.getPos_y + object.getHeight) - this->pos_y;
		dyExit = object.getPos_y - (this->pos_y + this->height);
	}
	// tính thời gian va chạm theo trục
	float txEntry, txExit;
	float tyEntry, tyExit;

	if (this->vx == 0.0f) // đang đứng yên
	{
		txEntry = -std::numeric_limits<float>::infinity();
		txExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		txEntry = dxEntry / this->vx;
		txExit = dxExit / this->vx;
	}
	if (this->vy == 0.0f)
	{
		tyEntry = -std::numeric_limits<float>::infinity();
		tyExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		tyEntry = dyEntry / this->vy;
		tyExit = dyExit / this->vy;
	}
	//thời gian va chạm là thời gian lớn nhất của 2 trục
	float entryTime = std::fmax(txEntry, tyEntry);
	// thời gian hết va chạm là thời gian nhỏ nhất
	float ExitTime = std::fmin(txExit, tyExit);

	// kiểm tra có thể va chạm không

	if (entryTime > ExitTime || (txEntry < 0.0f && tyEntry < 0.0f) || txEntry > 1.0f || tyEntry > 1.0f)
	{
		// đứng yên
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f; // ko va chạm trong frame này
	}
	// lấy hướng va chạm
	if (txEntry > tyEntry)
	{
		if (dxEntry > 0.0f)
		{
			normalx = 1.0f;
			normaly = 0.0f;
		}
		else
		{
			normalx = -1.0f;
			normaly = 0.0f;
		}
	}
	else
	{
		if (dyEntry > 0.0f)
		{
			normalx = 0.0f;
			normaly = 1.0f;
		}
		else
		{
			normalx = 0.0f;
			normaly = -1.0f;
		}
	}
	return entryTime;
}
