#include "text.h"
#include "game_manager.h"

CTextObject::CTextObject(){

}

CTextObject::~CTextObject(){}

void CTextObject::DrawObj(){
	switch (UGameManager::GetInstance().GameState())
	{
	case START:
		glColor3f(1.0, 1.0, 1.0);
		DrawString(190.0, 270.0, 15.0, 15.0,

			GLUT_STROKE_ROMAN,

			"PRESS MOUSE TO START!");
		break;
	case ONGAME:
		break;
	case GAMECLEAR:
		DrawString(250.0, 280.0, 15.0, 15.0,

			GLUT_STROKE_ROMAN,

			"GAME CLEAR!");
		break;
	case GAMEOVER:
		DrawString(250.0, 280.0, 15.0, 15.0,

			GLUT_STROKE_ROMAN,

			"GAME OVER...");
		break;
	default:
		break;
	}
}

void CTextObject::DrawString(float x, float y, float xscl, float yscl, void * font, const char * string)
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