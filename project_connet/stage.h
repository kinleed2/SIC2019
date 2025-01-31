#ifndef INCLUDED_STAGE
#define INCLUDED_STAGE

//******************************************************************************
//
//
//      stage.h
//
//
//******************************************************************************

//------< 定数 >----------------------------------------------------------------

//------< プロトタイプ宣言 >-----------------------------------------------------
void stage_0_init();
void stage_0_update();
void stage_0_draw();



void stage_1_init();
void stage_1_update();
void stage_2_init();
void stage_2_update();
void stage_3_init();
void stage_3_update();
void stage_4_init();
void stage_4_update();
void stage_5_init();
void stage_5_update();
void stage_6_init();
void stage_6_update();

int stage_end(int stage);
void stage_end_draw();

#endif // !INCLUDED_STAGE