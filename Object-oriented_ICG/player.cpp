#include <iostream>
#include "player.h"
#include "platform.h"

using namespace std;

//コンストラクタ
CPlayerObject::CPlayerObject(Vector3 *pos, Vector3 *eulerAngle, float radius, float speed, float turn, int maxHP, Vector3 *col) {
	//ローカル変数の初期化
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

	//弾インスタンス生成
	m_bullets.resize(m_bulletNum);
	for (int i = 0; i < m_bulletNum; ++i) {
		m_bullets[i] = new CBulletObject(&m_position, new Vector3(0, 0, 0), 0.05, new Vector3(1.0, 1.0, 0.0), 0.3, 10, 300, this);
	}
}
//デストラクタ
CPlayerObject::~CPlayerObject() {
	//弾配列のメモリ開放
	vector<ABulletBase*>().swap(m_bullets);
}

void CPlayerObject::DrawObj() {
	if (!m_isVisible)return;
	
	glPushMatrix();
	{
		this->SetMaterialColor(this);
		glTranslatef(0, 0, -0.5);
		glRotatef(0.0, 0.0, 1.0, 0.0);
		glRotatef(0.0, 1.0, 0.0, 0.0);
		glRotatef(0.0, 0.0, 0.0, 1.0);
		glutSolidSphere(m_radius, 18, 16);
	}
	glPopMatrix();

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

void CPlayerObject::Attack() {
	m_bullets[m_currBullet]->Pos(m_position);
	m_bullets[m_currBullet]->State(UPDATE);
	++m_currBullet;
	if (m_currBullet == m_bulletNum)m_currBullet = 0;
}