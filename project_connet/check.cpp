#include "all.h"

extern OBJ2D player;
extern OBJ2D map[24][32];
extern int game_state;

int check_conncet(int mapType)
{
	int checkConnect = 0;
	int i, j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == mapType
				&& map[i][j].connectFlag == TRUE)
			{
				checkConnect++;
			}

		}
	}
	if (checkConnect == 2)
	{
		player.score = 1;
		return TRUE;
	}
		
}

void check()
{
	int i, j;
	for ( i = 0; i < 24; i++)
	{
		for ( j = 0; j < 32; j++)
		{
			if (check_conncet(2) == TRUE
				&& map[i][j].type == 3
				&& player.pos.y + MAPCHIP_SIZE == map[i][j].pos.y
				&& player.pos.x >= map[i][j].pos.x - MAPCHIP_SIZE
				&& player.pos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
			{
				game_state = 3;
			}

		}
	}
	debug::setString("check:%d", check_conncet(2));
}





