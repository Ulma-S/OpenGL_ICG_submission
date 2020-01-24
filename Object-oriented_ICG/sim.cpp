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
#include "game_manager.h"

using namespace std;

SimDataT simdata; //SimDataT�^�\���̂̃f�[�^��錾
CPlayerObject *player;

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
	UGameManager::GetInstance().InitGame();
	player = UGameManager::GetInstance().Player();
	return;
}

/*-------------------------------------------------------------- UpdateScene
 * UpdateScene:
 *--------*/
void UpdateScene(void)
{
	UGameManager::GetInstance().UpdateGame();
	return;
}
