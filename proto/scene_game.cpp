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

// �ʂ̃t�@�C���̕ϐ����g�p����錾
extern int nextScene;
extern void bg_init();
extern void bg_update();
extern void bg_draw();

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

	bg_update();

	player_update();

	judge_update();

	debug::setString("game:%d", game_state);
}

//--------------------------------
// �X�V����
//--------------------------------
void game_update()
{
    switch (game_state)
    {
    case 0:
        //////// �����ݒ� ////////

        // �X�v���C�g�̃��[�h
        //sprite_load(&sprPlayer, L"./Data/Images/player.png");       // �v���C���[�X�v���C�g



		bg_init();

		player_init();

        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        break;

    case 1:
        //////// �ʏ펞 ////////
        game_common();



        break;

	case 2:

		

		game_end();

		break;
    }
    game_timer++;
}

//--------------------------------
// �`�揈��
//--------------------------------
void game_draw()
{
    // ��ʂ𔒂œh��Ԃ�
    GameLib::clear(1, 1, 1);
	
	bg_draw();

	player_draw();


	if (game_state == 2)
	{
		font::textOut(2, "CLEAR", 50, 100, 2, 2, 1, 1, 0);
	}
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
    //SAFE_DELETE(sprPlayer); // �v���C���[�X�v���C�g�̔j��
}
