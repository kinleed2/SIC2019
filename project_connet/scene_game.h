#ifndef INCLUDED_SCENE_GAME
#define INCLUDED_SCENE_GAME

//******************************************************************************
//
//
//      scene_game.h
//
//
//******************************************************************************

//------< �萔 >----------------------------------------------------------------
extern Sprite* sprPlayer;
extern Sprite* sprBg;
extern Sprite* sprEnemy;
extern Sprite* sprEfc;
extern Sprite* sprNumber;
extern Sprite* sprHook;
extern Sprite* sprEnemy2;
//------< �v���g�^�C�v�錾 >-----------------------------------------------------
void game_init();
void game_update();
void game_draw();
void game_end();

#endif // !INCLUDED_SCENE_GAME
