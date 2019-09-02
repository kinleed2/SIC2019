#include "all.h"

OBJ2D map[24][32];
extern OBJ2D player;
extern int game_state;

struct LINEDRAW
{
	float x;
	float y;
	int type;
}lineDraw[16];

void map_init()
{
	int i, j;
	for ( i = 0; i < 24; i++)
	{
		for ( j = 0; j < 32; j++)
		{
			map[i][j].type = 0;
			map[i][j].state = 0;
			map[i][j].pos = VECTOR2(j * MAPCHIP_SIZE ,i * MAPCHIP_SIZE);
			map[i][j].connectFlag = FALSE;

			map[i][j].data = sprMap;
			map[i][j].scale		=VECTOR2(1,1);
			map[i][j].texPos	=VECTOR2(0,0);
			map[i][j].texSize	=VECTOR2(40,40);
			map[i][j].texPivot	=VECTOR2(0,0);
		}
	}

}




void map_update(int stage[24][32])
{
	

	int i, j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			map[i][j].type = stage[i][j];

		}
	}

}

void map_draw()
{



	sprite_render(sprBg,                  // �g�p����X�v���C�g
		0,0,             // �ʒu
		1, 1,         // �X�P�[��v
		0, 0,      // ���摜�ʒu
		1280, 960,   // ���摜�傫��
		0, 0,   // ��_�̈ʒu
		0.0f,
		1, 1, 1, 1
		);

	
	int i, j, k = 0;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 32; j++)
		{
			switch (map[i][j].type)
			{
			case 1:
				sprite_render(map[i][j].data,                  // �g�p����X�v���C�g
					map[i][j].pos.x,		map[i][j].pos.y,             // �ʒu
					map[i][j].scale.x,		map[i][j].scale.y,         // �X�P�[��v
					map[i][j].texPos.x,		map[i][j].texPos.y,       // ���摜�ʒu
					map[i][j].texSize.x,	map[i][j].texSize.y,     // ���摜�傫��
					map[i][j].texPivot.x,	map[i][j].texPivot.y,   // ��_�̈ʒu
					0.0f,
					1, 1, 1, 1
					);
				break;
			case 2:
				primitive::circle(j* MAPCHIP_SIZE + 20, i * MAPCHIP_SIZE + 20, 20, 1, 1, 0);
				break;
			case 3:
				if (player.score == 1)
				{
					primitive::circle(j* MAPCHIP_SIZE + 20, i * MAPCHIP_SIZE + 20, 20, 1, 1, 0);
				}
				else
				{
					primitive::circle(j* MAPCHIP_SIZE + 20, i * MAPCHIP_SIZE + 20, 20, 0, 1, 1);
				}
				break;
			case 4: 
				primitive::circle(j* MAPCHIP_SIZE + 20, i * MAPCHIP_SIZE + 20, 20, 1, 1, 1, 0.2);
				break;
			default:
				break;
			}

			if (map[i][j].connectFlag == TRUE)
			{
				if (player.cnt == 1)
				{
					primitive::line(map[i][j].pos.x + 20 , map[i][j].pos.y + 20, player.pos.x + 40, player.pos.y + 40, 0, 1, 0,1,5);
				}
				else
				{
					lineDraw[k].x = map[i][j].pos.x;
					lineDraw[k].y = map[i][j].pos.y;
					lineDraw[k].type = map[i][j].type;
					k++;
				}
				
			}
		}
	}

	if (k >=2 )
	{
		primitive::line(lineDraw[k - 1].x + 20, lineDraw[k - 1].y + 20, lineDraw[k - 2].x + 20, lineDraw[k - 2].y + 20, 0, 1, 0,1,5);
	}

	//�N���A������
	if (game_state == 2)
	{
		font::textOut(2, "CLEAR", 40, 250, 1.3f, 1.3f, 0, 1, 1);
	}


	//HP�̕\��
	int heart = 100;
	for (i = 0; i < player.hp; i++)
	{
		primitive::circle(heart, 20, 20, 1, 0, 0);
		heart += 50;
	}

	//�A���O�̉�ʏ���
	if (player.score !=1)
	{
		primitive::rect(0, 0, 1280, 960, 0, 0, 0, 0, 0, 0, 0.3);
	}
	
	//primitive::rect(0, 0, 1280, 960, 0, 0, 0, 1, 1, 1, 0.3);

}