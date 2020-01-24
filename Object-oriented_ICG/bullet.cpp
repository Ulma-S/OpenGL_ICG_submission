#include <iostream>
#include "bullet.h"
#include "platform.h"
#include "calc.h"

using namespace std;

CBulletObject::CBulletObject(Vector3 *pos, Vector3 *eulerAngle, float radius, Vector3 *col, float speed, float damage, int thresholdTime, AMovableObject *player) {
	m_position = *pos;
	m_eulerAngle = *eulerAngle;
	m_radius = radius;
	m_color = *col;
	m_speed = speed;
	m_isVisible = false;
	m_isMoving = false;
	m_damageValue = damage;
	m_thresholdTime = thresholdTime;
	m_state = INIT;
	m_turn = 0;
	m_player = player;

}

void ABulletBase::Damage(AMovableObject *target) {
	target->CurrHP(target->CurrHP() - m_damageValue);
}

void CBulletObject::DrawObj() {
	if (!m_isVisible)return;
	this->SetMaterialColor(this);
	glPushMatrix();
	{
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 1.0, 0.0);
		glRotatef(180.0, 1.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 1.0);
		glutSolidCone(m_radius * 2, m_radius * 10, 8, 8);
	}
	glPopMatrix();
}

void CBulletObject::UpdatePos() {
	switch (m_state) {
	case INIT:
		m_time = 0;
		m_isVisible = false;
		m_isMoving = false;
		m_position = m_player->Pos();
		m_eulerAngle = m_player->EulerAngle();
		//cout << m_position.z << endl;
		break;

	case UPDATE:
		++m_time;
		m_isVisible = true;
		m_isMoving = true;
		MoveObject(this);
		if (m_time > m_thresholdTime) {
			m_state = INIT;
		}
		break;
	default:
		break;
	}
}