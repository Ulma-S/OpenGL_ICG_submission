#include <stdlib.h>
#include <stdio.h>

#include "platform.h"
#include "common.h"
#include "sim.h"
#include "camera.h"
#include "player.h"

extern SimDataT simdata;
extern WindowDataT window;
extern AObjectBase *camera;
extern CPlayerObject *player;

/*---------------------------------------------------------------- Viewing
 * Viewing:
 *--------*/
void Viewing(void)
{
	//gluLookAt( 0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
	//gluLookAt( 2.0, 2.0, 6.0, simdata.player.x, simdata.player.y, simdata.player.z, 0.0, 1.0, 0.0 );
	//gluLookAt(0, 2.0, 2.0, simdata.player.position.x, simdata.player.position.y, simdata.player.position.z, 0.0, 1.0, 0.0);

	gluLookAt(6.0, 3.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
