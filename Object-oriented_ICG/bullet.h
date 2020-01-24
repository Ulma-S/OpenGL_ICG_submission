#include "object.h"

#ifndef INCLUDED_bullet_h_
#define INCLUDED_bullet_h_

enum EBulletState {
	INIT,
	UPDATE,
};

class ABulletBase : public AMovableObject {
protected:
	float m_damageValue;
	EBulletState m_state;	//0:wait, 1:execute, 2:reset
	AMovableObject *m_player;
	int m_time = 0;
	int m_thresholdTime;
public:
	void Damage(AMovableObject *target);

	//Getter, Setter
	inline float DamageValue() { return m_damageValue; }
	inline void DamageValue(float value) { m_damageValue = value; }
	inline EBulletState State() { return m_state; }
	inline void State(EBulletState value) { m_state = value; }
};

class CBulletObject : public ABulletBase {
public:
	CBulletObject() {}
	//位置(player), 角度, 色, ダメージ量, 残存時間
	CBulletObject(Vector3 *pos, Vector3 *eulerAngle, float radius, Vector3* col, float speed, float damage, int thresholdTime, AMovableObject *player);
	void DrawObj() override;
	void UpdatePos() override;
};

#endif // !INCLUDED_bullet_h_
