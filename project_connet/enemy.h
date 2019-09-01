#ifndef INCLUDED_ENEMY
#define INCLUDED_ENEMY

//******************************************************************************
//
//
//      enemy.h
//
//
//******************************************************************************

//------< 定数 >----------------------------------------------------------------

//------< プロトタイプ宣言 >-----------------------------------------------------
void enemy_init();
void enemy_update();
void enemy_draw();
void enemy_guard_init(OBJ2D *obj, int x, int y, int direction);
void enemy_guard_move(OBJ2D *obj,int leftLimit, int rightLimit, int speed);
void enemy_uav_init(OBJ2D *obj, int x, int y, int direction);
void enemy_uav_move(OBJ2D *obj, int mode, int leftLimit, int rightLimit, int speed, int upLimit, int downLimit);
void enemy_camera_init(OBJ2D *obj, int x, int y, int direction);
void enemy_camera_move(OBJ2D *obj, int mode, int leftLimit, int rightLimit, int speed, int upLimit, int downLimit);
#endif // !INCLUDED_ENEMY