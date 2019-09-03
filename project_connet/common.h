#ifndef INCLUDED_COMMON
#define INCLUDED_COMMON

//******************************************************************************
//
//
//      common.h
//
//
//******************************************************************************

//------< typedef >-------------------------------------------------------------

//------< マクロ関数 >-----------------------------------------------------------
#define SAFE_DELETE(x)  if(x){delete x;x=NULL;}      // メモリを解放する
#define ToRadian(x)     DirectX::XMConvertToRadians(x)  // 角度をラジアンに

//------< 定数 >----------------------------------------------------------------
#define VEC4_WHITE      (VECTOR4(1, 1, 1, 1))   // 白
#define SCREEN_HEIGHT (960)
#define SCREEN_WIDTH  (1280)

// シーン管理用定数
#define SCENE_TITLE     (0)
#define SCENE_GAME      (1)

//
enum DIRECTION
{
	right, left ,up ,down
};

enum STAGE
{
	stage0set, stage0play, stage0end,
	stage1set, stage1play, stage1end,
	stage2set, stage2play, stage2end, 
	stage3set, stage3play, stage3end, 
	stage4set, stage4play, stage4end, 
	stage5set, stage5play, stage5end
};

#endif// ! INCLUDED_COMMON
