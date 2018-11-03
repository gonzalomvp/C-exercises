#pragma once

const unsigned int BUFFER_SIZE = 256;

struct TListNode
{
	//Constructor
	TListNode(const char *element);

	//Destructor
	~TListNode();

	char *m_element;
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
	char *lastPop;
	unsigned int lastPopMaxLength;
};
