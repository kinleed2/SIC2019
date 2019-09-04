#include "all.h"

OBJ2D player;
extern OBJ2D map[24][32];


void player_init()
{
	player.data = sprPlayer;
	player.texPivot = VECTOR2(0, 0);
	player.texSize = VECTOR2(80, 120);
	player.texPos = VECTOR2(0, 0);
	player.scale = VECTOR2(1, 1);

	player.pos.x = 0;
	player.pos.y = 800;
	player.timer = 0;
	player.direction = right;
	player.connectFlag = FALSE;
	player.cnt = 0;
	player.score = 0;
	player.exist = TRUE;
	player.state = 0;

	player.speed = VECTOR2(0, 0);
}

void player_update()
{
	player.timer++;
	player.rpos.x = player.pos.x + 15;
	player.rpos.y = player.pos.y + 30;

	//

	if (player.exist == FALSE)
	{
		//player.anime = 0;
		sound::play(8);
		player_fall();

		player.anime = player.timer / 64 % 4;

		if (player.anime == 3)
		{
			Sleep(500);
			player.state = 2;
		}

	}
	else
	{

		player_move();


		//����
		player_fall();

		//���

		player_hook();

		//�A��
		player_connect();
	}
	



		// ���@�̈ړ�����
		if (player.pos.y < 0)                   player.pos.y = 0;
		if (player.pos.y > SCREEN_HEIGHT - PL_HEIGHT - MAPCHIP_SIZE)   player.pos.y = SCREEN_HEIGHT - PL_HEIGHT - MAPCHIP_SIZE;
}


void player_draw()
{
	//primitive::rect(player.pos.x + 15, player.pos.y + 30, 50, 50, 0, 1, 0, 0, 1);

	if (player.exist == TRUE)
	{


		sprite_render(player.data,                  // �g�p����X�v���C�g
			player.pos.x, player.pos.y,             // �ʒu
			player.scale.x, player.scale.y,         // �X�P�[��v
			player.texPos.x + player.anime * player.texSize.x, player.texPos.y,       // ���摜�ʒu
			player.texSize.x, player.texSize.y,     // ���摜�傫��
			player.texPivot.x, player.texPivot.y,   // ��_�̈ʒu
			0.0f,
			1.0f, 1.0f, 1.0f, 1.0f
			);

	}
	
	
	if (player.hookFlag && player.state == 0)
	{
		//primitive::circle(player.hookPos.x, player.hookPos.y + 20, 20, 0, 1, 0);

		sprite_render(sprItem,                  // �g�p����X�v���C�g
			player.hookPos.x, player.hookPos.y,             // �ʒu
			1, 1,         // �X�P�[��v
			0,120 + 60,       // ���摜�ʒu
			40, 40,     // ���摜�傫��
			0, 0,   // ��_�̈ʒu
			0.0f,
			1, 1, 1, 1
			);
	}
	

	int hook = 0;

	if (player.state == 1 && player.pos.y >= player.hookPos.y + 30)
	{
		
		sprite_render(sprItem,                  // �g�p����X�v���C�g
			player.hookPos.x + 20 , player.hookPos.y + 20,             // �ʒu
			1,1 ,         // �X�P�[��v
			0,120,      // ���摜�ʒu
			60,60,   // ���摜�傫��
			30,30,   // ��_�̈ʒu
			0,
			1, 1, 1, 1
			);
		if (player.direction == right)
		{
			primitive::line(player.pos.x + 80, player.pos.y + 20, player.hookPos.x + 20, player.hookPos.y + 22, 0, 0, 0, 1, 2);
		}
		else if (player.direction == left)
		{
			primitive::line(player.pos.x, player.pos.y + 20, player.hookPos.x + 20, player.hookPos.y + 22, 0, 0, 0, 1, 2);
		}
		else
		{
			primitive::line(player.pos.x + 20, player.pos.y + 20, player.hookPos.x + 20, player.hookPos.y + 22, 0, 0, 0, 1, 2);
		}
	}


	//HP�̕\��
	int hpPos = 50;
	int i;
	for (i = 0; i < player.hp; i++)
	{
		sprite_render(player.data,                  // �g�p����X�v���C�g
			hpPos, 0,             // �ʒu
			1, 1,         // �X�P�[��v
			1200, 0,       // ���摜�ʒu
			80, 80,     // ���摜�傫��
			0, 0,   // ��_�̈ʒu
			0.0f,
			1, 1, 1, 1);
		hpPos += 100;

	}

	if (player.exist == FALSE)
	{
		if (player.state == 0 || player.state == 1)
		{
			sprite_render(sprItem,                  // �g�p����X�v���C�g
				player.pos.x - 80, player.pos.y,             // �ʒu
				1, 1,         // �X�P�[��v
				0 + player.anime * 240, 0,       // ���摜�ʒu
				240, 120,     // ���摜�傫��
				0, 0,   // ��_�̈ʒu
				0.0f,
				1, 1, 1, 1
				);
		}

	}




debug::setString("player.hp:%d", player.hp);
debug::setString("player.score:%d", player.score);
debug::setString("player.cnt:%d", player.cnt);
debug::setString("player.x:%f player.y:%f", player.pos.x, player.pos.y);
debug::setString("player.speed.x:%f player.speed.y:%f", player.speed.x, player.speed.y);
debug::setString("player.anime:%d", player.anime);
debug::setString("player.hook:%d", hook);
	debug::setString("player.timer;%d", player.timer);

}

