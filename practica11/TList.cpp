#include "stdafx.h"
#pragma warning( disable : 4710)

#include "TList.h"
#include "string.h"

// *******************************************************
// TList Class
// *******************************************************
TList::TList()
{
	m_size = 0;
	pNodeFirst = nullptr;
	pNodeCurrent = nullptr;
	pNodeLast = nullptr;
	lastPop = new char[BUFFER_SIZE];
	lastPopMaxLength = BUFFER_SIZE - 1;
	lastPop[0] = NULL;
}

TList::~TList()
{
	Reset();
	delete []lastPop;
}

int TList::Size()
{
	return m_size;
}

int TList::Push(const char *psz)
{
	TListNode *node = new TListNode(psz);

	if (m_size == 0)
	{
		pNodeFirst = node;
		pNodeCurrent = node;
	}
	else
	{
		pNodeLast->m_next = node;
	}

	pNodeLast = node;

	m_size++;
	return m_size;
}

const char *TList::First()
{
	const char *ret = nullptr;

	if (pNodeFirst) {
		ret = pNodeFirst->m_element;
		pNodeCurrent = pNodeFirst;
	}

	return ret;
}

const char *TList::Next()
{
	const char *ret = nullptr;

	if (pNodeCurrent)
	{
		TListNode *next = pNodeCurrent->m_next;
		if (next)
		{
			ret = next->m_element;
			pNodeCurrent = next;
		}

	}
	return ret;
}

const char *TList::Pop()
{
	if (pNodeFirst) {
		TListNode *nodeToDelete = pNodeFirst;
		unsigned int length = strlen(nodeToDelete->m_element);
		if (length > lastPopMaxLength)
		{
			delete []lastPop;
			lastPop = new char[length + 1];
			lastPopMaxLength = length;
		}
		strcpy_s(lastPop, length + 1, nodeToDelete->m_element);
		pNodeFirst = nodeToDelete->m_next;
		pNodeCurrent = pNodeFirst;
		delete nodeToDelete;
		m_size--;
	}
	else
	{
		lastPop[0] = NULL;
	}

	return lastPop;
}

void TList::Reset()
{
	while (pNodeFirst) {
		Pop();
	}
}

// *******************************************************
// TListNode Class
// *******************************************************

TListNode::TListNode(const char *element)
{
	unsigned int length = strlen(element);
	m_element = new char[length + 1];
	strcpy_s(m_element, length + 1, element);
	m_next = nullptr;
}

TListNode::~TListNode()
{
	delete []m_element;
}