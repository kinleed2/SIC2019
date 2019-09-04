#include "all.h"

extern OBJ2D enemyGuard[3];
extern OBJ2D enemyUav[3];
extern OBJ2D enemyCamera[3];
extern OBJ2D player;
extern OBJ2D map[24][32];

void stage_1_init()
{
	map_init();

	player_init();
	//全部の敵の初期化
	enemy_init();

	//警備員の初期化
	enemy_guard_init(enemyGuard, 690, 800, left);
}

void stage_1_update()
{
	//stage 1のデータ
	int stage1[24][32] = 
	  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	//マップチップ更新
	map_update(stage1);
	//敵の移動
	enemy_guard_move(enemyGuard,300, 900, 2);

	player_update();

	check(stage1set,stage1end);


}

void stage_2_init()
{
	map_init();

	player_init();


	enemy_init();
	enemy_guard_init(enemyGuard, 690, 800, left);
	enemy_camera_init(enemyCamera, 860, 320, right, 40, 20, 0);
	//enemy_guard_init(enemyGuard + 1, 100, 250, right);
}

void stage_2_update()
{
	//stage 2のデータ
	int stage2[24][32] = 
	  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	//マップチップ更新
	map_update(stage2);
	//敵の移動
	enemy_guard_move(enemyGuard, 40, 1100, 1);
	enemy_camera_move(enemyCamera, 1, 680, 960, 1 ,0 ,0);
	//enemy_guard_move(enemyGuard + 1, 100, 900, 10);


	player_update();

	check(stage2set,stage2end);


}
void stage_3_init()
{
	map_init();

	player_init();


	enemy_init();
	enemy_guard_init(enemyGuard, 560, 800, left);
	//enemy_guard_init(enemyGuard + 1, 1200, 800, right);
	enemy_camera_init(enemyCamera, 300, 760, left, 0, 0, 0);
	//enemy_camera_init(enemyCamera + 1, 1100, 360, up, 160, 0, 90);
	enemy_uav_init(enemyUav, 400, 220, left);
	enemy_uav_init(enemyUav + 1, 1100, 360, down);

	//enemy_guard_init(enemyGuard + 1, 100, 250, right);
}
void stage_3_update()
{
	//stage 3のデータ
	int stage3[24][32] =
	{   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,
		0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	//マップチップ更新
	map_update(stage3);
	//敵の移動
	enemy_guard_move(enemyGuard, 300, 880, 1);
	//enemy_guard_move(enemyGuard + 1, 880, 1200, 1);
	enemy_camera_move(enemyCamera, 1, 120, 400, 1, 0, 0);
	//enemy_camera_move(enemyCamera + 1 , 2, 0, 0, 1, 200, 480);
	enemy_uav_move(enemyUav, 1, 400, 840, 1, 0, 0);
	enemy_uav_move(enemyUav + 1, 2, 0, 0, 1, 120, 480);

	//enemy_guard_move(enemyGuard + 1, 100, 900, 10);


	player_update();

	check(stage3set, stage3end);


}

void stage_4_init()
{
	map_init();

	player_init();


	enemy_init();
	enemy_guard_init(enemyGuard, 640, 800, right);
	enemy_guard_init(enemyGuard + 1, 800, 800, left);
	enemy_camera_init(enemyCamera, 400, 400, left, -10, -20, 0);
	enemy_camera_init(enemyCamera + 1, 240, 760, 0, 60, -10, 0);
	enemy_uav_init(enemyUav, 40, 200, right);
	enemy_uav_init(enemyUav + 1, 720, 560, right);

	//enemy_guard_init(enemyGuard + 1, 100, 250, right);
}
void stage_4_update()
{
	//stage 4のデータ
	int stage4[24][32] =
	{   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	//マップチップ更新
	map_update(stage4);
	//敵の移動
	enemy_guard_move(enemyGuard, 300, 1100, 1);
	enemy_guard_move(enemyGuard + 1, 300, 1100, 1);
	enemy_camera_move(enemyCamera, 1, 120, 440, 1, 0, 0);
	enemy_camera_move(enemyCamera + 1, 1, 760, 340, 0, 0, 0);
	enemy_uav_move(enemyUav, 1, 80, 600, 1, 0, 0);
	enemy_uav_move(enemyUav + 1, 1, 600, 1160, 1, 0, 0);

	//enemy_guard_move(enemyGuard + 1, 100, 900, 10);


	player_update();

	check(stage4set, stage4end);


}
void stage_5_init()
{
	map_init();

	player_init();


	enemy_init();
	enemy_guard_init(enemyGuard, 560, 800, right);
	enemy_guard_init(enemyGuard + 1, 880, 800, left);
	enemy_guard_init(enemyGuard + 2, 920, 360, left);
	//enemy_camera_init(enemyCamera, 400, 400, left, 200, 0, 0);
	//enemy_camera_init(enemyCamera + 1, 240, 760, 0, 0, 0, 0);
	enemy_uav_init(enemyUav, 80, 320, right);
	enemy_uav_init(enemyUav + 1, 400, 160, left);

}
void stage_5_update()
{
	//stage 5のデータ
	int stage5[24][32] =
	{   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	//マップチップ更新
	map_update(stage5);
	//敵の移動
	enemy_guard_move(enemyGuard, 280, 1000, 1);
	enemy_guard_move(enemyGuard + 1, 280, 1000, 1);
	enemy_guard_move(enemyGuard + 2, 680, 1100, 1);
	//enemy_camera_move(enemyCamera, 1, 120, 440, 1, 0, 0);h
	//enemy_camera_move(enemyCamera + 1, 1, 760, 340, 0, 0, 0);
	enemy_uav_move(enemyUav, 2, 80, 480, 1, 320, 680);
	enemy_uav_move(enemyUav + 1, 1, 400, 680, 1, 0, 0);

	player_update();

	check(stage5set, stage5end);


}



void stage_0_init()
{
	map_init();

	player_init();

	enemy_init();

	
	if (player.guideState < 8)
	{
		player.guideState = 0;
	}
	else
	{
		enemy_guard_init(enemyGuard, 1000, 800, left);
	}

	player.timer = 0;

	player.pos.x = 200;



}


void stage_0_update()
{
	player.timer++;
	//stage 0のデータ
	int stage0[24][32] =
	{	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,
		0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};
	//マップチップ更新
	map_update(stage0);

	//enemy_guard_move(enemyGuard, 300, 900, 2);


	switch (player.guideState)
	{
	case 0:
		if (STATE(0) & PAD_LEFT)
		{
			player.direction = left;
			//player.pos.x -= 5;
			if (player.speed.x > -5 && player.timer % 2 == 0)
			{
				player.speed.x--;
			}

		}
		//滑る
		else if (player.speed.x < 0 && player.timer % 1 == 0)
		{
			player.speed.x++;
		}

		player.pos.x += player.speed.x;

		if (player.pos.x <= 50)
		{
			player.speed.x = 0;
			player.guideState++;
		}

		if (player.state == 0)
		{
			player.anime = 0;

			if (player.direction == right)
			{
				player.texPos.y = right;

			}
			if (player.direction == left)
			{
				player.texPos.y = left * player.texSize.y;
			}
			if (STATE(0) & PAD_RIGHT || STATE(0) & PAD_LEFT)
			{
				player.anime = 2 + player.timer / 10 % 7;
			}
			else
			{
				player.anime = player.timer / 25 % 2;
			}
		}

		break;

	case 1:
		if (STATE(0)& PAD_RIGHT)
		{

			player.direction = right;
			if (player.speed.x < 5 && player.timer % 2 == 0)
			{
				player.speed.x++;
			}
		}
		//滑る
		else if (player.speed.x > 0 && player.timer % 1 == 0)
		{
			player.speed.x--;

		}

		player.pos.x += player.speed.x;

		if (player.pos.x >= 250)
		{
			player.speed.x = 0;
			player.guideState++;
		}

		if (player.type == 0)
		{
			player.anime = 0;

			if (player.direction == right)
			{
				player.texPos.y = right;

			}
			if (player.direction == left)
			{
				player.texPos.y = left * player.texSize.y;
			}
			if (STATE(0) & PAD_RIGHT || STATE(0) & PAD_LEFT)
			{
				player.anime = 2 + player.timer / 10 % 7;
			}
			else
			{
				player.anime = player.timer / 25 % 2;
			}
		}

		break;
	
	case 2:

		
		player_connect();

		if (player.cnt == 1)
		{
			player.guideState++;
		}

		break;
	case 3:
		player_move();
		if (player.pos.x >= 500)
		{
			player.speed.x = 0;
			player.guideState++;
		}

		break;
	case 4:

	

		player_fall();

		player_hook();
		
		if (player.pos.y == 560 && player.pos.x >= 620)
		{
			player.speed.x = 0;
			player.guideState++;
		}
	
		break;
	case 5:
		player_connect();

		if (player.score == 1)
		{
			
			player.anime = 0;
			enemy_guard_init(enemyGuard, 1000, 800, left);
			player.guideState++;
		}
		break;
	case 6:
		enemyGuard[0].pos.x -= 1.5f;

		enemyGuard[0].anime = 2 + player.timer / 20 % 4;

		if (player.score == 0)
		{
			player.guideState++;
		}

		break;
	case 7:
		if (STATE (0) & PAD_TRG1)
		{
			player.exist = TRUE;
			player.state = 0;
			player.guideState++;
		}
		break;
	case 8:
		player_update();
		enemy_guard_move(enemyGuard, 300, 900, 2);
		break;

	default:
		break;
	}


	check(stage0set, stage0end);
}

void stage_0_draw()
{
	switch (player.guideState)
	{
	case 0:
		primitive::rect(player.pos.x - 50, player.pos.y - 80, 250, 80, 0, 0, 0, 1, 1, 1, 1);
		font::textOut(4, "Press <-", player.pos.x - 30, player.pos.y - 50, 1.0f, 1.0f, 0, 0, 0);


		break;
	case 1:

		font::textOut(4, "Press ->", player.pos.x - 30, player.pos.y - 50, 1.0f, 1.0f, 0, 1, 1);


		break;
	case 2:
		font::textOut(4, "Press A(controller) or Z(keyboard) ", player.pos.x - 30, player.pos.y - 100, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "to xxx", player.pos.x - 30, player.pos.y - 50, 1.0f, 1.0f, 0, 1, 1);

		break;
	case 3:
		font::textOut(4, "Go to the right", player.pos.x - 30, player.pos.y - 50, 1.0f, 1.0f, 0, 1, 1);


		break;
	case 4:
		if (player.state == 0)
		{


			font::textOut(4, "Press R1(controller) or S(keyboard)", player.pos.x - 350, player.pos.y - 250, 1.0f, 1.0f, 0, 1, 1);

			font::textOut(4, "to aim and Press A(controller) or ", player.pos.x - 350, player.pos.y - 200, 1.0f, 1.0f, 0, 1, 1);
			font::textOut(4, "to use hook", player.pos.x - 350, player.pos.y - 150, 1.0f, 1.0f, 0, 1, 1);
		}
		break;
	case 5:
		font::textOut(4, "Press A(controller) or Z(keyboard)", player.pos.x - 500, player.pos.y -100, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "connect the xx to open the door)", player.pos.x - 500, player.pos.y - 50, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "Door", 1170,650, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "|", 1237, 680, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "V", 1230, 700, 1.0f, 1.0f, 0, 1, 1);
		break;
	case 6:
		font::textOut(4, "Be careful guard will cut you \"connection\" ", player.pos.x - 500, player.pos.y - 50, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "close the door ", player.pos.x - 500, player.pos.y, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "If you are exposed to the guards,", player.pos.x - 500, player.pos.y + 50, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "drones and cameras", player.pos.x - 500, player.pos.y + 100, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "Door", 1170, 650, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "|", 1237, 680, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "V", 1230, 700, 1.0f, 1.0f, 0, 1, 1);
		break;
	case 7:
		
		primitive::rect(0, 0, 1280, 960, 0, 0, 0, 0, 0, 0, 0.7);

		int hpPos;
		hpPos = 50;
		int i;
		for (i = 0; i < player.hp; i++)
		{
			sprite_render(player.data,                  // 使用するスプライト
				hpPos, 0,             // 位置
				1, 1,         // スケールv
				1200, 0,       // 元画像位置
				80, 80,     // 元画像大きさ
				0, 0,   // 基準点の位置
				0.0f,
				1, 1, 1, 1);
			hpPos += 100;
		}

		
		font::textOut(4, "your escape times will be -1", 100, 150, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "Press A(controller) or Z(keyboard) ", 100, 250, 1.0f, 1.0f, 0, 1, 1);
		font::textOut(4, "to enjoy your game ", 100, 300, 1.0f, 1.0f, 0, 1, 1);
		break;
	case 8:

		break;
	default:
		break;
	}

	

}


int stage_end(int stage)
{


	int stageEnd[24][32] =
	  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};
	//マップチップ更新
	map_update(stageEnd);


	player.direction = right;
	
	if (player.speed.x == 0)
	{
		player.pos = VECTOR2(640 - 40, 480 - 40);
	}
	player.anime = 2 + player.timer / 10 % 7;

	player.timer++;

	if (TRG(0) & PAD_TRG1)
	{
		player.speed.x = 5;
	}

	player.pos.x += player.speed.x;

	if (player.pos.x >= 1280) stage++;

	return stage;
}

void stage_end_draw(int stage)
{
	
	font::textOut(4, "CLEAR!!", 500, 250, 2.0f, 2.0f, 1, 1, 0);
	font::textOut(4, "Press A(controller) or Z(keyboard) ", 40, 600, 1.5f, 1.5f, 1, 1, 1);
	font::textOut(4, "to next stage", 40, 650, 1.5f, 1.5f, 1, 1, 1);
	

}