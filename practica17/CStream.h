#pragma once

#include "IObserver.h"

class CStream
{

public:
	virtual int Open() = 0;
	virtual int Close() = 0;
	virtual int Read() = 0;
	virtual int Write() = 0;

	virtual void AsyncRead(IObserver *pObserver) = 0;

};