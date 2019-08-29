#include "all.h"

OBJ2D player;
extern OBJ2D map[24][32];
extern int game_timer;

void player_init()
{
	player.pos.x = 0;
	player.pos.y = 0;


}

void player_update()
{
	//‰E‚ÉˆÚ“®‚·‚é
	if (STATE(0) & PAD_RIGHT)
	{
		if (player.speed.x < 10 && game_timer % 2 == 0)
		{
			player.speed.x++;
		}
	}
	//ŠŠ‚é
	else if (player.speed.x > 0)
	{
		if (game_timer % 4 == 0)
		{
			player.speed.x--;
		}
		
	}
	//¶‚ÉˆÚ“®‚·‚é
	if (STATE(0) & PAD_LEFT)
	{
		if (player.speed.x > -10 && game_timer % 2 == 0)
		{
			player.speed.x--;
		}
	}
	//ŠŠ‚é
	else if (player.speed.x < 0)
	{
		if (game_timer % 4 == 0)
		{
			player.speed.x++;
		}
	}
	player.pos.x += player.speed.x;
	
	


	//—Ž‰º
	int checkGround = 0;
	int i, j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == 1 
				&& player.pos.x <= map[i][j].pos.x + MAPCHIP_SIZE 
				&& player.pos.x >= map[i][j].pos.x 
				&& player.pos.y + MAPCHIP_SIZE * 2 == map[i][j].pos.y)
			{
				checkGround = 1;
			}
		}
	}
	if (checkGround == 0)
	{
		player.pos.y += 40;
	}

	//‰E‚É”ò‚Ô

	float checkFlyRposX = player.pos.x + 4 * MAPCHIP_SIZE;
	float checkFlyRposY = player.pos.y - 4 * MAPCHIP_SIZE;
	int checkFlyRflag = 0;

	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
		if (map[i][j].type == 1
			&& checkFlyRposY == map[i][j].pos.y
			&& checkFlyRposX >= map[i][j].pos.x 
			&& checkFlyRposX <= map[i][j].pos.x + MAPCHIP_SIZE)
			{
				checkFlyRflag = 1;
				checkFlyRposX == map[i][j].pos.x;
				checkFlyRposY == map[i][j].pos.y;
				
			}
		}
	}
	if (checkFlyRflag)
	{
		if (TRG(0)& PAD_TRG1)
		{
			player.pos.x = checkFlyRposX;
			player.pos.y = checkFlyRposY - 3 * MAPCHIP_SIZE;
		}
	}

	if (checkFlyRflag == 1)
	{
		primitive::circle(checkFlyRposX, checkFlyRposY, 20, 0, 1, 0);
	}

	// Ž©‹@‚ÌˆÚ“®§ŒÀ
	if (player.pos.x < 0)                    player.pos.x = 0;
	if (player.pos.x > SCREEN_WIDTH - PL_WIDTH)     player.pos.x = SCREEN_WIDTH - PL_WIDTH;
	if (player.pos.y < 0)                   player.pos.y = 0;
	if (player.pos.y > SCREEN_HEIGHT - PL_HEIGHT -  MAPCHIP_SIZE)   player.pos.y = SCREEN_HEIGHT - PL_HEIGHT -  MAPCHIP_SIZE;


	debug::setString("check:%d", checkFlyRflag);
	debug::setString("checkY:%f", checkFlyRposY);
	debug::setString("map y:%f", map[16][13].pos.y);
	debug::setString("map type:%d", map[16][13].type);
}


void player_draw()
{

	primitive::rect(player.pos.x, player.pos.y,80,120,0,0,0,1,0,0);
	
	//debug
	debug::setString("player.x:%f player.y:%f", player.pos.x, player.pos.y);
}

