#include "all.h"

int x = 0;

extern int nextScene;

void game_over_draw()
{

	sprite_render(sprBg2,                  // �g�p����X�v���C�g
		0, 0,             // �ʒu
		1, 1,         // �X�P�[��v
		0, 0,      // ���摜�ʒu
		1280, 960,   // ���摜�傫��
		0, 0,   // ��_�̈ʒu
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


		sprite_render(sprBg2,                  // �g�p����X�v���C�g
			0, 0,             // �ʒu
			1, 1,         // �X�P�[��v
			0 + 1280 * x, 0,      // ���摜�ʒu
			1280, 960,   // ���摜�傫��
			0, 0,   // ��_�̈ʒu
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

	
	sprite_render(sprUi,                  // �g�p����X�v���C�g
		520, 280,             // �ʒu
		1, 1,         // �X�P�[��v
		0 + 240 * uiAnime, 0,      // ���摜�ʒu
		240, 320,   // ���摜�傫��
		0, 0,   // ��_�̈ʒu
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

		sprite_render(sprBg,                  // �g�p����X�v���C�g
			0, 0,             // �ʒu
			1, 1,         // �X�P�[��v
			0, 0,      // ���摜�ʒu
			1280, 960,   // ���摜�傫��
			0, 0,   // ��_�̈ʒu
			0.0f,
			1, 1, 1, 1
			);

		map_draw();

		if (ending_timer >= 800)
		{
			
			sprite_render(sprBg2,                  // �g�p����X�v���C�g
				0, 0,             // �ʒu
				1, 1,         // �X�P�[��v
				0, 0,      // ���摜�ʒu
				1280, 960,   // ���摜�傫��
				0, 0,   // ��_�̈ʒu
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


