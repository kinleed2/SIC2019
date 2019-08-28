//******************************************************************************
//
//
//      scene_game
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< 変数 >----------------------------------------------------------------
int game_state;     // 状態
int game_timer;     // タイマー

// 別のファイルの変数を使用する宣言
extern int nextScene;
extern void bg_init();
extern void bg_update();
extern void bg_draw();

//--------------------------------
// 初期設定
//--------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;
}

//--------------------------------
// ゲーム中
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
// 更新処理
//--------------------------------
void game_update()
{
    switch (game_state)
    {
    case 0:
        //////// 初期設定 ////////

        // スプライトのロード
        //sprite_load(&sprPlayer, L"./Data/Images/player.png");       // プレイヤースプライト



		bg_init();

		player_init();

        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        break;

    case 1:
        //////// 通常時 ////////
        game_common();



        break;

	case 2:

		

		game_end();

		break;
    }
    game_timer++;
}

//--------------------------------
// 描画処理
//--------------------------------
void game_draw()
{
    // 画面を白で塗りつぶす
    GameLib::clear(1, 1, 1);
	
	bg_draw();

	player_draw();


	if (game_state == 2)
	{
		font::textOut(2, "CLEAR", 50, 100, 2, 2, 1, 1, 0);
	}
}

//--------------------------------
// 終了処理
//--------------------------------
void game_end()
{

    int i;
    for (i = 0; i < MUSIC_FILE_MAX; i++)
    {
        music::stop(i);
    }

    // スプライトの破棄 
    //SAFE_DELETE(sprPlayer); // プレイヤースプライトの破棄
}
