#include "all.h"

OBJ2D enemyGuard[3];
OBJ2D enemyUav[3];
OBJ2D enemyCamera[3];
extern int game_timer;

void enemy_init()
{

	int i;
	for (i = 0; i < 3; i++)
	{
		if (enemyGuard[i].exist == TRUE)
		{
			enemyGuard[i].exist = FALSE;
		}

		if (enemyUav[i].exist == TRUE)
		{
			enemyUav[i].exist = FALSE;
		}

		if (enemyCamera[i].exist == TRUE)
		{
			enemyCamera[i].exist = FALSE;
		}

	}
}

void enemy_update()
{
	//enemy_guard_move(300,700,1);
}


void enemy_draw()
{

	VECTOR2 enemyAtk[4];
	int i;
	for ( i = 0; i < 3; i++)
	{
		if (enemyGuard[i].exist == TRUE)
		{

			if (enemyGuard[i].direction == right)
			{
				enemyAtk[0] = { enemyGuard[i].pos.x + 80, enemyGuard[i].pos.y + 77};
				enemyAtk[1] = { enemyGuard[i].pos.x + 80, enemyGuard[i].pos.y + 77 };
				enemyAtk[2] = { enemyGuard[i].pos.x + 80 + 120, enemyGuard[i].pos.y };
				enemyAtk[3] = { enemyGuard[i].pos.x + 80 + 120, enemyGuard[i].pos.y + 120 };

				

				//primitive::rect(enemyGuard[i].pos.x + 95, enemyGuard[i].pos.y, 100, 120, 0, 0, 0, 1, 1, 0, 0.7);
				primitive::quad(enemyAtk, 1, 1, 0, 0.7);
			}
			else
			{
				enemyAtk[0] = { enemyGuard[i].pos.x , enemyGuard[i].pos.y + 77 };
				enemyAtk[1] = { enemyGuard[i].pos.x , enemyGuard[i].pos.y + 77 };
				enemyAtk[2] = { enemyGuard[i].pos.x - 120, enemyGuard[i].pos.y };
				enemyAtk[3] = { enemyGuard[i].pos.x - 120, enemyGuard[i].pos.y + 120 };

				
				//primitive::rect(enemyGuard[i].pos.x - 95, enemyGuard[i].pos.y, 100, 120, 0, 0, 0, 1, 1, 0, 0.7);
				primitive::quad(enemyAtk, 1, 1, 0, 0.7);
			}


			//primitive::rect(enemyGuard[i].pos.x, enemyGuard[i].pos.y, 80, 120, 0, 0, 0, 1, 1,1);
			
			sprite_render(enemyGuard[i].data,                  // 使用するスプライト
				enemyGuard[i].pos.x, enemyGuard[i].pos.y,             // 位置
				enemyGuard[i].scale.x, enemyGuard[i].scale.y,         // スケールv
				enemyGuard[i].texPos.x + enemyGuard[i].anime * enemyGuard[i].texSize.x, 
				enemyGuard[i].texPos.y + enemyGuard[i].direction * enemyGuard[i].texSize.y,       // 元画像位置
				enemyGuard[i].texSize.x, enemyGuard[i].texSize.y,     // 元画像大きさ
				enemyGuard[i].texPivot.x, enemyGuard[i].texPivot.y,   // 基準点の位置
				enemyGuard[i].rotate,
				1, 1, 1, 1
				);

		
		}

		if (enemyUav[i].exist == TRUE)
		{
			//primitive::rect(enemyUav[i].pos.x, enemyUav[i].pos.y, 40, 40, 0, 0, 0, 0.5, 0.5, 1);

			enemyAtk[0] = { enemyUav[i].pos.x + 30, enemyUav[i].pos.y + 50 };
			enemyAtk[1] = { enemyUav[i].pos.x + 30, enemyUav[i].pos.y + 50 };
			enemyAtk[2] = { enemyUav[i].pos.x + 110, enemyUav[i].pos.y + 200 };
			enemyAtk[3] = { enemyUav[i].pos.x - 50, enemyUav[i].pos.y + 200 };

			primitive::quad(enemyAtk, 1, 1, 0, 0.7);
			//primitive::rect(enemyUav[i].pos.x - 60, enemyUav[i].pos.y + 40, 160, 160, 0, 0, 0, 1, 1, 0, 0.7);

			
			sprite_render(enemyUav[i].data,                  // 使用するスプライト
				enemyUav[i].pos.x, enemyUav[i].pos.y,             // 位置
				enemyUav[i].scale.x, enemyUav[i].scale.y,         // スケールv
				enemyUav[i].texPos.x + enemyUav[i].anime * enemyUav[i].texSize.x, enemyUav[i].texPos.y,       // 元画像位置
				enemyUav[i].texSize.x, enemyUav[i].texSize.y,     // 元画像大きさ
				enemyUav[i].texPivot.x, enemyUav[i].texPivot.y,   // 基準点の位置
				0.0f,
				1, 1, 1, 1
				);



		}
		if (enemyCamera[i].exist == TRUE)
		{

			enemyAtk[0] = { enemyCamera[i].rpos.x, enemyCamera[i].rpos.y };
			enemyAtk[1] = { enemyCamera[i].rpos.x, enemyCamera[i].rpos.y };
			enemyAtk[2] = { enemyCamera[i].pos.x + 190, enemyCamera[i].pos.y + 160 };
			enemyAtk[3]	= { enemyCamera[i].pos.x - 30, enemyCamera[i].pos.y + 160 };



			if (enemyCamera[i].direction == right)
			{

				primitive::quad(enemyAtk, 1, 1, 0, 0.7);
			}
			else
			{
				primitive::quad(enemyAtk, 1, 1, 0, 0.7);
			}

			sprite_render(enemyCamera[i].data,                  // 使用するスプライト
				enemyCamera[i].rpos.x, enemyCamera[i].rpos.y,             // 位置
				enemyCamera[i].scale.x, enemyCamera[i].scale.y,         // スケールv
				enemyCamera[i].texPos.x + enemyCamera[i].anime * enemyCamera[i].texSize.x, enemyCamera[i].texPos.y,       // 元画像位置
				enemyCamera[i].texSize.x, enemyCamera[i].texSize.y,     // 元画像大きさ
				enemyCamera[i].texPivot.x, enemyCamera[i].texPivot.y,   // 基準点の位置
				enemyCamera[i].rotate,
				1, 1, 1, 1
				);



		}

	}
	
}


