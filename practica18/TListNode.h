#pragma once

#include "IElement.h"

struct TListNode
{
	IElement* m_element;
	TListNode* m_next;

	TListNode();
	TListNode(IElement *element);
};