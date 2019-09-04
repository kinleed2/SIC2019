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


	if (game_state % 3 != 2)
	{
		sprite_render(sprBg,                  // �g�p����X�v���C�g
			0, 0,             // �ʒu
			1, 1,         // �X�P�[��v
			0, 0,      // ���摜�ʒu
			1280, 960,   // ���摜�傫��
			0, 0,   // ��_�̈ʒu
			0.0f,
			1, 1, 1, 1
			);
	}
	

	
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
				if (map[i][j].connectFlag == FALSE)
				{
					sprite_render(map[i][j].data,                  // �g�p����X�v���C�g
						map[i][j].pos.x - 40, map[i][j].pos.y - 30,             // �ʒu
						map[i][j].scale.x, map[i][j].scale.y,         // �X�P�[��v
						0,40,    // ���摜�ʒu
						110,110,    // ���摜�傫��
						map[i][j].texPivot.x, map[i][j].texPivot.y,   // ��_�̈ʒu
						0.0f,
						1, 1, 1, 1
						);
				}
				else
				{
					sprite_render(map[i][j].data,                  // �g�p����X�v���C�g
						map[i][j].pos.x - 40, map[i][j].pos.y -30,             // �ʒu
						map[i][j].scale.x, map[i][j].scale.y,         // �X�P�[��v
						110, 40,    // ���摜�ʒu
						110, 110,    // ���摜�傫��
						map[i][j].texPivot.x, map[i][j].texPivot.y,   // ��_�̈ʒu
						0.0f,
						1, 1, 1, 1
						);


				}
				break;
			case 3:
				if (player.score == 1)
				{
					sprite_render(sprMap2,                  // �g�p����X�v���C�g
						map[i][j].pos.x - 60, map[i][j].pos.y -20 ,          // �ʒu
						map[i][j].scale.x, map[i][j].scale.y,         // �X�P�[��v
						140, 0,    // ���摜�ʒu
						140, 140,    // ���摜�傫��
						map[i][j].texPivot.x, map[i][j].texPivot.y,   // ��_�̈ʒu
						0.0f,
						1, 1, 1, 1
						);
				}
				else
				{
					sprite_render(sprMap2,                  // �g�p����X�v���C�g
						map[i][j].pos.x - 60, map[i][j].pos.y -20,             // �ʒu
						map[i][j].scale.x, map[i][j].scale.y,         // �X�P�[��v
						0, 0,    // ���摜�ʒu
						140, 140,    // ���摜�傫��
						map[i][j].texPivot.x, map[i][j].texPivot.y,   // ��_�̈ʒu
						0.0f,
						1, 1, 1, 1
						);
				}
				break;
			case 4: 
				switch (map[i][j].state)
				{
				case 1:

					sprite_render(sprMap2,                  // �g�p����X�v���C�g
						map[i][j].pos.x, map[i][j].pos.y -20,             // �ʒu
						map[i][j].scale.x, map[i][j].scale.y,         // �X�P�[��v
						0, 140,    // ���摜�ʒu
						100, 40,    // ���摜�傫��
						map[i][j].texPivot.x, map[i][j].texPivot.y,   // ��_�̈ʒu
						0.0f,
						1, 1, 1, 1
						);

					
					break;
				case 2:

					sprite_render(sprMap2,                  // �g�p����X�v���C�g
						map[i][j].pos.x, map[i][j].pos.y - 20,             // �ʒu
						map[i][j].scale.x, map[i][j].scale.y,         // �X�P�[��v
						100, 140,    // ���摜�ʒu
						100, 40,    // ���摜�傫��
						map[i][j].texPivot.x, map[i][j].texPivot.y,   // ��_�̈ʒu
						0.0f,
						1, 1, 1, 1
						);
					break;
				case 3:

					sprite_render(sprMap2,                  // �g�p����X�v���C�g
						map[i][j].pos.x, map[i][j].pos.y - 20,             // �ʒu
						map[i][j].scale.x, map[i][j].scale.y,         // �X�P�[��v
						200, 140,    // ���摜�ʒu
						100, 40,    // ���摜�傫��
						map[i][j].texPivot.x, map[i][j].texPivot.y,   // ��_�̈ʒu
						0.0f,
						1, 1, 1, 1
						);

					break;
				default:
					break;
				}
				break;
			default:
				break;
			}

			if (map[i][j].connectFlag == TRUE && game_state % 3 != 2)
			{
				if (player.cnt == 1)
				{
					primitive::line(map[i][j].pos.x - 23 , map[i][j].pos.y + 52, player.pos.x + 35, player.pos.y + 70, 1, 0, 0, 1,3);
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
		primitive::line(lineDraw[k - 1].x - 23, lineDraw[k - 1].y + 52, lineDraw[k - 2].x - 23, lineDraw[k - 2].y + 52, 0, 1, 0,1,3);
	}

	//�N���A������
//if (game_state == 2)
//{
//	font::textOut(2, "CLEAR", 40, 250, 1.3f, 1.3f, 0, 1, 1);
//}

	//�A���O�̉�ʏ���
	//if (player.score !=1)
	//{
	//	primitive::rect(0, 0, 1280, 960, 0, 0, 0, 0, 0, 0, 0.2);
	//}
	
	//primitive::rect(0, 0, 1280, 960, 0, 0, 0, 1, 1, 1, 0.3);

}