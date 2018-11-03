#include "stdafx.h"

#include "utils.h"

short int intToShort(int i)
{
	short int ret = static_cast<short int>(i);

	if (i > MAX_SHORT)
	{
		ret = MAX_SHORT;
	}
	else if (i < MIN_SHORT)
	{
		ret = MIN_SHORT;
	}
	return ret;
}