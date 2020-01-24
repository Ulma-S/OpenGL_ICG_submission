#include "heal.h"

CHealObject::CHealObject(Vector3 *pos, Vector3 *eulerAngle, float radius, Vector3 *col, float healValue, AMovableObject *target) {
	m_position = *pos;
	m_eulerAngle = *eulerAngle;
	m_radius = radius;
	m_color = *col;
	m_isVisible = true;
	m_healValue = healValue;
	m_target = target;
}

void CHealObject::DrawObj() {
	if (!m_isVisible)return;
	this->SetMaterialColor(this);

	glPushMatrix();
	{
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 1.0, 0.0);
		glRotatef(0.0, 1.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 1.0);
		glutSolidCube(m_radius * 2);
	}
	glPopMatrix();
}

void CHealObject::Heal() {
	m_target->CurrHP(m_target->CurrHP()+ m_healValue);
}