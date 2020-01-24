#include "ground.h"

CGroundObject::CGroundObject(Vector3 *pos, Vector3 *eulerAngle, float radius, Vector3 *col) {
	m_position = *pos;
	m_eulerAngle = *eulerAngle;
	m_radius = radius;
	m_color = *col;
	m_isVisible = true;
}

void CGroundObject::DrawObj() {
	if (!m_isVisible)return;

	this->SetMaterialColor(this);
	glPushMatrix();
	{
		float gLength = m_radius;
		float gDepth = -m_radius/10;
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 1.0, 0.0);
		glRotatef(0.0, 1.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex3f(-gLength, gDepth, -gLength);
		glVertex3f(-gLength, gDepth, gLength);
		glVertex3f(gLength, gDepth, gLength);
		glVertex3f(gLength, gDepth, -gLength);
		glEnd();
		//glutSolidCube(gDepth);
	}
	glPopMatrix();
}