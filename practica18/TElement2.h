#pragma once

#include "IElement.h"

struct TElement2 : public IElement
{
	const char *m_cadena;

	TElement2(const char *cadena);
	virtual void PrintElement();

};