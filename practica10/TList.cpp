#include "stdafx.h"
#pragma warning( disable : 4710)

#include "TList.h"

// *******************************************************
// TList Class
// *******************************************************
TList::TList()
{
	m_size = 0;
	pNodeFirst = nullptr;
	pNodeCurrent = nullptr;
	pNodeLast = nullptr;
}

TList::~TList()
{
	Reset();
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

const char  *TList::Pop()
{
	const char *ret = nullptr;

	if (pNodeFirst) {
		TListNode *nodeToDelete = pNodeFirst;
		ret = nodeToDelete->m_element;
		pNodeFirst = nodeToDelete->m_next;
		pNodeCurrent = pNodeFirst;
		delete nodeToDelete;
		m_size--;
	}
	return ret;
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
	m_element = element;
	m_next = nullptr;
}