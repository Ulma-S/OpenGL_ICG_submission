#ifndef INCLUDED_player_h_
#define INCLUDED_player_h_

#include <iostream>
#include <vector>
#include "bullet.h"

using namespace std;

class CPlayerObject : public AMovableObject{
private:
	int m_bulletNum = 20;
	int m_currBullet = 0;
	vector<ABulletBase*> m_bullets;
public:
	//移動速度、回転速度、最大HP、色
	CPlayerObject(Vector3 *pos, Vector3 *eulerAngle, float radius, float speed, float turn, int maxHP, Vector3 *col);
	~CPlayerObject();
	void DrawObj() override;
	void Attack();

	//Getter, Setter
	inline int BulletNum() { return m_bulletNum; }
	inline vector<ABulletBase*> Bulllets() { return m_bullets; }
};

#endif
