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
	float roll, pitch, yaw; /////���p��
	int state; /////�����
	bool visible; ///��������
	bool isMoving = false;
	bool hasChangedState = false;

	float red, green, blue; ///////���F

	float move; //�����x�km/�t���[���l
	float turn; //�����񑬓x�i�e���x�j�k�x/�t���[���l

	float radius; //���a
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
	//////// ���[�U��`�̃V�[���ɂ��Ẵf�[�^�������ɂ܂Ƃ߂�

	ObjDataT cube[3]; ///////���L���[�u
	ObjDataT sphere; /////������
	ObjDataT *active_camera;

	ObjDataT player; /////���v���C��������킷�I�u�W�F�N�g
	ObjDataT enemy[10];
	ObjDataT bullet;
	ObjDataT goal;

	////////
} SimDataT;



