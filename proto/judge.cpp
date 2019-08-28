#include"all.h"


extern int game_state;
extern OBJ2D player;
extern int lineState;


void judge_update()
{

	if (lineState == 2 && player.pos.x == 768 && player.pos.y == 576)
	{
		game_state = 2;
	}

}