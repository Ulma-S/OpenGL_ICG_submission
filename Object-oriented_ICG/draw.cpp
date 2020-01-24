#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "platform.h"

#include "common.h"

#include "sim.h"
#include "player.h"
#include "enemy.h"
#include "heal.h"
#include "ground.h"
//#include "game_manager.h"

using namespace std;

extern WindowDataT window;
extern SimDataT simdata;

//-------- prototypes for user functions

void drawString(float x, float y, float xscl, float yscl,
	void *font, const char *string);

//extern GameState game_state;

//extern UGameManager *game;

extern CPlayerObject *player;
extern CEnemyObject *enemy;
extern CHealObject *heal;
extern CGroundObject *ground;

//HPGage
float hpGageValue = 1.0;

//Developer Tools
//void DrawAxis();

void drawString(float x, float y, float xscl, float yscl,
	void *font, const char *string)
{
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glScalef(xscl*0.01, yscl*0.01, 1.0);

	while (*string) {
		glutStrokeCharacter(font, *string++);
	}
	glPopMatrix();
	return;
}

/*---------------------------------------------------------------- DrawScene
 * DrawScene:
 *--------*/
void DrawScene(void)
{
	//game->DrawGame();
	glPushMatrix();
	{
		player->SetObjTransform(player);
		player->DrawObj();
	}
	glPopMatrix();

	glPushMatrix();
	{
		enemy->SetObjTransform(enemy);
		enemy->DrawObj();
	}
	glPopMatrix();

	glPushMatrix();
	{
		for (int i = 0; i < player->BulletNum(); ++i)
		{
			glPushMatrix();
			player->SetObjTransform(player->Bulllets()[i]);
			player->Bulllets()[i]->DrawObj();
			glPopMatrix();
		}
	}
	glPopMatrix();

	glPushMatrix();
	{
		heal->SetObjTransform(heal);
		heal->DrawObj();
	}
	glPopMatrix();

	glPushMatrix();
	{
		ground->SetObjTransform(ground);
		ground->DrawObj();
	}
	glPopMatrix();

	//glDisable(GL_LIGHTING); //照明OFF

	//glDisable(GL_DEPTH_TEST); //デプス処理OFF

	//glMatrixMode(GL_PROJECTION);

	//glLoadIdentity();

	//glOrtho(0, 640, 0, 480, -1.0, 1.0); //並行投影に設定（2D表現に変更）

	//glMatrixMode(GL_MODELVIEW);

	//glLoadIdentity();

	/////////////////////////////////////////////

	// この部分に、文字描画コードを書く（以下参考）

	glColor3f(0.0, 0.0, 0.0); //文字色

	/*switch (game_state)
	{
	case START:
		drawString(190.0, 270.0, 15.0, 15.0,

			GLUT_STROKE_ROMAN,

			"PRESS MOUSE TO START!");
		break;
	case PLAYING:
		break;
	case GAMECLEAR:
		drawString(250.0, 280.0, 15.0, 15.0,

			GLUT_STROKE_ROMAN,

			"GAME CLEAR!");
		break;
	case GAMEOVER:
		drawString(250.0, 280.0, 15.0, 15.0,

			GLUT_STROKE_ROMAN,

			"GAME OVER...");
		break;
	default:
		break;
	}*/
	return;
}

//
////Developer Tools
//void DrawAxis() {
//	float axisLength = 10000;
//	//x
//	glBegin(GL_LINES);
//	setMaterialColor(1.0, 0, 0);
//	glVertex3f(-axisLength, 0, 0);
//	glVertex3f(axisLength, 0, 0);
//	glEnd();
//
//	//y
//
//	glBegin(GL_LINES);
//	setMaterialColor(0, 1.0, 0);
//	glVertex3f(0, -axisLength, 0);
//	glVertex3f(0, axisLength, 0);
//	glEnd();
//
//	//z
//
//	glBegin(GL_LINES);
//	setMaterialColor(0, 0, 1.0);
//	glVertex3f(0, 0, -axisLength);
//	glVertex3f(0, 0, axisLength);
//	glEnd();
//}