void enemy_guard_init(OBJ2D *obj, float x, float y, int direction)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->direction = direction;
	obj->exist = TRUE;
	obj->data = sprEnemy;
	obj->texPos = VECTOR2(0, 0);
	obj->texPivot = VECTOR2(0, 0);
	obj->texSize = VECTOR2(80, 120);
	obj->scale = VECTOR2(1, 1);
}


void enemy_uav_init(OBJ2D *obj, float x, float y, int direction)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->direction = direction;
	obj->exist = TRUE;
	obj->data = sprEnemy2;
	obj->texPos = VECTOR2(0, 40);
	obj->texPivot = VECTOR2(0, 0);
	obj->texSize = VECTOR2(60, 60);
	obj->scale = VECTOR2(1, 1);
}

void enemy_camera_init(OBJ2D *obj, float x, float y, int direction, float fixShowX, float fixShowY,int rotate)
{
	obj->pos.x = x;
	obj->pos.y = y;
	obj->direction = direction;
	obj->exist = TRUE;
	obj->data = sprEnemy2;
	obj->texPos = VECTOR2(0, 0);
	obj->texPivot = VECTOR2(20, 20);
	obj->texSize = VECTOR2(40, 40);
	obj->scale = VECTOR2(1, 1);
	obj->rpos.x = x + fixShowX;
	obj->rpos.y = y + fixShowY;
	obj->rotate = ToRadian(rotate);
}



void enemy_guard_move(OBJ2D *obj,int leftLimit, int rightLimit,int speed)
{

	switch (obj->direction)
	{
	case left:
		obj->pos.x -= speed;
		if (obj->pos.x <= leftLimit)
		{
			obj->direction = right;
			
		}
		break;
	case right:
		obj->pos.x += speed;
		if (obj->pos.x >= rightLimit)
		{
			obj->direction = left;
			
		}
		break;
	default:
		break;
	}

	obj->anime = 2 + game_timer / 20 % 4;



}


void enemy_uav_move(OBJ2D *obj, int mode,int leftLimit, int rightLimit, int speed,int upLimit, int downLimit)
{
	switch (mode)
	{
	case 1:
		switch (obj->direction)
		{
		case left:
			obj->pos.x -= speed;
			if (obj->pos.x <= leftLimit)
			{
				obj->direction = right;
			}
			break;
		case right:
			obj->pos.x += speed;
			if (obj->pos.x >= rightLimit)
			{
				obj->direction = left;
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (obj->direction)
		{
		case left:
			obj->pos.x -= speed;
			obj->pos.y -= speed;
			if (obj->pos.x <= leftLimit || obj->pos.y <= upLimit)
			{
				obj->direction = right;
			}
			break;
		case right:
			obj->pos.x += speed;
			obj->pos.y += speed;
			if (obj->pos.x >= rightLimit || obj->pos.x >= downLimit)
			{
				obj->direction = left;
			}
			break;
		}
	case 3:
			switch (obj->direction)
			{
			case up:
				obj->pos.y -= speed;
				if (obj->pos.y <= upLimit)
				{
					obj->direction = down;
				}
				break;
			case down:
				obj->pos.y += speed;
				if (obj->pos.y >= downLimit)
				{
					obj->direction = up;
				}
				break;
		default:
			break;
		}
	default:
		break;
	}
	
	obj->anime = game_timer / 20 % 2;

}

void enemy_camera_move(OBJ2D *obj, int mode, int leftLimit, int rightLimit, int speed, int upLimit, int downLimit)
{
	switch (mode)
	{
	case 1:
		switch (obj->direction)
		{
		case left:
			obj->pos.x -= speed;
			if (obj->pos.x <= leftLimit)
			{
				obj->direction = right;
			}
			break;
		case right:
			obj->pos.x += speed;
			if (obj->pos.x >= rightLimit)
			{
				obj->direction = left;
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (obj->direction)
		{
		case up:
			obj->pos.y -= speed;
			if (obj->pos.y <= upLimit)
			{
				obj->direction = down;
			}
			break;
		case down:
			obj->pos.y += speed;
			if (obj->pos.y >= downLimit)
			{
				obj->direction = up;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	
	obj->anime = game_timer / 20 % 4;

}
