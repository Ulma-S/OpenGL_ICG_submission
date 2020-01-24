#ifndef INCLUDED_camera_h_
#define INCLUDED_camera_h_

#include "object.h"

class CCameraObject : public AObjectBase{
private:
public:
	CCameraObject(Vector3 *pos, Vector3 *eulerAngle);
	void DrawObj() override;
};

#endif // !INCLUDED_camera_h_
