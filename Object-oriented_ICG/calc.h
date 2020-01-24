#include <math.h>
#include <stdlib.h>
#include "object.h"

//▼ベクトル
//typedef struct {
//	float x, y, z;
//} Vector3;
//▼オイラー角による回転の表現
typedef struct {
	float roll, pitch, yaw;
} euler_t;

void DirectionAtoB( AObjectBase *a, AObjectBase *b, Vector3 *dir );
//float VectorNorm( Vector3 *v );
float DistanceAtoB( AObjectBase *a, AObjectBase *b );
float VectorToPolar( Vector3 *v,  euler_t *angle );
float EulerAtoB( AObjectBase *a, AObjectBase *b, euler_t *angle );
//void MoveObject( ObjDataT *obj );

//bool HasHit(AObjectBase *a, ObjDataT *b);
float uniformRandom(float min, float max);


