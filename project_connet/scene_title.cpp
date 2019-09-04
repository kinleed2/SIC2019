//******************************************************************************
//
//
//      scene_title
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< 変数 >----------------------------------------------------------------
int title_state;    // 状態
int title_timer;    // タイマー
// フェードアウト用変数の宣言
float fadeOut;
float showPresent;
// 別のファイルの変数を使用する宣言
extern int nextScene;

//--------------------------------
// 初期設定
//--------------------------------
void title_init()
{
    title_state = 0;
    title_timer = 0;

    // フェードアウト用変数の初期設定
    fadeOut = 0.0f;
	showPresent = 0.0f;
}

//--------------------------------
// 更新処理
//--------------------------------
void title_update()
{
	
    switch (title_state)
    {

    case 0:
        //////// 初期設定 ////////
		sprite_load(&sprBg, L"./Data/Images/logo.png");



		if (TRG(0) & PAD_START || title_timer == 500)
		{
			title_state++;
		}
		
        break;
	case 1:
		music::play(0,TRUE);
		sprite_load(&sprBg, L"./Data/Images/title_bg3.png");

		title_state++;


		break;
    case 2:
        //////// 通常時 ////////
        // キー入力でシーン切り替え
        if (TRG(0) & PAD_START)
        {
            title_state++;
        }
        break;
		
		

    // フェードアウト用のcase 2:をつくる
    case 3:
        //////// フェードアウト ////////
        fadeOut += 0.0167f;
        if (fadeOut >= 1.0f)
        {
            nextScene = SCENE_GAME;
        }
        break;
    }
    title_timer++;

    // デバッグ用文字列の設定
    //debug::setString("title_state:%d", title_state);
   // debug::setString("title_timer:%d", title_timer);
}

//--------------------------------
// 描画処理
//--------------------------------
void title_draw()
{
	// 画面を黒で塗りつぶす
	GameLib::clear(0, 0, 0);




	if (title_state == 0)
	{

		sprite_render(sprBg,                  // 使用するスプライト
			0, 0,             // 位置
			1, 1,         // スケールv
			0, 0,      // 元画像位置
			1280, 960,   // 元画像大きさ
			0, 0,   // 基準点の位置
			0.0f,
			1, 1, 1, showPresent
			);

	//font::textOut(4, "present", 500, 600, 2.0f, 2.0f, 1, 1, 1, showPresent);
	showPresent += 0.003f;
	
	}

	if (title_state >= 2)
	{
	
		GameLib::clear(0, 0, 0);
		// 文字表示機能
		//font::textOut(2, "ECC COMP", 50, 100, 2, 2, 1, 1, 0);
		//font::textOut(2, "Project Connect", 40, 250, 1.3f, 1.3f, 0, 1, 1);

		sprite_render(sprBg,                  // 使用するスプライト
			0, -100,             // 位置
			1, 1,         // スケールv
			0, 0,      // 元画像位置
			1280, 960,   // 元画像大きさ
			0, 0,   // 基準点の位置
			0.0f,
			1, 1, 1, 1
			);

		// 文字を点滅させる
		if (title_timer / 32 % 2)
			font::textOut(4, "Push Start", 450, 700, 2, 2,1,1,1);

		// タイトル画面のフェードアウト
		if (fadeOut > 0.0f)
		{
			primitive::rect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
				0, 0, 0, 0, 0, 0, fadeOut);
		}
	}

}

//--------------------------------
// 終了処理
//--------------------------------
void title_end()
{
	music::stop(0);
}
