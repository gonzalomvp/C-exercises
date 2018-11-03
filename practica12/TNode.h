#pragma once

struct TNode
{
	char *m_element;
	TNode *m_next;

	//Constructor
	TNode(const char *element);

	//Destructor
	~TNode();
};