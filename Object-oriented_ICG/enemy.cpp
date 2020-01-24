#include "enemy.h"
#include "calc.h"

CEnemyObject::CEnemyObject(Vector3 *pos, Vector3 *eulerAngle, float radius, float speed, float turn, int maxHP, Vector3 *col, AObjectBase *target) {
	//ƒ[ƒJƒ‹•Ï”‚Ì‰Šú‰»
	m_position = *pos;
	m_eulerAngle = *eulerAngle;
	m_radius = radius;
	m_isVisible = true;
	m_speed = speed;
	m_turn = turn;
	m_maxHP = maxHP;
	m_currHP = maxHP;
	m_isMoving = false;
	m_color = *col;
	m_turn = 0;
	m_target = target;
}

void CEnemyObject::DrawObj() {
	if (!m_isVisible)return;
	this->SetMaterialColor(this);

	glPushMatrix();
	{
		glTranslatef(0, 0, 0);
		glRotatef(0.0, 0.0, 1.0, 0.0);
		glRotatef(0.0, 1.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 1.0);
		glutSolidSphere(m_radius * 2, 18, 16);
	}
	glPopMatrix();
}

void CEnemyObject::UpdatePos() {
	float dist;
	euler_t angle;
	dist = EulerAtoB(this, m_target, &angle);
	m_eulerAngle.y = angle.yaw;

	if (dist > m_target->Radius() + m_radius && m_isVisible) {
		MoveObject(this);
	}
}

void CEnemyObject::Neutralize() {
	m_isVisible = false;
	m_isMoving = false;
}