#ifndef INCLUDED_collision_detector_h_
#define INCLUDED_collision_detector_h_

#include "object.h"

//▼衝突検出クラス (Singleton)
class UCollisionDetector {
private:
	//bool m_onTriggerEnter = false;
	UCollisionDetector() = default;	//コンストラクタ
	~UCollisionDetector() = default;
public:
	static UCollisionDetector& GetInstance() {
		static UCollisionDetector instance;
		return instance;
	}
	bool TriggerStay(AObjectBase *self, AObjectBase *target);
	///bool TriggerEnter(AObjectBase *self, AObjectBase *target);
};

#endif // !INCLUDED_collision_detector_h_
