#include "Samus.h"
#include "trace.h"


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
	case ON_MORPH_LEFT:
		morph_ball_left->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case ON_MORPH_RIGHT:
		morph_ball_right->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case ON_RUN_SHOOTING_LEFT:
		run_shooting_left->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case ON_RUN_SHOOTING_RIGHT:
		run_shooting_right->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case ON_JUMP_LEFT:
		jump_left->Render(pos_x, pos_y, pos_x - 400, 600);
		break;
	case ON_JUMP_RIGHT:
		jump_right->Render(pos_x, pos_y, pos_x - 400, 600);
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
	delete(run_shooting_left);
	delete(run_shooting_right);
	delete(run_aim_up_left);
	delete(run_aim_up_right);
	delete(idle_aim_up_left);
	delete(idle_aim_up_right);
	delete(idle_left);
	delete(idle_right);
	delete(morph_ball_left);
	delete(morph_ball_right);
	delete(run_shooting_left);
	delete(run_shooting_right);
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
	jump_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, JUMP_RIGHT, JUMP_WIDTH, JUMP_HEIGHT, JUMP_COUNT, SPRITE_PER_ROW);
	run_shooting_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_LEFT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_shooting_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_RIGHT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_aim_up_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_AIM_UP_LEFT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	run_aim_up_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_AIM_UP_RIGHT, RUN_AIM_UP_WIDTH, RUN_AIM_UP_HEIGHT, RUN_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, IDLE_AIM_UP_LEFT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_aim_up_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, IDLE_AIM_UP_RIGHT, IDLE_AIM_UP_WIDTH, IDLE_AIM_UP_HEIGHT, IDLE_AIM_UP_COUNT, SPRITE_PER_ROW);
	idle_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, STANDING_LEFT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
	idle_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, STANDING_RIGHT, STANDING_WIDTH, STANDING_HEIGHT, STANDING_COUNT, SPRITE_PER_ROW);
	morph_ball_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, MORPH_BALL_LEFT, MORPH_BALL_WIDTH, MORPH_BALL_HEIGHT, MORPH_BALL_COUNT, SPRITE_PER_ROW);
	morph_ball_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, MORPH_BALL_RIGHT, MORPH_BALL_WIDTH, MORPH_BALL_HEIGHT, MORPH_BALL_COUNT, SPRITE_PER_ROW);
	run_shooting_left = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_LEFT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
	run_shooting_right = new Sprite(_SpriteHandler, SAMUS_SPRITES_PATH, RUN_SHOOTING_RIGHT, RUN_SHOOTING_WIDTH, RUN_SHOOTING_HEIGHT, RUN_SHOOTING_COUNT, SPRITE_PER_ROW);
}

void Samus::InitPostition()
{
	//--TO DO: This code will be edited soon
	pos_x = 50;
	pos_y = GROUND_Y;

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

void Samus::SetVelocityY(float value)
{
	vy = value;
}

float Samus::GetVelocityY()
{
	return vy;
}

void Samus::SetPosX(int value)
{
	pos_x = value;
}

int Samus::GetPosX()
{
	return pos_x;
}

void Samus::SetPosY(int value)
{
	pos_y = value;
}

int Samus::GetPosY()
{
	return pos_y;
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
	morph_ball_left->Reset();
	morph_ball_right->Reset();
	run_shooting_left->Reset();
	run_shooting_right->Reset();
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
		case ON_MORPH_LEFT:
			morph_ball_left->Next();
			break;
		case ON_MORPH_RIGHT:
			morph_ball_right->Next();
			break;
		case ON_RUN_SHOOTING_LEFT:
			run_shooting_left->Next();
			break;
		case ON_RUN_SHOOTING_RIGHT:
			run_shooting_right->Next();
			break;
		case ON_JUMP_LEFT:
			jump_left->Next();
			break;
		case ON_JUMP_RIGHT:
			jump_right->Next();
			break;
		}

		last_time = now;
	}

	//**********************************************************************************
	// [CAUTION!!!] Vi pos_y chua chinh theo toa do World, code duoi day chi la tam thoi,
	// se cap nhat lai sau
	if (pos_y < GROUND_Y)
	{
		vy += FALLDOWN_VELOCITY_DECREASE;
	}
	else
	{
		pos_y = GROUND_Y;
		vy = 0;
		if (state == ON_JUMP_LEFT)
		{
			state = IDLE_LEFT;
		}
		else if (state == ON_JUMP_RIGHT)
		{
			state = IDLE_RIGHT;
		}
	}
	//************************************************************************************

	//Render
	_Render();

}