void player_move()
{

	if (player.state == 0)
	{
		//�E�Ɉړ�����
		if (STATE(0) & PAD_RIGHT)
		{
			player.direction = right;
			//player.pos.x += 5;
			if (player.speed.x < 5 && player.timer % 2 == 0)
			{
				player.speed.x++;
				
			}
			
		}
		//����
		else if (player.speed.x > 0 && player.timer % 2 == 0)
		{
			player.speed.x--;


		}
		//���Ɉړ�����
		if (STATE(0) & PAD_LEFT)
		{
			player.direction = left;
			//player.pos.x -= 5;
			if (player.speed.x > -5 && player.timer % 2 == 0)
			{
				player.speed.x--;
				
			}

		}
		//����
		else if (player.speed.x < 0 && player.timer % 2 == 0)
		{
			player.speed.x++;
		}

		player.pos.x += player.speed.x;
		//if (player.speed.x ==1)
		//{
		//	sound::play(1);
		//}

		if (STATE(0) & PAD_UP)
		{
			player.direction = up;
			
		}
		
	}



	if (player.pos.x < 0)                    player.pos.x = 0;
	if (player.pos.x > SCREEN_WIDTH - PL_WIDTH)     player.pos.x = SCREEN_WIDTH - PL_WIDTH;


	if (player.state == 0)
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
			player.anime = 2 + player.timer / 10 % 7;
		}
		else
		{
			player.anime = player.timer / 25 % 2;
		}
	}
	




}


void player_hook()
{
	if (player.state == 0 && player.groundFlag == TRUE)
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

		int i, j;
		for (i = 0; i < 24; i++)
		{
			for (j = 0; j < 32; j++)
			{
				if (map[i][j].type == 1
					&& player.hookPos.y + 2 * MAPCHIP_SIZE >= map[i][j].pos.y
					&& player.hookPos.y <= map[i][j].pos.y
					&& player.hookPos.x >= map[i][j].pos.x - 20
					&& player.hookPos.x <= map[i][j].pos.x + 20)
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
			player.state = 1;
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
			sound::play(0);
		}
		//player.pos.x = player.hookPos.x;
		//player.pos.y = player.hookPos.y - PL_HEIGHT;
		
	}
	if (player.state == 1)
	{

		player.pos.x += player.speed.x;
		player.pos.y += player.speed.y;
	}
	if (player.pos.y <= player.hookPos.y - PL_HEIGHT - MAPCHIP_SIZE - 20)
	{
		player.state = 0;
		player.hookFlag = FALSE;
	}


	if (player.state == 1)
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
			//���斢����
			player.anime = 4 + player.timer / 10 % 3;
		}


	}

}

void player_connect()
{
	int i, j;
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
					sound::play(5);
					if (player.cnt == 2)
					{
						player.cnt++;
						if (player.cnt == 3)
						{
							sound::play(2);
						}
					}
					

				}
			}
		}
	}
}


void player_fall()
{
	player.groundFlag = FALSE;

	int i, j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (map[i][j].type == 1
				&& player.pos.x <= map[i][j].pos.x + 20
				&& player.pos.x + 80 >= map[i][j].pos.x + 20
				&& player.pos.y + PL_HEIGHT == map[i][j].pos.y)
			{
				player.groundFlag = TRUE;
			}
		}
	}
	if (player.groundFlag == FALSE )
	{
		if (player.state == 0 )
		{
			player.pos.y += 20;
		}
		
	}
}