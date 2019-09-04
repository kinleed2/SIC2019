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
Sprite* sprBg;
Sprite* sprEnemy;
Sprite* sprEnemy2;
Sprite* sprMap;
Sprite* sprMap2;
Sprite* sprItem;
Sprite* sprItem2;

// 別のファイルの変数を使用する宣言
extern int nextScene;
extern OBJ2D player;




//--------------------------------
// 初期設定
//--------------------------------
void game_init()
{
    game_state = 0;
    game_timer = 0;

	player.hp = 5;
	player.guideState = 0;
	music::play(0, TRUE);
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
	//if (TRG(0) & PAD_START || player.hp == 0)
	//{
	//	nextScene = SCENE_TITLE;
	//}
	if (TRG(0) & PAD_START)
	{
		nextScene = SCENE_TITLE;
	}

	

    switch (game_state)
    {
	case stage0set:

		sprite_load(&sprPlayer, L"./Data/Images/player.png");       // プレイヤースプライト
		sprite_load(&sprBg, L"./Data/Images/bg.png");
		sprite_load(&sprEnemy, L"./Data/Images/enemy.png");
		sprite_load(&sprEnemy2, L"./Data/Images/enemy_2.png");
		sprite_load(&sprMap, L"./Data/Images/map.png");
		sprite_load(&sprMap2, L"./Data/Images/map2.png");
		//sprite_load(&sprItem, L"./Data/Images/item.png");
		//sprite_load(&sprItem2, L"./Data/Images/item2.png");

		stage_0_init();

		GameLib::setBlendMode(Blender::BS_ALPHA);

		game_state++;
		break;
	

	case stage0play:
	
		stage_0_update();

		if (TRG(0) & PAD_TRG4)
		{
			game_state = stage0end;
		}
		break;

	case stage0end:


		if (TRG(0) & PAD_TRG4)
		{
			game_state ++;
		}


		game_state = stage_end(game_state);
		break;




    case stage1set:
        //////// 初期設定 ////////

		//map_init();
		//
		//enemy_init();
		//
		//player_init();
		
		stage_1_init();

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
		
		game_state = stage_end(game_state);
		break;

	case stage2set:

		stage_2_init();


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

		game_state = stage_end(game_state);
		break;

	case stage3set:

		stage_3_init();


		game_state++;

		break;

	case stage3play:

		stage_3_update();

		//"D"を押すと次のステージへ
		if (TRG(0) & PAD_TRG4)
		{
			game_state = stage4set;
		}
		break;

	case stage3end:

		game_state = stage_end(game_state);
		break;

	case stage4set:

		stage_4_init();


		game_state++;

		break;

	case stage4play:

		stage_4_update();

		//"D"を押すと次のステージへ
		if (TRG(0) & PAD_TRG4)
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

		//"D"を押すと次のステージへ
		if (TRG(0) & PAD_TRG4)
		{
			game_state = stage4set;
		}
		break;

	case stage5end:

		Sleep(1000);
		game_state++;
		break;

    }
    game_timer++;


	debug::setString("game_timer:%d", game_timer);
	debug::setString("game_state:%d", game_state);
}

//--------------------------------
// 描画処理
//--------------------------------
void game_draw()
{
	GameLib::clear(0, 0, 0);

    // 画面を白で塗りつぶす
	
	

	map_draw();

	enemy_draw();
	
	
	if (game_state == stage0play) stage_0_draw();
	
	player_draw();
	

	if (game_state  % 3 == 2) stage_end_draw(game_state);
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
	SAFE_DELETE(sprBg);
	SAFE_DELETE(sprEnemy2);
	SAFE_DELETE(sprEnemy);
	SAFE_DELETE(sprMap);
	SAFE_DELETE(sprMap2);
	SAFE_DELETE(sprItem);
	SAFE_DELETE(sprItem2);
	
}		
