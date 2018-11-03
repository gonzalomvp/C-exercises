#pragma once

class CStream
{

public:
	virtual int Open();
	virtual int Close();
	virtual int Read();
	virtual int Write();

};