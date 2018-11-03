#pragma once

#include "IElement.h"
#include "TListNode.h"

struct TList
{
	//Constructor
	TList();

	//Constructor de copia
	TList(const TList &src);

	//Destructor
	~TList();

	int Size() const;
	int Push(IElement* element);
	IElement* First();
	IElement* Next();
	IElement* Pop();
	void Reset();

	void printList() const;

private:
	int m_size;
	TListNode* pNodeFirst;
	TListNode* pNodeCurrent;
	TListNode* pNodeLast;

	void Init();
};
