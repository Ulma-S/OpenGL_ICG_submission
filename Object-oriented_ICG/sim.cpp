#include <stdio.h>
#include<iostream>
#include <stdlib.h>

#include "common.h"

#include "sim.h"
#include "calc.h" /////��MoveObject�̂��߂ɕK�v
#include "player.h"
#include "enemy.h"
#include "heal.h"
#include "ground.h"
#include "camera.h"
#include "collision_detector.h"
//#include "game_manager.h"

using namespace std;

SimDataT simdata; //SimDataT�^�\���̂̃f�[�^��錾
CPlayerObject *player;
CEnemyObject *enemy;
CHealObject *heal;
CGroundObject *ground;
AObjectBase *camera;

//UGameManager *game;

extern int time;

//���P���f�[�^�^(float)�����̂܂܎g���ꍇ
//float sphere_red, sphere_green, sphere_blue;
//float cube_red, cube_green, cube_blue;
//���z��𓱓�
//float sphere_color[3] = { 1.0, 1.0, 0.0 };

//���\����
/*
typedef struct{
	float red, blue, green;
} color_t;
color_t sphere_color = { 1.0, 1.0, 0.0 };
*/

Vector3 Init(float x, float y, float z);
void InitSimData(ObjDataT *obj, float x, float y, float z, float r, float g, float b, float radius);

int bulletCount = 0;
//GameState game_state = START;

/*---------------------------------------------------------------- InitScene
 * InitScene:
 *--------*/
void InitScene(void)
{
	////// �V�[���f�[�^�̏�����
	simdata.clip_far = 200.0; //���t�@�[�N���b�v�v���[��
	simdata.clip_near = 0.1;
	simdata.air_color[0] = 1.0;
	simdata.air_color[1] = 1.0;
	simdata.air_color[2] = 1.0;
	simdata.air_color[3] = 0.5; // fog density factor
	simdata.sky_color[0] = 0.2;
	simdata.sky_color[1] = 0.3;
	simdata.sky_color[2] = 0.4;
	simdata.sky_color[3] = 0.5; // sky color factor
	//////

	///���ǉ������I�u�W�F�N�g�̏�����
	simdata.active_camera = &simdata.player;
	InitSimData(&simdata.player, 0, 0, 0, 1, 0, 0, 0.2);
	simdata.player.hp = 100;
	simdata.player.maxHP = 100;

	InitSimData(&simdata.cube[0], 4, 0, 0, 0, 1, 0, 0.2);
	InitSimData(&simdata.cube[1], 0, 0, -4, 0, 1, 0, 0.2);
	InitSimData(&simdata.cube[2], -4, 0, 0, 0, 1, 0, 0.2);

	InitSimData(&simdata.enemy[0], 0, 0, 6, 0, 0, 0, 0.2);
	InitSimData(&simdata.enemy[1], 6, 0, 0, 0, 0, 0, 0.2);
	InitSimData(&simdata.enemy[2], -6, 0, 0, 0, 0, 0, 0.2);
	InitSimData(&simdata.enemy[3], 6, 0, -6, 0, 0, 0, 0.2);
	InitSimData(&simdata.enemy[4], -6, 0, -6, 0, 0, 0, 0.2);
	InitSimData(&simdata.enemy[5], 0, 0, -6, 0, 0, 0, 0.2);

	InitSimData(&simdata.goal, -6, 0, -6, 0, 0, 0, 0.2);

	for (int i = 0; i < N_ENEMIES; ++i) {
		simdata.enemy[i].state = 0;	//0:normal, 1:hard
		simdata.enemy[i].visible = true;
		simdata.enemy[i].hp = 1;
	}

	for (int i = 0; i < N_HEAL; ++i) {
		simdata.cube[i].hasChangedState = false;
	}

	InitSimData(&simdata.bullet, -100, -100, -100, 0, 0, 0, 0.1);	//�����l��0�ɂ����player�̏����l�Ɣ���ď���ɃN���A�ɂȂ����Ⴄ�̂�
	simdata.bullet.visible = false;
	simdata.bullet.state = 0;
	player = new CPlayerObject(new Vector3(0, 0, 0), new Vector3(0, 0, 0), 0.2, 0.5, 0.02, 100, new Vector3(1.0, 0.0, 0.0));
	enemy = new CEnemyObject(new Vector3(2, 0, 2), new Vector3(0.0, 0.0, 0.0), 0.2, 0.04, 0.02, 100, new Vector3(0.0, 0.0, 0.0), player);
	heal = new CHealObject(new Vector3(0, 0, 0), new Vector3(0.0, 0.0, 0.0), 0.2, new Vector3(0.0, 1.0, 0.0), 30, player);
	ground = new CGroundObject(new Vector3(0, 0, 0), new Vector3(0.0, 0.0, 0.0), 10.0, new Vector3(0.0, 1.0, 0.0));
	camera = player;
	//game = new UGameManager();
	//game->InitGame();
	return;
}

/*-------------------------------------------------------------- UpdateScene
 * UpdateScene:
 *--------*/
