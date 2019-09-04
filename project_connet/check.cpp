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

void check_enemy_guard()
{
	int l;
	for (l = 0; l < 3; l++)
	{

		if (enemyGuard[l].exist == FALSE) continue;
		if (player.exist == FALSE) continue;

		if (enemyGuard[l].direction == right
			&& player.rpos.x < enemyGuard[l].pos.x + 80 + 100
			&& player.rpos.x + 50 > enemyGuard[l].pos.x
			&&player.rpos.y + 50 >= enemyGuard[l].pos.y
			&& player.rpos.y < enemyGuard[l].pos.y + 120)
		{
			enemyGuard[l].atk = 1;
			player.hp--;
			player.exist = FALSE;
		}

		if (enemyGuard[l].direction == left
			&& player.rpos.x < enemyGuard[l].pos.x + 80
			&& player.rpos.x + 50 > enemyGuard[l].pos.x - 100
			&& player.rpos.y + 50 >= enemyGuard[l].pos.y
			&& player.rpos.y < enemyGuard[l].pos.y + 120)
		{
			enemyGuard[l].atk = 1;
			player.hp--;
			player.exist = FALSE;
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
						player.score = 0;

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
					map[i][j].state = 0;
				}
			}
		}
	}
		
	//debug::setString("check.hp:%d", player.hp);
}

void check_enemy_uav()
{
	int l;
	for (l = 0; l < 3; l++)
	{

		if (enemyUav[l].exist == FALSE) continue;
		if (player.exist == FALSE) continue;

		if (player.rpos.x < enemyUav[l].pos.x + 100
			&& player.rpos.x + 50 > enemyUav[l].pos.x - 60
			&& player.rpos.y + 50 > enemyUav[l].pos.y + 40
			&& player.rpos.y < enemyUav[l].pos.y + 200)
		{
			enemyUav[l].atk = 1;
			player.hp--;
			player.exist = FALSE;
			
		}

	}
}

void check_enemy_camera()
{
	int l;
	for (l = 0; l < 3; l++)
	{

		if (enemyCamera[l].exist == FALSE) continue;
		if (player.exist == FALSE) continue;

		if (player.rpos.x < enemyCamera[l].pos.x + 160
			&& player.rpos.x + 50 > enemyCamera[l].pos.x
			&&player.rpos.y  + 50 > enemyCamera[l].pos.y + 60
			&& player.rpos.y < enemyCamera[l].pos.y + 160)
		{
			enemyCamera[l].atk = 1;
			player.hp--;
			player.exist = FALSE;
		}


	}
}







void check(int returnStage,int nextStage)
{
	check_enemy_guard();
	check_enemy_uav();
	check_enemy_camera();


	if (player.state == 2)
	{
		
		game_state = returnStage;
	}

	int i, j;
	for ( i = 0; i < 24; i++)
	{
		for ( j = 0; j < 32; j++)
		{

			if (check_conncet() == TRUE
				&& map[i][j].type == 3
				&& player.pos.y == map[i][j].pos.y
				&& player.pos.x >= map[i][j].pos.x - 10
				&& player.pos.x <= map[i][j].pos.x)
			{
				player.anime = 0;
				player.speed = VECTOR2(0, 0);
				game_state = nextStage;
			}

			if (map[i][j].type == 4 && map[i][j].state == 2)
			{
				player.atk = 1;
			}


		}
	}
	//debug::setString("check:%d", check_conncet());
}





