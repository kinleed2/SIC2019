#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

//******************************************************************************
//
//
//      player.h
//
//
//******************************************************************************

//------< �萔 >----------------------------------------------------------------
#define PL_WIDTH  (80)
#define PL_HEIGHT (120)
//------< �v���g�^�C�v�錾 >-----------------------------------------------------
void player_init();
void player_update();
void player_draw();
void player_move();
void player_fall();
void player_hook();
void player_connect();

#endif // !INCLUDED_PLAYER