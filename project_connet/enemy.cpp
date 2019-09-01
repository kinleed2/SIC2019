#include "all.h"

OBJ2D enemyGuard[3];
OBJ2D enemyUav[3];
OBJ2D enemyCamera[3];
extern int game_timer;

void enemy_init()
{

	int i;
	for (i = 0; i < 3; i++)
	{
		if (enemyGuard[i].exist == TRUE)
		{
			enemyGuard[i].exist = FALSE;
		}

	}
}

void enemy_update()
{
	//enemy_guard_move(300,700,1);
}


void enemy_draw()
{
	int i;
	for ( i = 0; i < 3; i++)
	{
		if (enemyGuard[i].exist == TRUE)
		{
			primitive::rect(enemyGuard[i].pos.x, enemyGuard[i].pos.y, 80, 120, 0, 0, 0, 1, 0, 1);
			if (enemyGuard[i].direction == right)
			{
				primitive::rect(enemyGuard[i].pos.x, enemyGuard[i].pos.y, 80 + 100, 120, 0, 0, 0, 1, 0, 1, 0.5);
			}
			else
			{
				primitive::rect(enemyGuard[i].pos.x - 100, enemyGuard[i].pos.y, 100, 120, 0, 0, 0, 1, 0, 1, 0.5);
			}
		}

		if (enemyUav[i].exist == TRUE)
		{
			primitive::rect(enemyUav[i].pos.x, enemyUav[i].pos.y, 40, 40, 0, 0, 0, 0.5, 0.5, 1);
			if (enemyUav[i].direction == right)
			{
				primitive::rect(enemyUav[i].pos.x, enemyUav[i].pos.y, 40 + 100, 40, 0, 0, 0, 0.5, 0, 0.5, 0.5);
			}
			else
			{
				primitive::rect(enemyUav[i].pos.x - 100, enemyUav[i].pos.y, 100, 40, 0, 0, 0, 0.5, 0, 0.5, 0.5);
			}
		}


		if (enemyCamera[i].exist == TRUE)
		{
			primitive::rect(enemyCamera[i].pos.x, enemyCamera[i].pos.y, 160, 160, 0, 0, 0, 0.2, 0.2, 1, 0.5);
			
		}



	}
	

}


void enemy_guard_init(OBJ2D *obj, int x, int y, int direction)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->direction = direction;
	obj->exist = TRUE;
}

void enemy_uav_init(OBJ2D *obj, int x, int y, int direction)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->direction = direction;
	obj->exist = TRUE;
}

void enemy_camera_init(OBJ2D *obj, int x, int y, int direction)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->direction = direction;
	obj->exist = TRUE;
}



void enemy_guard_move(OBJ2D *obj,int leftLimit, int rightLimit,int speed)
{

	switch (obj->direction)
	{
	case left:
		obj->pos.x -= speed;
		if (obj->pos.x <= leftLimit)
		{
			obj->direction = right;
		}
		break;
	case right:
		obj->pos.x += speed;
		if (obj->pos.x >= rightLimit)
		{
			obj->direction = left;
		}
		break;
	default:
		break;
	}


}


void enemy_uav_move(OBJ2D *obj, int mode,int leftLimit, int rightLimit, int speed,int upLimit, int downLimit)
{
	switch (mode)
	{
	case 1:
		switch (obj->direction)
		{
		case left:
			obj->pos.x -= speed;
			if (obj->pos.x <= leftLimit)
			{
				obj->direction = right;
			}
			break;
		case right:
			obj->pos.x += speed;
			if (obj->pos.x >= rightLimit)
			{
				obj->direction = left;
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (obj->direction)
		{
		case left:
			obj->pos.x -= speed;
			obj->pos.y -= speed;
			if (obj->pos.x <= leftLimit || obj->pos.y <= upLimit)
			{
				obj->direction = right;
			}
			break;
		case right:
			obj->pos.x += speed;
			obj->pos.y += speed;
			if (obj->pos.x >= rightLimit || obj->pos.x >= downLimit)
			{
				obj->direction = left;
			}
			break;

		default:
			break;
		}
	default:
		break;
	}
	


}

void enemy_camera_move(OBJ2D *obj, int leftLimit, int rightLimit, int speed)
{

	switch (obj->direction)
	{
	case left:
		obj->pos.x -= speed;
		if (obj->pos.x <= leftLimit)
		{
			obj->direction = right;
		}
		break;
	case right:
		obj->pos.x += speed;
		if (obj->pos.x >= rightLimit)
		{
			obj->direction = left;
		}
		break;
	default:
		break;
	}


}