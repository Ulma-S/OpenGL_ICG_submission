#include "object.h"
#include <iostream>

using namespace std;

void AObjectBase::SetObjTransform(AObjectBase* obj) {
	glTranslatef(obj->m_position.x, obj->m_position.y, obj->m_position.z);
	glRotatef(obj->m_eulerAngle.y, 0.0, 1.0, 0.0);
	glRotatef(obj->m_eulerAngle.x, 1.0, 0.0, 0.0);
	glRotatef(obj->m_eulerAngle.z, 0.0, 0.0, 1.0);
}

void AObjectBase::SetMaterialColor(AObjectBase *obj) {
	float diffuse[4];
	float specular[] = { 0.8, 0.8, 0.8, 1.0 };

	diffuse[0] = m_color.x;
	diffuse[1] = m_color.y;
	diffuse[2] = m_color.z;
	diffuse[3] = 1.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 32.0);
}

void AObjectBase::Neutralize() {
	m_isVisible = false;
}

void AObjectBase::Destroy() {
	delete this;
}

void AMovableObject::MoveObject(AMovableObject *obj) {
	obj->m_eulerAngle.y += obj->m_turn;
	obj->m_position.x -= obj->m_speed * sinf(obj->m_eulerAngle.y * RADIAN);
	obj->m_position.z -= obj->m_speed * cosf(obj->m_eulerAngle.y * RADIAN);
}

void AMovableObject::UpdatePos() {
	if (m_isMoving)MoveObject(this);
}