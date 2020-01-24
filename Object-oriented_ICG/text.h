#include "object.h"

#ifndef INCLUDED_text_h_
#define INCLUDED_text_h_


class CTextObject : public AObjectBase {
public:
	CTextObject();
	~CTextObject();
	void DrawObj() override;
	void DrawString(float x, float y, float xscl, float yscl,
		void *font, const char *string);
};

#endif // !INCLUDED_text_h_
