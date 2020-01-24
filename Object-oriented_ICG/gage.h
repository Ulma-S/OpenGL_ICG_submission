#include "object.h"

#ifndef INCLUDED_gage_h_
#define INCLUDED_gage_h_

class CHPGage : public AMovableObject {
private:
	float m_hpValue;
	AMovableObject *m_target;
public:
	CHPGage(AMovableObject *target, Vector3 *col);
	void DrawObj()override;
};

#endif // !INCLUDED_gage_h_
