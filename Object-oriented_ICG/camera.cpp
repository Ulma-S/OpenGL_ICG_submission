#include "camera.h"

CCameraObject::CCameraObject(Vector3 *pos, Vector3 *eulerAngle) {
	m_position = *pos;
	m_eulerAngle = *eulerAngle;
}

void CCameraObject::DrawObj() {}