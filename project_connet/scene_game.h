#ifndef INCLUDED_SCENE_GAME
#define INCLUDED_SCENE_GAME

//******************************************************************************
//
//
//      scene_game.h
//
//
//******************************************************************************

//------< 定数 >----------------------------------------------------------------
extern Sprite* sprPlayer;
extern Sprite* sprBg;
extern Sprite* sprEnemy;
extern Sprite* sprEfc;
extern Sprite* sprNumber;
extern Sprite* sprEnemy2;
extern Sprite* sprMap;
//------< プロトタイプ宣言 >-----------------------------------------------------
void game_init();
void game_update();
void game_draw();
void game_end();
void game_guide();

#endif // !INCLUDED_SCENE_GAME
