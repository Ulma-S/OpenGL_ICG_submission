#define N_ENEMIES 6
#define N_HEAL 3
#include "vector.h"
// sim.cpp
void InitScene(void);
void UpdateScene(void);

// draw.cpp
void DrawScene(void);

//typedef struct {
//	float x;
//	float y;
//	float z;
//
//}Vector3;

//Game State
enum GameState {
	START = 0,
	PLAYING,
	GAMEOVER,
	GAMECLEAR,
};

//-------- object data
typedef struct {

	Vector3 position;
	float roll, pitch, yaw; /////◆姿勢
	int state; /////◆状態
	bool visible; ///◆可視属性
	bool isMoving = false;
	bool hasChangedState = false;

	float red, green, blue; ///////◆色

	float move; //◆速度〔m/フレーム〕
	float turn; //◆旋回速度（各速度）〔度/フレーム〕

	float radius; //半径
	float speed;

	float hp;
	float maxHP;

} ObjDataT;

//-------- simulation data
typedef struct {

	float clip_near;
	float clip_far;
	float air_color[4];
	float sky_color[4];
	//////// ユーザ定義のシーンについてのデータをここにまとめる

	ObjDataT cube[3]; ///////◆キューブ
	ObjDataT sphere; /////◆球体
	ObjDataT *active_camera;

	ObjDataT player; /////◆プレイヤをあらわすオブジェクト
	ObjDataT enemy[10];
	ObjDataT bullet;
	ObjDataT goal;

	////////
} SimDataT;



