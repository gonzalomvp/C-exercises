
#include "stdafx.h"

#include "ListUtils.h"
#include "string.h"

TList ListUtils::GetReverseList(TList lstSrc)
{
	TList ret;
	TNode *node = lstSrc.pNodeFirst;
	char *invertedString = new char[BUFFER_SIZE];
	unsigned int maxLength = BUFFER_SIZE - 1;

	while (node)
	{
		const char *string = node->m_element;
		unsigned int length = strlen(string);
		
		//Se incrementa el tamaño del buffer si es necesario
		if (length > maxLength)
		{
			delete[] invertedString;
			invertedString = new char[length + 1];
			maxLength = length;
		}

		invertString(string, length, invertedString);
		ret.Push(invertedString);

		node = node->m_next;
	}

	delete[] invertedString;

	return ret;
}

void ListUtils::GetReverseListEnhanced(const TList &lstSrc, TList &lstDest)
{
	TNode *node = lstSrc.pNodeFirst;
	char *invertedString = new char[BUFFER_SIZE];
	unsigned int maxLength = BUFFER_SIZE - 1;

	lstDest.Reset();

	while (node)
	{
		const char *string = node->m_element;
		unsigned int length = strlen(string);

		//Se incrementa el tamaño del buffer si es necesario
		if (length > maxLength)
		{
			delete[] invertedString;
			invertedString = new char[length + 1];
			maxLength = length;
		}

		invertString(string, length, invertedString);
		lstDest.Push(invertedString);

		node = node->m_next;
	}

	delete[] invertedString;
}

void ListUtils::invertString(const char *stringSrc, unsigned int length, char *stringDest)
{
	for (unsigned int i = 0; i < length; i++)
	{
		*(stringDest + i) = *(stringSrc + length - 1 - i);
	}

	*(stringDest + length) = *(stringSrc + length);
}