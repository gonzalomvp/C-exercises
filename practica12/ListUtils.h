#pragma once

#include "TList.h"

namespace ListUtils
{
	TList GetReverseList(TList lstSrc);
	void GetReverseListEnhanced(const TList &lstSrc, TList &lstDest);

	void invertString(const char *stringSrc, unsigned int lenght, char *stringDest);
}