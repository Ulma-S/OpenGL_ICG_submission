#define _USE_MATH_DEFINES
#include <math.h>
#include "sim.h"
#include "calc.h"
#include "vector.h"
#include "object.h"

//float PI = 3.14159;
//float RADIANS = M_PI / 180.0;
float DEGREE = 180.0 / M_PI;

//▼オブジェクトaからオブジェクトbへの方向ベクトルを求める関数
//オブジェクト間の方向ベクトル
void DirectionAtoB(AObjectBase *a, AObjectBase *b, Vector3 *dir)
{
	dir->x = b->Pos().x - a->Pos().x;
	dir->y = b->Pos().y - a->Pos().y;
	dir->z = b->Pos().z - a->Pos().z;
}
//▼ベクトルの大きさを計算する関数
//ベクトルの大きさ
//float VectorNorm(Vector3 *v)
//{
//	return sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
//}
//▼距離を求める関数（「衝突判定」で作った関数の別バージョン）
//オブジェクト間距離
float DistanceAtoB(AObjectBase *a, AObjectBase *b)
{
	Vector3 v;
	DirectionAtoB(a, b, &v);
	return v.Norm();
}
//▼方向ベクトルから方位角と仰角を求める関数
float VectorToPolar(Vector3 *v, euler_t *angle)
{
	float d = sqrtf(v->x * v->x + v->z * v->z);
	angle->pitch = DEGREE * atan2f(v->y, d);
	angle->yaw = DEGREE * atan2f(-v->x, -v->z);
	return v->Norm();
}
//▼
float EulerAtoB(AObjectBase *a, AObjectBase *b, euler_t *angle)
{
	Vector3 dir;
	DirectionAtoB(a, b, &dir);
	VectorToPolar(&dir, angle);
	return dir.Norm();
}
////▼備考：構造体へのポインタを引数としている
//void MoveObject(ObjDataT *obj)
//{
//	obj->yaw += obj->turn;
//	obj->position.x -= obj->move * sinf(obj->yaw * RADIAN);
//	obj->position.z -= obj->move * cosf(obj->yaw * RADIAN);
//}

//
//bool HasHit(ObjDataT *a, ObjDataT *b) {
//	if (DistanceAtoB(a, b) <= a->radius + b->radius) {
//		return true;
//	}
//	return false;
//}

float uniformRandom(float min, float max) {
	double r;
	r = (double)rand() / (double)RAND_MAX;
	r = r * (max - min) + min;
	return r;
}