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

	map_update();

	enemy_update();

	player_update();

	check();
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

		map_init();

		enemy_init();

		player_init();

        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        break;

    case 1:
        //////// �ʏ펞 ////////
        game_common();

        break;


	case 2:

		

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
    //SAFE_DELETE(sprPlayer); // �v���C���[�X�v���C�g�̔j��
}
