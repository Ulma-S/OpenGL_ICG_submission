#ifndef INCLUDED_vector_h_
#define INCLUDED_vector_h_
#define _USE_MATH_DEFINES

#include <math.h>

class Vector3 {
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(float x, float y, float z);

	//演算子のオーバーロード
	Vector3& operator = (const Vector3& v);
	Vector3& operator += (const Vector3& v);
	Vector3& operator -= (const Vector3& v);
	Vector3& operator *= (const float f);
	Vector3& operator /= (const float f);
	Vector3 operator + () const;
	Vector3 operator - () const;
	bool operator == (const Vector3& v) const;
	bool operator != (const Vector3& v) const;

	//長さ
	float Norm() const;
	//正規化
	void Normalize();
};

Vector3 operator + (const Vector3& v1, const Vector3& v2);
Vector3 operator - (const Vector3& v1, const Vector3& v2);
Vector3 operator * (const Vector3& v, const float f);
Vector3 operator * (const float f, const Vector3& v);
Vector3 operator / (const Vector3& v, const float f);
//内積
float operator * (const Vector3& v1, const Vector3& v2);
//外積
Vector3 operator ^ (const Vector3& v1, const Vector3& v2);
//なす角
float Angle(const Vector3& v1, const Vector3& v2);

//----------------------------------------------------------------------
//メンバ関数の実装
inline Vector3::Vector3() { x = y = z = 0; }
inline Vector3::Vector3(float x, float y, float z) {
	this->x = x;	this->y = y;	this->z = z;
}

inline Vector3& Vector3::operator = (const Vector3& v) {
	this->x = v.x;	this->y = v.y;	this->z = v.z;
	return *this;
}

inline Vector3& Vector3::operator += (const Vector3& v) {
	this->x += v.x;	this->y += v.y;	this->z += v.z;
	return *this;
}

inline Vector3& Vector3::operator -= (const Vector3& v) {
	this->x -= v.x;	this->y -= v.y;	this->z -= v.z;
	return *this;
}

inline Vector3& Vector3::operator *= (const float f) {
	this->x *= f;	this->y *= f;	this->z *= f;
	return *this;
}

inline Vector3& Vector3::operator /= (const float f) {
	this->x /= f;	this->y /= f;	this->z /= f;
	return *this;
}

inline Vector3 Vector3::operator + () const {
	return *this;
}

inline Vector3 Vector3::operator - () const {
	return Vector3(-x, -y, -z);
}

inline bool Vector3::operator == (const Vector3& v) const {
	return (x == v.x) && (y == v.y) && (z == v.z);
}

inline bool Vector3::operator != (const Vector3& v) const {
	return !(*this == v);
}

inline float Vector3::Norm() const {
	return pow(x*x + y * y + z * z, 0.5);
}

inline void  Vector3::Normalize() {
	*this /= Norm();
}
//-----------------------------------------------------------------
//グローバル関数の実装
inline Vector3 operator + (const Vector3& v1, const Vector3& v2) {
	Vector3 t;
	t.x = v1.x + v2.x;
	t.y = v1.y + v2.y;
	t.z = v1.z + v2.z;
	return t;
}

inline Vector3 operator - (const Vector3& v1, const Vector3& v2) {
	Vector3 t;
	t.x = v1.x - v2.x;
	t.y = v1.y - v2.y;
	t.z = v1.z - v2.z;
	return t;
}

inline Vector3 operator * (const Vector3& v, const float f) {
	Vector3 t;
	t.x = v.x * f;
	t.y = v.y * f;
	t.z = v.z * f;
	return t;
}

inline Vector3 operator * (const float f, const Vector3& v) {
	Vector3 t;
	t.x = v.x * f;
	t.y = v.y * f;
	t.z = v.z * f;
	return t;
}

inline Vector3 operator / (const Vector3& v, const float f) {
	Vector3 t;
	t.x = v.x / f;
	t.y = v.y / f;
	t.z = v.z / f;
	return t;
}

//内積
inline float operator * (const Vector3& v1, const Vector3& v2) {
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

//外積
inline Vector3 operator ^ (const Vector3& v1, const Vector3& v2) {
	Vector3 t;
	t.x = v1.y*v2.z - v1.z*v2.y;
	t.y = v1.z*v2.x - v1.x*v2.z;
	t.z = v1.x*v2.y - v1.y*v2.x;
	return t;
}

//なす角
inline float Angle(const Vector3& v1, const Vector3& v2) {
	float cos = v1 * v2 / (v1.Norm()*v2.Norm());
	return acos(cos)/M_PI*180;
}

#endif // !INCLUDED_vector_h_
