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
#include "game_manager.h"

using namespace std;

//-------- prototypes for user functions

void drawString(float x, float y, float xscl, float yscl,
	void *font, const char *string);

void drawString(float x, float y, float xscl, float yscl,
	void *font, const char *string)
{
	glPushMatrix();
	{
		glTranslatef(x, y, 0.0);
		glScalef(xscl*0.01, yscl*0.01, 1.0);

		while (*string) {
			glutStrokeCharacter(font, *string++);
		}
	}
	glPopMatrix();
	return;
}

/*---------------------------------------------------------------- DrawScene
 * DrawScene:
 *--------*/
void DrawScene(void)
{
	UGameManager::GetInstance().DrawGame();
	return;
}
