#include "all.h"

extern OBJ2D player;
extern OBJ2D map[24][32];
extern OBJ2D enemyGuard[3];
extern OBJ2D enemyUav[3];
extern OBJ2D enemyCamera[3];
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

		if (enemyGuard[l].exist == FALSE) continue;


		if (enemyGuard[l].direction == right
			&& player.pos.x < enemyGuard[l].pos.x + 80 + 100
			&& player.pos.x + 80 > enemyGuard[l].pos.x
			&&player.pos.y + 120 >= enemyGuard[l].pos.y
			&& player.pos.y < enemyGuard[l].pos.y + 120)
		{
			player.hp--;
			game_state = returnStage;
		}

		if (enemyGuard[l].direction == left
			&& player.pos.x < enemyGuard[l].pos.x + 80
			&& player.pos.x + 80 > enemyGuard[l].pos.x - 100
			&& player.pos.y + 120 >= enemyGuard[l].pos.y
			&& player.pos.y < enemyGuard[l].pos.y + 120)
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

					if (enemyGuard[l].pos.y + MAPCHIP_SIZE == map[i][j].pos.y
						&& enemyGuard[l].pos.x + 2 * MAPCHIP_SIZE >= map[i][j].pos.x
						&& enemyGuard[l].pos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
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

		if (k == 2 && player.cnt == 0)
		{
			for (i = 0; i < 24; i++)
			{
				for (j = 0; j < 32; j++)
				{
					map[i][j].connectFlag = FALSE;
				}
			}
		}
	}
		
	
	
	

	//debug::setString("check.hp:%d", player.hp);
}

void check_enemy_uav(int returnStage)
{
	int l;
	for (l = 0; l < 3; l++)
	{

		if (enemyUav[l].exist == FALSE) continue;


		if (player.pos.x < enemyUav[l].pos.x + 100
			&& player.pos.x > enemyUav[l].pos.x - 60
			&& player.pos.y > enemyUav[l].pos.y + 40
			&& player.pos.y < enemyUav[l].pos.y + 200)
		{
			player.hp--;
			game_state = returnStage;
		}

	}
}

void check_enemy_camera(int returnStage)
{
	int l;
	for (l = 0; l < 3; l++)
	{

		if (enemyCamera[l].exist == FALSE) continue;


		if (player.pos.x < enemyCamera[l].pos.x + 160
			&& player.pos.x > enemyCamera[l].pos.x
			&&player.pos.y  > enemyCamera[l].pos.y
			&& player.pos.y < enemyCamera[l].pos.y + 160)
		{
			player.hp--;
			game_state = returnStage;
		}


	}
}







void check(int returnStage,int nextStage)
{
	check_enemy_guard(returnStage);
	check_enemy_uav(returnStage);
	check_enemy_camera(returnStage);

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





