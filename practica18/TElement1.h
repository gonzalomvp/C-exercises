#pragma once

#include "IElement.h"

struct TElement1 : public IElement
{
	int m_i;

	TElement1(int i);
	virtual void PrintElement();

};