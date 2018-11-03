#pragma once

#include "TNode.h"

const unsigned int BUFFER_SIZE = 256;

struct TList
{
	int m_size;
	TNode *pNodeFirst;
	TNode *pNodeCurrent;
	TNode *pNodeLast;

	//Constructor
	TList();

	//Constructor de copia
	TList(const TList &src);

	//Destructor
	~TList();

	int Size() const;
	int Push(const char *psz);
	const char *First();
	const char *Next();
	const char *Pop();
	void Reset();

private:
	char *lastPop;
	unsigned int lastPopMaxLength;

	void Init();
};
