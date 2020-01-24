#ifndef INCLUDED_object_h_
#define INCLUDED_object_h_

#include "vector.h"
#include "platform.h"
#define RADIAN M_PI/180.0

//�����ׂĂ̕`��I�u�W�F�N�g�̊��N���X
class AObjectBase {
protected:
	Vector3 m_position;		//�ʒu
	Vector3 m_eulerAngle;	//�I�C���[�p
	float m_radius;			//���a
	Vector3 m_color;		//�F (RGB)
	bool m_isVisible;		//�����

public:
	void SetObjTransform(AObjectBase *obj);
	void SetMaterialColor(AObjectBase *obj);
	virtual void DrawObj() = 0;	//�`��
	virtual void Neutralize();
	virtual void Destroy();

	//Getter, Setter
	inline Vector3 Pos() const { return m_position; }
	inline void Pos(const Vector3& value) { m_position = value; }
	inline Vector3 EulerAngle() const { return m_eulerAngle; }
	inline void EulerAngle(const Vector3& value) { m_eulerAngle = value; }
	inline float Radius() const { return m_radius; }
	inline void Radius(const float value) { m_radius = value; }
	inline Vector3 Color() const { return m_color; }
	inline void Color(const Vector3& value) { m_color = value; }
	inline bool IsVisible() const { return m_isVisible; }
	inline void IsVisible(const bool value) { m_isVisible = value; }
};

//���ړ��\�ȃI�u�W�F�N�g�ɂ͂�������p��
class AMovableObject : public AObjectBase {
protected:
	float m_speed;		//�ړ����x
	float m_turn;		//�p���x
	bool m_isMoving;	//�ړ����
	float m_currHP;		//���݂�HP
	float m_maxHP;		//�ő�HP
	

public:
	void MoveObject(AMovableObject *obj);	//�ړ�
	//�ʒu�̍X�V (���t���[��sim.cpp/UpdateScene()�ŌĂ�)
	virtual void UpdatePos();

	//Getter, Setter
	inline float Speed() const { return m_speed; }
	inline void Speed(const float value) { m_speed = value; }
	inline float Turn() const { return m_turn; }
	inline void Turn(const float value) { m_turn = value; }
	inline bool IsMoving() const { return m_isMoving; }
	inline void IsMoving(const bool value) { m_isMoving = value; }
	inline float CurrHP() const { return m_currHP; }
	inline void CurrHP(const float value) { m_currHP = value; }
	inline float MaxHP() const { return m_maxHP; }
	inline void MaxHP(const float value) { m_maxHP = value; }
};

#endif