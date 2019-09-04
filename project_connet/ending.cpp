#include "all.h"

int x = 0;

extern int nextScene;

void game_over_draw()
{

	sprite_render(sprBg2,                  // 使用するスプライト
		0, 0,             // 位置
		1, 1,         // スケールv
		0, 0,      // 元画像位置
		1280, 960,   // 元画像大きさ
		0, 0,   // 基準点の位置
		0.0f,
		1, 1, 1, 0.9
		);
	
	font::textOut(4, "Press Start(controller)/Enter(keyboard) to return Title ", 20, 600, 1.0f, 1.0f, 1, 1, 1);
}

void game_good_end_draw(int ending_timer)
{
	GameLib::clear(0, 0, 0);

	if (x <= 3)
	{


		sprite_render(sprBg2,                  // 使用するスプライト
			0, 0,             // 位置
			1, 1,         // スケールv
			0 + 1280 * x, 0,      // 元画像位置
			1280, 960,   // 元画像大きさ
			0, 0,   // 基準点の位置
			0.0f,
			1, 1, 1, 1
			);
	}





	switch (x)
	{
	case 0:
		if (ending_timer >= 150)
		{
			x++;
		}

		break;
	case 1:
		if (ending_timer >= 300)
		{
			x++;
		}

		break;
	case 2:
		if (ending_timer >= 450)
		{
			x++;
		}
		break;
	case 3:
			if (ending_timer >= 650)
			{
				x++;
			}
		break;
	case 4:
		


		font::textOut(4, "Created by", 400, 400, 1.0f, 1.0f, 1, 1, 1);
		font::textOut(4, "KIN LEE", 400, 450, 1.0f, 1.0f, 1, 1, 1);
		font::textOut(4, "SHINYA MORIKUCHI", 400, 500, 1.0f, 1.0f, 1, 1, 1);
		font::textOut(4, "XIANGTAI MONG", 400, 550, 1.0f, 1.0f, 1, 1, 1);
		if (ending_timer >= 1550)
		{
			x++;
		}
		break;
	case 5:
		x = 0;
		nextScene = SCENE_TITLE;

		break;
	default:
		break;
	}
	


	


	
	
}

void game_bad_end_draw(int ending_timer)
{
	

	GameLib::clear(0, 0, 0);

	int uiAnime = ending_timer / 50 % 2;

	
	sprite_render(sprUi,                  // 使用するスプライト
		520, 280,             // 位置
		1, 1,         // スケールv
		0 + 240 * uiAnime, 0,      // 元画像位置
		240, 320,   // 元画像大きさ
		0, 0,   // 基準点の位置
		0.0f,
		1, 1, 1, 1
		);

	if (ending_timer>= 500)
	{
		music::stop(0);
		if (ending_timer == 510)
		{
			music::play(1);
		}

		sprite_render(sprBg,                  // 使用するスプライト
			0, 0,             // 位置
			1, 1,         // スケールv
			0, 0,      // 元画像位置
			1280, 960,   // 元画像大きさ
			0, 0,   // 基準点の位置
			0.0f,
			1, 1, 1, 1
			);

		map_draw();

		if (ending_timer >= 800)
		{
			
			sprite_render(sprBg2,                  // 使用するスプライト
				0, 0,             // 位置
				1, 1,         // スケールv
				0, 0,      // 元画像位置
				1280, 960,   // 元画像大きさ
				0, 0,   // 基準点の位置
				0.0f,
				1, 1, 1, 0.9
				);

			font::textOut(4, "Press Start(controller)/Enter(keyboard) to return Title ", 20, 600, 1.0f, 1.0f, 1, 1, 1);
		}
	}
	else if (ending_timer >= 300)
	{
		font::textOut(4, "Where is your Treasure?", 400, 650, 1.0f, 1.0f, 1, 1, 1);
	}
	else if (ending_timer >= 200)
	{
		font::textOut(4, "Wait!", 600, 650, 1.0f, 1.0f, 1, 1, 1);
	}
	else if (ending_timer >= 50)
	{
		font::textOut(4, "Did you finish your job?", 400, 650, 1.0f, 1.0f, 1, 1, 1);
	}
	

	debug::setString("ending:%d", ending_timer);

}


