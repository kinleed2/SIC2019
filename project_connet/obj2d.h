#ifndef INCLUDED_OBJ2D
#define INCLUDED_OBJ2D

//******************************************************************************
//
//
//      obj2d.h
//
//
//******************************************************************************

//------< 定数 >----------------------------------------------------------------

//------< 構造体 >---------------------------------------------------------------

//==============================================================================
//
//      OBJ2D
//
//==============================================================================
struct OBJ2D
{
    // スプライト関連
    Sprite* data;           // スプライトポインタ
    VECTOR2 texPos;         // 画像位置
    VECTOR2 texSize;        // 画像サイズ
    VECTOR2 texPivot;       // 画像の基準点
    int     anime;          // アニメーション用（仮）

    // OBJ2Dのタイプ・存在フラグ
    int     type;           // タイプ
    BOOL    exist;          // 存在フラグ

    // 汎用的なもの
    VECTOR2 pos;            // 位置
    VECTOR2 scale;          // スケール
    float   angle;          // 角度
    VECTOR4 color;          // 色（xyzwそれぞれrgba）
    float   radius;         // 半径
    int     state;          // 状態遷移用
    int     timer;          // タイマー
    VECTOR2 speed;          // 速度
    int     cnt;            // 汎用カウンタ（使い方は自由）
    BOOL    hostilityFg;    // 敵フラグ（今回から追加）
	int		direction;		// 方向


    // 特殊なもの
    BOOL    groundFlag;     // 地上フラグ（地上のものはTRUE）
    float   rotate;         // 旋回する角度
    OBJ2D*  parent;         // 親オブジェクトを指すポインタ
    VECTOR2 rpos;           // 相対的な位置（relative position)
    int     hp;             // ヒットポイント
    int     atk;            // 攻撃力
    int     damageTimer;    // ダメージタイマー
    int     score;          // この敵を倒したら何点入るか
	VECTOR2 hookPos;		//
	BOOL	hookFlag;		//
	BOOL    connectFlag;    //
	int     guideState;
};

//------< プロトタイプ宣言 >-----------------------------------------------------
OBJ2D* searchSet(OBJ2D[], int, int, VECTOR2);
BOOL areaCheck(OBJ2D*, float);

#endif // !INCLUDED_OBJ2D
