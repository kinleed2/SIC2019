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
	right, left
};

#endif// ! INCLUDED_COMMON
