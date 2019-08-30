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

	map_update();

	enemy_update();

	player_update();

	check();
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

		map_init();

		enemy_init();

		player_init();

        GameLib::setBlendMode(Blender::BS_ALPHA);

        game_state++;
        break;

    case 1:
        //////// 通常時 ////////
        game_common();

        break;


	case 2:

		

		break;
    }
    game_timer++;


	debug::setString("game_timer:%d", game_timer);
}

//--------------------------------
// 描画処理
//--------------------------------
void game_draw()
{
    // 画面を白で塗りつぶす
    GameLib::clear(0, 0, 0);

	map_draw();

	enemy_draw();

	player_draw();

	
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
