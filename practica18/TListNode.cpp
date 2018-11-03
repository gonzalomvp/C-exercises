#include "stdafx.h"

#include "TListNode.h"

TListNode::TListNode()
{
	m_element = nullptr;
	m_next = nullptr;
}

TListNode::TListNode(IElement *element)
{
	m_element = element;
	m_next = nullptr;
}