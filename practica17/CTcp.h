#pragma once

#include "CStream.h"

class CTcp : public CStream
{

public:
	virtual int Open();
	virtual int Close();
	virtual int Read();
	virtual int Write();

	virtual void AsyncRead(IObserver *pObserver);

};