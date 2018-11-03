#pragma once

struct TListNode
{
	//Constructor
	TListNode(const char *element);

	const char *m_element;
	TListNode *m_next;
};

struct TList
{
	//Constructor
	TList();

	//Destructor
	~TList();

	int Size();
	int Push(const char *psz);
	const char *First();
	const char *Next();
	const char *Pop();
	void Reset();

private: 
	int m_size;
	TListNode *pNodeFirst;
	TListNode *pNodeCurrent;
	TListNode *pNodeLast;
};
