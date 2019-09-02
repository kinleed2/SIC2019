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

Sprite* sprPlayer;
Sprite* sprHook;
Sprite* sprBg;



// �ʂ̃t�@�C���̕ϐ����g�p����錾
extern int nextScene;





//--------------------------------
// �����ݒ�
//--------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
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
	if (TRG(0) & PAD_START)
	{
		nextScene = SCENE_TITLE;
	}


    switch (game_state)
    {
    case stage1set:
        //////// �����ݒ� ////////

        // �X�v���C�g�̃��[�h
        sprite_load(&sprPlayer, L"./Data/Images/player.png");       // �v���C���[�X�v���C�g
		sprite_load(&sprHook, L"./Data/Images/hook.png");
		sprite_load(&sprBg, L"./Data/Images/bg.png");
		//map_init();
		//
		//enemy_init();
		//
		//player_init();
		
		stage_1_init();

        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        break;

    case stage1play:
        //////// �ʏ펞 ////////
        //game_common();

		stage_1_update();
		
		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_TRG4)
		{
			game_state = stage2set;
		}

        break;


	case stage1end:
		
		Sleep(1000);
		game_state++;
		break;
	
	case stage2set:

		stage_2_init();

		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;
	
		break;
	case stage2play:

		stage_2_update();

		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_TRG4)
		{
			game_state = stage3set;
		}
		break;

	case stage2end:

		Sleep(1000);
		game_state++;
		break;

	case stage3set:

		stage_3_init();

		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;

		break;

	case stage3play:

		stage_3_update();

		//"D"�������Ǝ��̃X�e�[�W��
		if (TRG(0) & PAD_TRG4)
		{
			game_state = stage3set;
		}
		break;

	case stage3end:

		Sleep(1000);
		game_state++;
		break;


    }
    game_timer++;


	debug::setString("game_timer:%d", game_timer);
}

//--------------------------------
// �`�揈��
//--------------------------------
void game_draw()
{
    // ��ʂ𔒂œh��Ԃ�
    GameLib::clear(0, 0, 0);

	map_draw();

	enemy_draw();

	player_draw();

	
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
	SAFE_DELETE(sprHook);
	SAFE_DELETE(sprBg);


	
}		
