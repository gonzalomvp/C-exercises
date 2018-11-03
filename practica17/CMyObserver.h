#pragma once

#include "IObserver.h"

class CMyObserver : public IObserver
{

public:
	virtual void onReadEnd();

};