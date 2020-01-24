#include "collision_detector.h"
#include "calc.h"

bool UCollisionDetector::TriggerStay(AObjectBase *self, AObjectBase *target) {
	if (DistanceAtoB(self, target) <= self->Radius() + target->Radius()) {
		return true;
	}
	return false;
}
