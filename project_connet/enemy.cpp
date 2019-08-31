#include "all.h"

OBJ2D enemy[3];
extern int game_timer;

void enemy_init()
{

	int i;
	for (i = 0; i < 3; i++)
	{
		if (enemy[i].exist == TRUE)
		{
			enemy[i].exist = FALSE;
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
		if (enemy[i].exist == TRUE)
		{
			primitive::rect(enemy[i].pos.x, enemy[i].pos.y, 80, 120, 0, 0, 0, 1, 0, 1);
			if (enemy[i].direction == right)
			{
				primitive::rect(enemy[i].pos.x, enemy[i].pos.y, 80 + 100, 120, 0, 0, 0, 1, 0, 1, 0.5);
			}
			else
			{
				primitive::rect(enemy[i].pos.x - 100, enemy[i].pos.y, 100, 120, 0, 0, 0, 1, 0, 1, 0.5);
			}
		}
	}
	

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


void enemy_guard_init(OBJ2D *obj,int x,int y,int direction)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->direction = direction;
	obj->exist = TRUE;
}