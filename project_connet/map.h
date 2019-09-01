#ifndef INCLUDED_MAP
#define INCLUDED_MAP

//******************************************************************************
//
//
//      map.h
//
//
//******************************************************************************

//------< 定数 >----------------------------------------------------------------
#define MAPCHIP_SIZE (40)

//------< プロトタイプ宣言 >-----------------------------------------------------
void map_init();
void map_update(int stage[24][32]);
void map_draw();

#endif // !INCLUDED_MAP