void UpdateScene(void)
{
	//game->UpdateGame();
	//if (game_state != PLAYING)return;	//�Q�[���v���C���łȂ����return (START�Ƃ�GAMECLEAR�Ƃ��̏��������Ȃ�����)

	if (player != 0)player->UpdatePos();
	if (enemy != 0)enemy->UpdatePos();

	for (int i = 0; i < player->BulletNum(); ++i) {
		if (player->Bulllets()[i] == 0)continue;
		player->Bulllets()[i]->UpdatePos();
	}

	if (UCollisionDetector::GetInstance().TriggerStay(player, enemy)) {
		enemy->Neutralize();
	}
	//cout << ground->Color().x << " " << ground->Color().y << " " << ground->Color().z << endl;
	//cout << player->Pos().z << endl;

	//for (int i = 0; i < N_ENEMIES; i++) {
	//	if (simdata.enemy[i].visible)break;
	//	if (i == N_ENEMIES - 1 && simdata.enemy[i].state == 0) {
	//		++simdata.enemy[i].state;
	//	}	//���ׂĂ̓G�������Ă�����enemyState���Z
	//	if (simdata.enemy[i].state == 1 && simdata.enemy[i].hasChangedState == false) {
	//		InitSimData(&simdata.enemy[0], 0, 0, 6, 0, 0, 0, 0.2);
	//		InitSimData(&simdata.enemy[1], 6, 0, 0, 0, 0, 0, 0.2);
	//		InitSimData(&simdata.enemy[2], -6, 0, 0, 0, 0, 0, 0.2);
	//		InitSimData(&simdata.enemy[3], 6, 0, -6, 0, 0, 0, 0.2);
	//		InitSimData(&simdata.enemy[4], -6, 0, -6, 0, 0, 0, 0.2);
	//		InitSimData(&simdata.enemy[5], 0, 0, -6, 0, 0, 0, 0.2);
	//		simdata.enemy[i].visible = true;
	//		simdata.enemy[i].hp = 1;
	//		cout << "CHANGE" << endl;
	//		simdata.enemy[i].hasChangedState = true;
	//	}
	//}
	//cout << simdata.enemy[0].visible << endl;

	//Player��hp��0�ȉ��Ȃ��gameover
	if (simdata.player.hp <= 0) {
		//game_state = GAMEOVER;
	}

	for (int i = 0; i < N_ENEMIES; ++i) {
		if (simdata.enemy[i].hp <= 0)simdata.enemy[i].visible = false;
	}

	//Goal
	/*if (HasHit(&simdata.player, &simdata.goal)) {
		for (int i = 0; i < N_ENEMIES; ++i) {
			if (simdata.enemy[i].state == 0)break;
			if (simdata.enemy[i].visible == true)break;
			game_state = GAMECLEAR;
		}
	}*/

	//Player���ړ����Ȃ��hp�����炷
	if (simdata.player.isMoving) {
		//		simdata.player.hp -= 0.05;
	}

	/*MoveObject(&simdata.player);
	for (int i = 0; i < N_HEAL; i++) {
		if (HasHit(&simdata.player, &simdata.cube[i]) && !simdata.cube[i].hasChangedState) {
			if (simdata.player.hp < simdata.player.maxHP) {
				simdata.player.hp += 30;
				simdata.cube[i].hasChangedState = true;
			}
		}
	}*/

	/*for (int i = 0; i < N_ENEMIES; i++) {
		if (HasHit(&simdata.player, &simdata.enemy[i]) && simdata.enemy[i].visible) {
			if (simdata.player.hp > 0) {
				simdata.player.hp -= 0.2;
			}
		}
	}*/

	//for (int i = 0; i < N_ENEMIES; i++) {
	//	if (HasHit(&simdata.enemy[i], &simdata.bullet)) {
	//		//simdata.enemy[i].visible = false;
	//		--simdata.enemy[i].hp;
	//	}
	//}

	for (int i = 0; i < N_ENEMIES; i++) {
		//float dist;
		//euler_t angle;
		//float k_move = 0.01; //���x�p�����[�^�i�{�͒ǐՁA�|�͓����`�������̌ジ���聦�j

	//	dist = EulerAtoB(&simdata.enemy[i], &simdata.player, &angle);

		//simdata.enemy[i].move = k_move;
		//simdata.enemy[i].turn = 0.0;
		//simdata.enemy[i].yaw = angle.yaw; //player�ւ̕�����ݒ聦

		//if (dist > 0.2 && simdata.enemy[i].visible) {
	//		MoveObject(&simdata.enemy[i]);
		//
	}

	//switch (simdata.bullet.state) {
	//case 0:
	//	break;

	//case 1:
	//	//���ʒu�̍X�V
	//	//MoveObject(&simdata.bullet);

	//	//���Փ˔���
	//	//if (HasHit(&simdata.bullet, &simdata.enemy[0])) { //�������ځF�U���Ώ�
	//	//	simdata.bullet.state = 2; //���e�Ɉڍs
	//	//	simdata.enemy[0].state = 1;
	//	//}

	//	//if (DistanceAtoB(&simdata.bullet, &simdata.enemy[0]) > 50.0) {
	//	//	simdata.bullet.state = 0; //�e������ĉ����܂Ō������烊�Z�b�g
	//	//}
	//	break;

	//case 2:
	//	simdata.bullet.state = 0; //�ȒP�̂��߁A���e�㏉����Ԃɕ��A
	//	break;
	//}
	////////
	return;
}

void InitSimData(ObjDataT *obj, float x, float y, float z, float r, float g, float b, float radius) {
	obj->position.x = x;
	obj->position.y = y;
	obj->position.z = z;
	obj->red = r;
	obj->green = g;
	obj->blue = b;
	obj->radius = radius;
}