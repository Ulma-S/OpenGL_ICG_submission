#include "gage.h"

CHPGage::CHPGage(AMovableObject *target, Vector3 *col) {
	m_target = target;
	m_color = *col;
}

void CHPGage::DrawObj() {
	m_hpValue = 1.0*m_target->CurrHP() / m_target->MaxHP();
	SetMaterialColor(this);
	glPushMatrix();
	{
		glBegin(GL_POLYGON);
		glVertex3f(0, 0.6, 0);
		glVertex3f(0, 0.3, 0);
		glVertex3f(m_hpValue, 0.3, 0);
		glVertex3f(m_hpValue, 0.6, 0);
		glEnd();
	}
	glPopMatrix();
}