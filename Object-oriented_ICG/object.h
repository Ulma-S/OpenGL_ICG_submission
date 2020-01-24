#ifndef INCLUDED_object_h_
#define INCLUDED_object_h_

#include "vector.h"
#include "platform.h"
#define RADIAN M_PI/180.0

//▼すべての描画オブジェクトの基底クラス
class AObjectBase {
protected:
	Vector3 m_position;		//位置
	Vector3 m_eulerAngle;	//オイラー角
	float m_radius;			//半径
	Vector3 m_color;		//色 (RGB)
	bool m_isVisible;		//可視状態

public:
	void SetObjTransform(AObjectBase *obj);
	void SetMaterialColor(AObjectBase *obj);
	virtual void DrawObj() = 0;	//描画
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

//▼移動可能なオブジェクトにはこちらを継承
class AMovableObject : public AObjectBase {
protected:
	float m_speed;		//移動速度
	float m_turn;		//角速度
	bool m_isMoving;	//移動状態
	float m_currHP;		//現在のHP
	float m_maxHP;		//最大HP
	

public:
	void MoveObject(AMovableObject *obj);	//移動
	//位置の更新 (毎フレームsim.cpp/UpdateScene()で呼ぶ)
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