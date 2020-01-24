#ifndef INCLUDED_ground_h_
#define INCLUDED_ground_h_

#include "object.h"

class CGroundObject : public AObjectBase{
private:
public:
	CGroundObject(Vector3 *pos, Vector3 *eulerAngle, float radius, Vector3 *col);
	void DrawObj() override;
};

#endif // !INCLUDED_ground_h_
