#include "all.h"

OBJ2D enemy[3];
extern int game_timer;

void enemy_init()
{

	enemy[0].pos.x = 690;
	enemy[0].pos.y = 800;
	enemy[0].state = 0;
}

void enemy_update()
{
	enemy_0_move(300,700);
}


void enemy_draw()
{
	primitive::rect(enemy[0].pos.x, enemy[0].pos.y, 80, 120, 0, 0, 0, 1, 0, 1);
	if (enemy[0].direction == right)
	{
		primitive::rect(enemy[0].pos.x, enemy[0].pos.y, 80 + 100, 120, 0, 0, 0, 1, 0, 1,0.5);
	}
	else
	{
		primitive::rect(enemy[0].pos.x -100, enemy[0].pos.y, 100, 120, 0, 0, 0, 1, 0, 1, 0.5);
	}

}

void enemy_0_move(int leftLimit, int rightLimit)
{
	switch (enemy[0].state)
	{
	case 0:
		enemy[0].direction = left;
		enemy[0].pos.x -= 1;
		if (enemy[0].pos.x <= leftLimit)
		{
			enemy[0].state++;
		}
		break;
	case 1:
		enemy[0].direction = right;
		enemy[0].pos.x += 1;
		if (enemy[0].pos.x >= rightLimit)
		{
			enemy[0].state--;
		}
		break;
	default:
		break;
	}


}