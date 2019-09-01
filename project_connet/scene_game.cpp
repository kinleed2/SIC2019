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

Sprite* sprPlayer;
Sprite* sprHook;
Sprite* sprBg;



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

	//map_update(stage1);
	//
	//enemy_update();
	//
	//player_update();

	//check();
}

//--------------------------------
// 更新処理
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
        //////// 初期設定 ////////

        // スプライトのロード
        sprite_load(&sprPlayer, L"./Data/Images/player.png");       // プレイヤースプライト
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
        //////// 通常時 ////////
        //game_common();

		stage_1_update();
		
		//"D"を押すと次のステージへ
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

		//"D"を押すと次のステージへ
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

		//"D"を押すと次のステージへ
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
    SAFE_DELETE(sprPlayer); // プレイヤースプライトの破棄
	SAFE_DELETE(sprHook);
	SAFE_DELETE(sprBg);


	
}		
