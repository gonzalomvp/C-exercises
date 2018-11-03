#pragma once

#include "CStream.h"

class CFile : public CStream
{

public:
	virtual int Open();
	virtual int Close();
	virtual int Read();
	virtual int Write();

};