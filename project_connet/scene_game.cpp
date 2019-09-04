//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//------< �C���N���[�h >---------------------------------------------------------
#include "all.h"

//------< �ϐ� >----------------------------------------------------------------
int game_state;     // ���
int game_timer;     // �^�C�}�[
int ending_timer;

Sprite* sprPlayer;
Sprite* sprBg;
Sprite* sprBg2;
Sprite* sprEnemy;
Sprite* sprEnemy2;
Sprite* sprMap;
Sprite* sprMap2;
Sprite* sprItem;
Sprite* sprItem2;
Sprite* sprUi;

// �ʂ̃t�@�C���̕ϐ����g�p����錾
extern int nextScene;
extern OBJ2D player;
extern OBJ2D enemyGuard[3];
extern OBJ2D map[24][32];



//--------------------------------
// �����ݒ�
//--------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;

	player.hp = 5;
	player.guideState = 0;
	//music::play(0, TRUE);

	ending_timer = 0;
}

//--------------------------------
// �Q�[����
//--------------------------------
void game_common()
{
    if (TRG(0) & PAD_START)
    {
        nextScene = SCENE_TITLE;
    }

	//map_update(stage1);
	//
	//enemy_update();
	//
	//player_update();

	//check();
}

//--------------------------------
// �X�V����
//--------------------------------
void game_update()
{
	if (player.hp == 0)
	{
		game_state = 99;

	}

	if (TRG(0) & PAD_START)
	{
		nextScene = SCENE_TITLE;
	}

	

    switch (game_state)
    {
	case 99:

		

		
		if (TRG(0) & PAD_START)
		{
			nextScene = SCENE_TITLE;
		}


		break;


	case 100:

		int j;

		ending_timer++;

		sprite_load(&sprBg2, L"./Data/Images/ending.png");
		
		if (TRG(0) & PAD_START)
		{
			nextScene = SCENE_TITLE;
		}

		break;




	case 101:


		sprite_load(&sprUi, L"./Data/Images/ui.png");

		sprite_load(&sprBg, L"./Data/Images/bg2.png");
		ending_timer++;

		stage_3_update();

		//if (ending_timer >= 500)
		//{
		//	//music::stop(0);
		//	if (ending_timer == 510)
		//	{
		//		//music::play(1);
		//	}
		//}

		if (TRG(0) & PAD_START && ending_timer >= 800)
		{
			nextScene = SCENE_TITLE;
		}


		break;


	case stage0set:

		sprite_load(&sprPlayer, L"./Data/Images/player.png");       // �v���C���[�X�v���C�g
		sprite_load(&sprBg, L"./Data/Images/bg.png");
		sprite_load(&sprBg2, L"./Data/Images/game_over.png");
		sprite_load(&sprEnemy, L"./Data/Images/enemy.png");
		sprite_load(&sprEnemy2, L"./Data/Images/enemy_2.png");
		sprite_load(&sprMap, L"./Data/Images/map.png");
		sprite_load(&sprMap2, L"./Data/Images/map2.png");
		sprite_load(&sprItem, L"./Data/Images/item.png");
		sprite_load(&sprItem2, L"./Data/Images/item2.png");
		
		stage_0_init();

		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;
		break;
	

	case stage0play:
	
		stage_0_update();

		if (TRG(0) & PAD_SELECT)
		{
			game_state = stage0end;
		}
		break;

	case stage0end:


		if (TRG(0) & PAD_SELECT)
		{
			game_state ++;
		}


		game_state = stage_end(game_state);
		break;

    case stage1set:
        //////// �����ݒ� ////////

		//map_init();
		//
		//enemy_init();
		//
		//player_init();
		
		stage_1_init();

        game_state++;
        break;

    case stage1play:
        //////// �ʏ펞 ////////
        //game_common();

		stage_1_update();
		
		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_SELECT)
		{
			game_state = stage2set;
		}

        break;

	case stage1end:
		
		game_state = stage_end(game_state);
		break;

	case stage2set:

		stage_2_init();


		game_state++;
	
		break;
	case stage2play:

		stage_2_update();

		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_SELECT)
		{
			game_state = stage3set;
		}
		break;

	case stage2end:

		game_state = stage_end(game_state);
		break;

	case stage3set:

		stage_3_init();
		sprite_load(&sprBg, L"./Data/Images/bg2.png");

		game_state++;

		break;

	case stage3play:

		stage_3_update();

		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_SELECT)
		{
			game_state = stage4set;
		}
		break;

	case stage3end:

		game_state = stage_end(game_state);
		break;

	case stage4set:

		stage_4_init();
		sprite_load(&sprBg, L"./Data/Images/bg.png");

		game_state++;

		break;

	case stage4play:

		stage_4_update();

		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_SELECT)
		{
			game_state = stage5set;
		}
		break;

	case stage4end:

		game_state = stage_end(game_state);
		break;

	case stage5set:

		stage_5_init();


		game_state++;

		break;

	case stage5play:

		stage_5_update();

		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_SELECT)
		{
			game_state = stage6set;
		}
		break;

	case stage5end:

		game_state = stage_end(game_state);
		break;

	case stage6set:

		stage_6_init();

		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;

		break;

	case stage6play:

		stage_6_update();

		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_SELECT)
		{
			game_state = stage6end;
		}
		break;

	case stage6end:
		if (player.atk == 0)
		{
			game_state = 100;
		}
		else
		{
			game_state = 101;
		}
		break;

    }
    game_timer++;


	//debug::setString("game_timer:%d", game_timer);
	//debug::setString("game_state:%d", game_state);
}

//--------------------------------
// �`�揈��
//--------------------------------
void game_draw()
{
	GameLib::clear(0, 0, 0);

    // ��ʂ𔒂œh��Ԃ�
	
	map_draw();

	enemy_draw();
	
	if (game_state == stage0play) stage_0_draw();
	
	player_draw();
	
	if (game_state  % 3 == 2) stage_end_draw();

	if (game_state == 99) game_over_draw();

	if (game_state == 100) game_good_end_draw(ending_timer);

	if (game_state == 101) game_bad_end_draw(ending_timer);

}

//--------------------------------
// �I������
//--------------------------------
void game_end()
{
    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }

    // �X�v���C�g�̔j�� 
    SAFE_DELETE(sprPlayer); // �v���C���[�X�v���C�g�̔j��
	SAFE_DELETE(sprBg);
	SAFE_DELETE(sprBg2);
	SAFE_DELETE(sprEnemy2);
	SAFE_DELETE(sprEnemy);
	SAFE_DELETE(sprMap);
	SAFE_DELETE(sprMap2);
	SAFE_DELETE(sprItem);
	SAFE_DELETE(sprItem2);
	SAFE_DELETE(sprUi);

}		
