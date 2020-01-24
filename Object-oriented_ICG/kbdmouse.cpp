/******************************************************************************
 * keybdmouse.cpp: keyboard and mouse callback functions
 */
#include <stdlib.h>
#include <stdio.h>

#include "platform.h"

#include "common.h"

#include "sim.h"

#include "calc.h"
#include "player.h"

extern SimDataT simdata;
extern WindowDataT window;

extern CPlayerObject *player;

extern int bulletCount;
//extern GameState game_state;

float playerTurn = 0.;
float playerMove = 0.;

//-------- modifier key status
bool isShiftKeyDown(void);
bool isCtrlKeyDown(void);
bool isAltKeyDown(void);

/*-------------------------------------------------- modifier key status
 * Shift, Ctrl, Alt key status
 */
bool isShiftKeyDown(void)
{
	return (bool)(glutGetModifiers() & GLUT_ACTIVE_SHIFT);
}
bool isCtrlKeyDown(void)
{
	return (bool)(glutGetModifiers() & GLUT_ACTIVE_CTRL);
}
bool isAltKeyDown(void)
{
	return (bool)(glutGetModifiers() & GLUT_ACTIVE_ALT);
}

/*------------------------------------------------------------- charKeyDown/Up
 * charKeyDown/Up - GLUT keyboard callback function
 * key: ASCII code
 * x, y: mouse position
 *--------*/
void charKeyDown(unsigned char key, int x, int y)
{
	switch (key) {
	case 'h': // help
		printf("Instruction\n");
		printf("[H]:Help\n");
		printf("[Q]:Quit\n");
		break;
	case 'q': // quit
		exit(0);
		break;

	case 'a': //左旋回
		//simdata.player.x -= 0.05;
		player->Turn(0.2);
		player->IsMoving(true);
		cout << player->Turn() << endl;
		break;
	case 's': //後退
		//simdata.player.z += 0.05;
		/*simdata.player.move -= playerMove;
		simdata.player.isMoving = true;*/
		player->Speed(-0.05);
		player->IsMoving(true);
		break;
	case 'd': //右旋回
		player->Turn(-0.2);
		player->IsMoving(true);
		break;
	case 'w': //前進
		//simdata.player.z -= 0.05;
		player->Speed(0.05);
		player->IsMoving(true);
		break;
	case ' ':
		//simdata.bullet.state = 1; //発射状態に遷移
		//simdata.bullet.move = 0.2; //弾速指定 ※速過ぎるとすり抜けます
		//simdata.bullet.position.x = simdata.player.position.x;
		//simdata.bullet.position.y = simdata.player.position.y + 0.1; //発射高さ調整
		//simdata.bullet.position.z = simdata.player.position.z;
		//simdata.bullet.yaw = simdata.player.yaw; //発射主体の方向を弾丸に設定
		player->Attack();
		break;
	default:
		simdata.player.isMoving = false;
		break;
	}
	return;
}
void charKeyUp(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		player->IsMoving(false);
		player->Speed(0);
		break;
	case 's':
		player->IsMoving(false);
		player->Speed(0);
		break;
	case 'a':
		player->IsMoving(false);
		player->Turn(0);
		break;
	case 'd':
		player->IsMoving(false);
		player->Turn(0);
		break;
	default:
		simdata.player.move = 0;
		simdata.player.turn = 0;
		simdata.player.isMoving = false;
		break;
	}
}
/*--------------------------------------------------------------- funcKeyDown/Up
 * funcKeyDown/Up - GLUT special key callback
 * key: GLUT key code
 * x, y: mouse position
 */
void funcKeyDown(int key, int x, int y)
{
	//ファンクションキー
	//[F*]: GLUT_KEY_F*(*は1～12)
	//[F1]: GLUT_KEY_F1
	//[F12]:GLUT_KEY_F12
	//その他の機能キー
	//[PageUp]  : GLUT_KEY_PAGE_UP:
	//[PageDown]: GLUT_KEY_PAGE_DOWN:
	//[Home]    : GLUT_KEY_HOME:
	//[End]     : GLUT_KEY_END:
	//[Insert]  : GLUT_KEY_INSERT:

	//カーソルキー
	switch (key) {
	case GLUT_KEY_LEFT: //[←]

		break;
	case GLUT_KEY_RIGHT://[→]

		break;
	case GLUT_KEY_UP: //[↑]

		break;
	case GLUT_KEY_DOWN://[↓]

		break;
	}
}
void funcKeyUp(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT: //[←]

		break;
	case GLUT_KEY_RIGHT://[→]

		break;
	case GLUT_KEY_UP: //[↑]

		break;
	case GLUT_KEY_DOWN://[↓]

		break;
	}
}
/*------------------------------------------------------------- mouseClick
 * mouseClick - GLUT mouse callback function
 * button: mouse button
 * state：press or release
 * x, y：mouse position
 *--------*/
void mouseClick(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state) {
		case GLUT_DOWN: // press
			/*if (game_state == START) {
				game_state = PLAYING;
			}*/
			break;
		case GLUT_UP: // release

			break;
		default:
			break;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		switch (state) {
		case GLUT_DOWN: // press

			break;
		case GLUT_UP: // release

			break;
		default:
			break;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		switch (state) {
		case GLUT_DOWN: // press

			break;
		case GLUT_UP: // release

			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return;
}
/*---------------------------------------------------------------- mouseDrag
 * mouseDrag - mouse drag callback function
 */
void mouseDrag(int x, int y)
{
	////////


	////////
	return;
}
/*-------------------------------------------------------------- mouseMotion
 * mouseMotion - passive mouse motion callback function
 */
void mouseMotion(int x, int y)
{
	////////


	////////
	return;
}