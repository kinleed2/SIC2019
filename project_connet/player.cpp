#include "all.h"

OBJ2D player;
extern OBJ2D map[24][32];
extern int game_timer;


void player_init()
{

	player.data = sprPlayer;
	player.texPivot = VECTOR2(0, 0);
	player.texSize = VECTOR2(80, 112);
	player.texPos = VECTOR2(0, 0);
	player.scale = VECTOR2(1, 1);

	player.pos.x = 0;
	player.pos.y = 800;

	player.direction = right;
	player.connectFlag = FALSE;
	player.cnt = 0;
	player.score = 0;
	
	player.type = 0;
}

void player_update()
{

	player.rpos.x = player.pos.x + 15;
	player.rpos.y = player.pos.y + 20;


	if (player.type == 0)
	{
		//右に移動する
		if (STATE(0) & PAD_RIGHT)
		{
			player.direction = right;
			//player.pos.x += 5;
			if (player.speed.x < 5 && game_timer % 2 == 0)
			{
				player.speed.x++;
			}
		}
		//滑る
		else if (player.speed.x > 0 && game_timer % 1 == 0)
		{
			player.speed.x--;

		}
		//左に移動する
		if (STATE(0) & PAD_LEFT)
		{
			player.direction = left;
			//player.pos.x -= 5;
			if (player.speed.x > -5 && game_timer % 2 == 0)
			{
				player.speed.x--;
			}

		}
		//滑る
		else if (player.speed.x < 0 && game_timer % 1 == 0)
		{
			player.speed.x++;
		}

		player.pos.x += player.speed.x;

		if (STATE(0) & PAD_UP)
		{
			player.direction = up;

		}
	}
	

	//落下
	player.groundFlag = FALSE;
	int i, j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == 1 
				&& player.pos.x <= map[i][j].pos.x + 20
				&& player.pos.x + 80 >= map[i][j].pos.x +20
				&& player.pos.y + PL_HEIGHT == map[i][j].pos.y)
			{
				player.groundFlag = TRUE;
			}
		}
	}
	if (player.groundFlag == FALSE && player.type == 0)
	{
		player.pos.y += 20;
	}

	//飛ぶ
	
	if (player.type == 0 && player.groundFlag == TRUE)
	{
		player.hookFlag = FALSE;
		switch (player.direction)
		{
		case right:
			player.hookPos.x = player.pos.x + 4 * MAPCHIP_SIZE;
			break;
		case left:
			player.hookPos.x = player.pos.x - 2 * MAPCHIP_SIZE;
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
					&& player.hookPos.y + 2 * MAPCHIP_SIZE >= map[i][j].pos.y
					&& player.hookPos.y <= map[i][j].pos.y
					&& player.hookPos.x >= map[i][j].pos.x
					&& player.hookPos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
				{
					if (STATE(0) & PAD_R1)
					{
						player.hookFlag = TRUE;
					}
					

					player.hookPos.y = map[i][j].pos.y;

					break;

				}
			}
		}
	}
	
	if (player.hookFlag)
	{
		if (TRG(0)& PAD_TRG1)
		{
			player.type = 1;
			switch (player.direction)
			{
			case right:
				player.speed.x = +2;
				break;
			case left:
				player.speed.x = -2;
				break;
			case up:
				break;
			default:
				break;
			}
			player.speed.y = -5;
		}
		//player.pos.x = player.hookPos.x;
		//player.pos.y = player.hookPos.y - PL_HEIGHT;
	}
	if (player.type == 1)
	{
		
		player.pos.x += player.speed.x;
		player.pos.y += player.speed.y;
	}
	if (player.pos.y <= player.hookPos.y - PL_HEIGHT -  MAPCHIP_SIZE - 20)
	{
		player.type = 0;
		player.hookFlag = FALSE;
	}


	//連結
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == 2
				&& map[i][j].connectFlag == FALSE
				&& player.pos.y + MAPCHIP_SIZE == map[i][j].pos.y
				&& player.pos.x + 2 * MAPCHIP_SIZE >= map[i][j].pos.x
				&& player.pos.x <= map[i][j].pos.x + MAPCHIP_SIZE)
			{
				if (TRG(0)&PAD_TRG1)
				{
					map[i][j].connectFlag = TRUE;
					player.cnt++;
				}
	

			}
		}
	}
	

	// 自機の移動制限
	if (player.pos.x < 0)                    player.pos.x = 0;
	if (player.pos.x > SCREEN_WIDTH - PL_WIDTH)     player.pos.x = SCREEN_WIDTH - PL_WIDTH;
	if (player.pos.y < 0)                   player.pos.y = 0;
	if (player.pos.y > SCREEN_HEIGHT - PL_HEIGHT -  MAPCHIP_SIZE)   player.pos.y = SCREEN_HEIGHT - PL_HEIGHT -  MAPCHIP_SIZE;


	if (player.type == 1)
	{
		if (player.anime == 6)
		{
			player.anime = 6;
		}
		else
		{
			if (player.direction == right)
			{
				player.texPos.y = (right + 2) * player.texSize.y;
			}

			if (player.direction == left)
			{
				player.texPos.y = (left + 2) * player.texSize.y;
			}
			//動画未完成
			player.anime = 4 + game_timer / 10 % 3;
		}
		
		
	}
	else
	{
		player.anime = 0;

		if (player.direction == right)
		{
			player.texPos.y = right;

		}
		if (player.direction == left)
		{
			player.texPos.y = left * player.texSize.y;
		}
		if (STATE(0) & PAD_RIGHT || STATE(0) & PAD_LEFT)
		{
			player.anime = 2 + game_timer / 10 % 8;
		}
		else
		{
			player.anime = game_timer / 25 % 2;
		}
	}

	
	




}


