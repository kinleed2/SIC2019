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
	enemy_0_move();
}


void enemy_draw()
{
	primitive::rect(enemy[0].pos.x, enemy[0].pos.y, 80, 120, 0, 0, 0, 1, 0, 1);


}

void enemy_0_move()
{
	switch (enemy[0].state)
	{
	case 0:
		enemy[0].pos.x -= 5;
		if (enemy[0].pos.x <= 120 )
		{
			enemy[0].state++;
		}
		break;
	case 1:
		enemy[0].pos.x += 5;
		if (enemy[0].pos.x >= 800)
		{
			enemy[0].state--;
		}
		break;
	default:
		break;
	}


}