//******************************************************************************
//
//
//      obj2d
//
//
//******************************************************************************

//------< インクルード >---------------------------------------------------------
#include "all.h"

//------< 変数 >----------------------------------------------------------------

//------< 構造体 >---------------------------------------------------------------

//------< プロトタイプ宣言 >-----------------------------------------------------

//--------------------------------
// 空きを探してOBJ2Dを生成する（Version2）
//--------------------------------
OBJ2D* searchSet(OBJ2D arr[], int arrayNum, int type, VECTOR2 pos)
{
    int i;
    for (i = 0; i < arrayNum; i++)
    {
        if (arr[i].exist == TRUE) continue;
        ZeroMemory(&arr[i], sizeof(OBJ2D));
        arr[i].type = type;
        arr[i].pos = pos;
        arr[i].scale = VECTOR2(1, 1);
        arr[i].color = VECTOR4(1, 1, 1, 1);
        arr[i].exist = TRUE;
        return &arr[i]; // 生成したarr[i]のアドレスを返す
    }
    return NULL;        // 生成できなかったのでNULLを返す
}

//--------------------------------
// OBJ2Dのエリア外チェック
//--------------------------------
BOOL areaCheck(OBJ2D* obj, float limit)
{
    if (obj->pos.x < -limit ||
        obj->pos.x > system::SCREEN_WIDTH + limit ||
        obj->pos.y < -limit ||
        obj->pos.y > system::SCREEN_HEIGHT + limit)
    {
        obj->exist = FALSE;
    }

    return obj->exist;
}



