#include "stdafx.h"
#pragma warning( disable : 4710)

#include "TList.h"
#include "TNode.h"
#include "string.h"

TList::TList()
{
	Init();
}

TList::TList(const TList &src)
{
	Init();

	TNode *node = src.pNodeFirst;
	while (node)
	{
		this->Push(node->m_element);
		node = node->m_next;
	}
}

void TList::Init()
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
	delete[]lastPop;
}

int TList::Size() const
{
	return m_size;
}

int TList::Push(const char *psz)
{
	TNode *node = new TNode(psz);

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
		TNode *next = pNodeCurrent->m_next;
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
		TNode *nodeToDelete = pNodeFirst;
		unsigned int length = strlen(nodeToDelete->m_element);
		if (length > lastPopMaxLength)
		{
			delete[]lastPop;
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
	pNodeFirst = nullptr;
	pNodeCurrent = nullptr;
	pNodeLast = nullptr;
}