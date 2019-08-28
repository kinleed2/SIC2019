#include "all.h"

OBJ2D player;
int state1 = 0;
extern int game_timer;

void player_init()
{
	player.pos.x = 100;
	player.pos.y = 600;
	


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



}


void player_draw()
{

	primitive::rect(player.pos.x, player.pos.y,80,120,0,0,0,1,0,0);

	//debug
	debug::setString("player.x:%f player.y:%f", player.pos.x, player.pos.y);
	debug::setString("player.speed.x:%f", player.speed.x);

}