#ifndef INCLUDED_heal_h_
#define INCLUDED_heal_h_

#include "object.h"

class CHealObject : public AObjectBase {
private:
	float m_healValue;
	AMovableObject *m_target;
public:
	//�ʒu, �p�x, ���a, �F, �񕜗�, �^�[�Q�b�g
	CHealObject(Vector3 *pos, Vector3 *eulerAngle, float radius, Vector3 *col, float healValue, AMovableObject *target);
	void DrawObj() override;
	void Heal();
};

#endif // !INCLUDED_heal_h_
