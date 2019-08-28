#include "all.h"

OBJ2D player;
int lineX_1, lineY_1,lineX_2,lineY_2,lineState = 0;

void player_init()
{	
	player.pos.x = 32;
	player.pos.y = 576;

}

void player_update()
{
	if (STATE(0) & PAD_RIGHT )
	{
		player.pos.x += 32;
		Sleep(100);
	}
	if (STATE(0) & PAD_LEFT )
	{
		player.pos.x -= 32;
		Sleep(100);
	}
	if (STATE(0) & PAD_UP)
	{
		player.pos.y -= 32;
		Sleep(100);
	}
	if (STATE(0) & PAD_DOWN)
	{
		player.pos.y += 32;
		Sleep(100);
	}
	//if (TRG_UP(0) & PAD_UP)
	//{
	//	int jumpState = 0;
	//	while(1)
	//	{
	//		switch (jumpState)
	//		{
	//		case 0:
	//			player.pos.y -= 32;
	//			jumpState++;
	//			break;
	//		case 1:
	//			player.pos.y -= 64;
	//			jumpState++;
	//			break;
	//		case 2:
	//			player.pos.y += 32;
	//			jumpState++;
	//			break;
	//		case 3:
	//			player.pos.y += 64;
	//			jumpState++;
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//
	//}

	if (TRG_UP(0) & PAD_TRG1)
	{
		switch (lineState)
		{
		case 0 :
			lineX_1 = player.pos.x;
			lineY_1 = player.pos.y;
			lineState++;
			break;
		case 1:
			lineX_2 = player.pos.x;
			lineY_2 = player.pos.y;
			lineState++;
			break;
		default:
			break;
		}
	

	}

}

void player_draw()
{
	primitive::circle(player.pos.x + 16, player.pos.y + 16, 16, 1, 0, 0);

	
	if (lineState == 1)
	{
		primitive::line(lineX_1+16 , lineY_1+16, player.pos.x+16, player.pos.y+16, 0, 0, 1);
	}
	else if (lineState == 2)
	{
		primitive::line(lineX_1 + 16, lineY_1 + 16, lineX_2 + 16, lineY_2 + 16, 0, 0, 1);
	}

	debug::setString("state:%d", lineState);
	debug::setString("x:%f y:%f", player.pos.x, player.pos.y);
}