void player_draw()
{

	primitive::rect(player.pos.x + 15, player.pos.y + 20, 50, 80, 0, 1, 0, 0, 1);


	sprite_render(player.data,                  // 使用するスプライト
		player.pos.x, player.pos.y + 8,             // 位置
		player.scale.x, player.scale.y,         // スケールv
		player.texPos.x + player.anime * player.texSize.x, player.texPos.y,       // 元画像位置
		player.texSize.x, player.texSize.y,     // 元画像大きさ
		player.texPivot.x, player.texPivot.y,   // 基準点の位置
		0.0f,
		1,1,1,1
		);

	
	
	if (player.hookFlag && player.type == 0)
	{
		primitive::circle(player.hookPos.x, player.hookPos.y + 20, 20, 0, 1, 0);
	}
	
	int hook = 0;

	if (player.type == 1 && player.pos.y >= player.hookPos.y + 30)
	{
		
		
		//sprite_render(sprHook,                  // 使用するスプライト
		//	player.pos.x + 60, player.pos.y + 10,             // 位置
		//	1, 1,         // スケールv
		//	0, 0,      // 元画像位置
		//	40, 40,   // 元画像大きさ
		//	0, 0,   // 基準点の位置
		//	ToRadian(-60),
		//	1, 1, 1, 1
		//	);
		sprite_render(sprHook,                  // 使用するスプライト
			player.hookPos.x + 20 , player.hookPos.y + 15,             // 位置
			1,1 ,         // スケールv
			40,0,      // 元画像位置
			40,40,   // 元画像大きさ
			20,20,   // 基準点の位置
			ToRadian(-60),
			1, 1, 1, 1
			);
		primitive::line(player.pos.x + 80, player.pos.y + 20, player.hookPos.x, player.hookPos.y + 40, 0, 0, 0, 1, 2);
	}


	//debug
	debug::setString("player.hp:%d", player.hp);
	debug::setString("player.score:%d", player.score);
	debug::setString("player.cnt:%d", player.cnt);
	debug::setString("player.x:%f player.y:%f", player.pos.x, player.pos.y);
	debug::setString("player.speed.x:%f player.speed.y:%f", player.speed.x, player.speed.y);
	debug::setString("player.anime:%d", player.anime);
	debug::setString("player.hook:%d", hook);

}

