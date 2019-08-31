#include "all.h"

extern OBJ2D player;
extern OBJ2D map[24][32];
extern OBJ2D enemy[3];
extern int game_state;

int check_conncet()
{
	int checkConnect = 0;
	int i, j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == 2
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
	return FALSE;
}

void check_enemy_guard(int returnStage)
{
	int l;
	for (l = 0; l < 3; l++)
	{

		if (enemy[l].exist == FALSE) continue;


		if (enemy[l].direction == right
			&& player.pos.x < enemy[l].pos.x + 80 + 100
			&& player.pos.x + 80 > enemy[l].pos.x
			&&player.pos.y + 120 >= enemy[l].pos.y
			&& player.pos.y < enemy[l].pos.y + 120)
		{
			player.hp--;
			game_state = returnStage;
		}

		if (enemy[l].direction == left
			&& player.pos.x + 80 < enemy[l].pos.x + 80
			&& player.pos.x + 80 > enemy[l].pos.x - 100
			&& player.pos.y + 120 >= enemy[l].pos.y
			&& player.pos.y < enemy[l].pos.y + 120)
		{
			player.hp--;
			game_state = returnStage;
		}

		int i, j, k = 0;
		for (i = 0; i < 24; i++)
		{
			for (j = 0; j < 32; j++)
			{

				if (map[i][j].type == 2
					&& map[i][j].connectFlag == TRUE)
				{
					k++;
					if (enemy[l].pos.y + MAPCHIP_SIZE == map[i][j].pos.y
						&& enemy[l].pos.x + 2 * MAPCHIP_SIZE >= map[i][j].pos.x
						&& enemy[l].pos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
					{
						map[i][j].connectFlag = FALSE;
						player.cnt = 0;

						if (k == 2)
						{
							player.score--;
						}
					}
				}
			}
		}


	}
		
	
	
	

	//debug::setString("check.hp:%d", player.hp);
}



void check(int returnStage,int nextStage)
{
	check_enemy_guard(returnStage);

	int i, j;
	for ( i = 0; i < 24; i++)
	{
		for ( j = 0; j < 32; j++)
		{
			if (check_conncet() == TRUE
				&& map[i][j].type == 3
				&& player.pos.y + MAPCHIP_SIZE == map[i][j].pos.y
				&& player.pos.x >= map[i][j].pos.x - MAPCHIP_SIZE
				&& player.pos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
			{
				game_state = nextStage;
			}

		}
	}
	//debug::setString("check:%d", check_conncet());
}





