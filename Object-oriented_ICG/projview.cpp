#include <stdlib.h>
#include <stdio.h>

#include "platform.h"
#include "common.h"
#include "sim.h"
#include "camera.h"
#include "player.h"
#include "game_manager.h"

extern SimDataT simdata;
extern WindowDataT window;
AObjectBase *camera;

/*---------------------------------------------------------------- Viewing
 * Viewing:
 *--------*/
void Viewing(void)
{
	camera = UGameManager::GetInstance().Camera();

	gluLookAt(0.0, 3.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(-camera->EulerAngle().z, 0.0, 0.0, 1.0);

	glRotatef(-camera->EulerAngle().x, 1.0, 0.0, 0.0);

	glRotatef(-camera->EulerAngle().y, 0.0, 1.0, 0.0);

	//分かりやすいように改行していますが、改行なしでも構いません。

	glTranslatef(-camera->Pos().x,

		-camera->Pos().y,

		-camera->Pos().z);
}
/*---------------------------------------------------------------- Projection
 * Projection:
 *--------*/
void Projection(void)
{
	//---- begin projection transformation
	gluPerspective(45.0, window.aspect, simdata.clip_near, simdata.clip_far);
}
