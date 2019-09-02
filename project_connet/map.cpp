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

	sprite_render(sprBg,                  // 使用するスプライト
		0,0,             // 位置
		1, 1,         // スケールv
		0, 0,      // 元画像位置
		1280, 960,   // 元画像大きさ
		0, 0,   // 基準点の位置
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
				primitive::circle(j* MAPCHIP_SIZE + 20, i * MAPCHIP_SIZE + 20, 20, 1, 1, 1,0.5);
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
				primitive::circle(j* MAPCHIP_SIZE + 20, i * MAPCHIP_SIZE + 20, 20, 1, 1, 1,0.2);
				break;
			default:
				break;
			}

			if (map[i][j].connectFlag == TRUE)
			{
				if (player.cnt == 1)
				{
					primitive::line(map[i][j].pos.x, map[i][j].pos.y, player.pos.x, player.pos.y, 0, 0, 1);
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
		primitive::line(lineDraw[k - 1].x, lineDraw[k - 1].y, lineDraw[k - 2].x, lineDraw[k - 2].y, 0, 0, 1);
	}

	if (game_state == 2)
	{
		font::textOut(2, "CLEAR", 40, 250, 1.3f, 1.3f, 0, 1, 1);
	}



}