#include "stdafx.h"

#include "TList.h"
#include "TListNode.h"
#include "IElement.h"

TList::TList()
{
	Init();
}

TList::TList(const TList &src)
{
	Init();

	TListNode* node = src.pNodeFirst;
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
}

TList::~TList()
{
	Reset();
}

int TList::Size() const
{
	return m_size;
}

int TList::Push(IElement* element)
{
	TListNode *nodeToAdd = new TListNode(element);
	if (m_size == 0)
	{
		pNodeFirst = nodeToAdd;
		pNodeCurrent = nodeToAdd;
	}
	else
	{
		pNodeLast->m_next = nodeToAdd;
	}

	pNodeLast = nodeToAdd;

	m_size++;
	return m_size;
}

IElement* TList::First()
{
	IElement* ret = nullptr;

	if (pNodeFirst) {
		ret = pNodeFirst->m_element;
		pNodeCurrent = pNodeFirst;
	}

	return ret;
}

IElement* TList::Next()
{
	IElement* ret = nullptr;

	if (pNodeCurrent)
	{
		TListNode* next = pNodeCurrent->m_next;
		if (next)
		{
			ret = next->m_element;
			pNodeCurrent = next;
		}

	}
	return ret;
}

IElement* TList::Pop()
{
	IElement* ret = nullptr;

	if (pNodeFirst) {
		TListNode* pNodeToDelete = pNodeFirst;
		ret = pNodeToDelete->m_element;
		pNodeFirst = pNodeToDelete->m_next;
		pNodeCurrent = pNodeToDelete->m_next;
		delete pNodeToDelete;
		m_size--;
	}

	return ret;
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

void TList::printList() const
{
	TListNode* node = pNodeFirst;

	printf("Size: %d\n",m_size);
	while (node)
	{
		node->m_element->PrintElement();
		node = node->m_next;
	}
}