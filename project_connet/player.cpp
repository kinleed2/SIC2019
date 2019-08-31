#include "all.h"

OBJ2D player;
extern OBJ2D map[24][32];
extern int game_timer;

void player_init()
{
	player.pos.x = 0;
	player.pos.y = 800;
	player.direction = right;
	player.connectFlag = FALSE;
	player.cnt = 0;
	player.score = 0;
	player.hp = 3;
}

void player_update()
{
	//‰E‚ÉˆÚ“®‚·‚é
	if (STATE(0) & PAD_RIGHT)
	{
		player.direction = right;
		//player.pos.x += 5;
		if (player.speed.x < 10 && game_timer % 2 == 0)
		{
			player.speed.x++;
		}
	}
	//ŠŠ‚é
	else if (player.speed.x > 0 && game_timer % 3 == 0)
	{
		player.speed.x--;
		
	}
	//¶‚ÉˆÚ“®‚·‚é
	if (STATE(0) & PAD_LEFT)
	{
		player.direction = left;
		//player.pos.x -= 5;
		if (player.speed.x > -10 && game_timer % 2 == 0)
		{
			player.speed.x--;
		}
		
	}
	//ŠŠ‚é
	else if (player.speed.x < 0 && game_timer % 3 == 0)
	{
		player.speed.x++;
	}

	player.pos.x += player.speed.x;
	
	if (STATE(0) & PAD_UP)
	{
		player.direction = up;

	}



	//—Ž‰º
	player.groundFlag = 0;
	int i, j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == 1 
				&& player.pos.x <= map[i][j].pos.x + MAPCHIP_SIZE 
				&& player.pos.x >= map[i][j].pos.x 
				&& player.pos.y + PL_HEIGHT == map[i][j].pos.y)
			{
				player.groundFlag = TRUE;
			}
		}
	}
	if (player.groundFlag == FALSE)
	{
		player.pos.y += 40;
	}


	//”ò‚Ô
	player.hookFlag = FALSE;
	switch (player.direction)
	{
	case right:
		player.hookPos.x = player.pos.x + 5 * MAPCHIP_SIZE;
		break;
	case left:
		player.hookPos.x = player.pos.x - 3 * MAPCHIP_SIZE;
		break;
	case up:
		player.hookPos.x = player.pos.x + MAPCHIP_SIZE;
		break;
	default:
		break;
	}

	player.hookPos.y = player.pos.y - PL_HEIGHT;

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
		if (map[i][j].type == 1
			&& player.hookPos.y == map[i][j].pos.y
			&& player.hookPos.x >= map[i][j].pos.x
			&& player.hookPos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
			{
				player.hookFlag = TRUE;
				player.hookPos.x = map[i][j].pos.x;
				player.hookPos.y = map[i][j].pos.y;
				
			}
		}
	}
	if (player.hookFlag)
	{
		if (TRG(0)& PAD_TRG1)
		{
			player.pos.x = player.hookPos.x;
			player.pos.y = player.hookPos.y - PL_HEIGHT;

		}
	}

	//˜AŒ‹
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == 2
				//&& map[i][j].connectFlag == FALSE
				&& player.pos.y + MAPCHIP_SIZE == map[i][j].pos.y
				&& player.pos.x + 2 * MAPCHIP_SIZE >= map[i][j].pos.x
				&& player.pos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
			{
				if (TRG(0)&PAD_TRG2)
				{
					map[i][j].connectFlag = TRUE;
					player.cnt++;
				}
	

			}
		}
	}
	

	// Ž©‹@‚ÌˆÚ“®§ŒÀ
	if (player.pos.x < 0)                    player.pos.x = 0;
	if (player.pos.x > SCREEN_WIDTH - PL_WIDTH)     player.pos.x = SCREEN_WIDTH - PL_WIDTH;
	if (player.pos.y < 0)                   player.pos.y = 0;
	if (player.pos.y > SCREEN_HEIGHT - PL_HEIGHT -  MAPCHIP_SIZE)   player.pos.y = SCREEN_HEIGHT - PL_HEIGHT -  MAPCHIP_SIZE;



	

}


void player_draw()
{

	primitive::rect(player.pos.x, player.pos.y,80,120,0,0,0,1,0,0);
	
	if (player.hookFlag)
	{
		primitive::circle(player.hookPos.x + 20, player.hookPos.y + 20, 20, 0, 1, 0);
	}





	//debug
	debug::setString("player.hp:%d", player.hp);
	debug::setString("player.score:%d", player.score);
	debug::setString("player.cnt:%d", player.cnt);
	debug::setString("player.x:%f player.y:%f", player.pos.x, player.pos.y);
}

