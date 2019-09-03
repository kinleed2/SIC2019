#ifndef INCLUDED_CHECK
#define INCLUDED_CHECK

//******************************************************************************
//
//
//      check.h
//
//
//******************************************************************************

//------< 定数 >----------------------------------------------------------------


//------< プロトタイプ宣言 >-----------------------------------------------------
int  check_conncet();
void check(int returnStage,int nextStage);
void check_enemy_guard();
void check_enemy_uav();
void check_enemy_camera();

#endif // !INCLUDED_CHECK