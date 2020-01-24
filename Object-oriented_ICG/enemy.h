#ifndef INCLUDED_enemy_h_
#define INCLUDED_enemy_h_

#include "object.h"

class CEnemyObject : public AMovableObject{
private:
	AObjectBase *m_target;
public:
	CEnemyObject(Vector3 *pos, Vector3 *eulerAngle, float radius, float speed, float turn, int maxHP, Vector3 *col, AObjectBase *target);
	void DrawObj() override;
	void UpdatePos() override;
	void Neutralize() override;
};

#endif // !INCLUDED_enemy_h_
