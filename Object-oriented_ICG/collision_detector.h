#ifndef INCLUDED_collision_detector_h_
#define INCLUDED_collision_detector_h_

#include "object.h"

//���Փˌ��o�N���X (Singleton)
class UCollisionDetector {
private:
	//bool m_onTriggerEnter = false;
	UCollisionDetector() = default;	//�R���X�g���N�^
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
