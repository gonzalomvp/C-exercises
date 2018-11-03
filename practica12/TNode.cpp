#include "stdafx.h"

#include "TNode.h"
#include "string.h"

TNode::TNode(const char *element)
{
	unsigned int length = strlen(element);
	m_element = new char[length + 1];
	strcpy_s(m_element, length + 1, element);
	m_next = nullptr;
}

TNode::~TNode()
{
	delete []m_element;
}