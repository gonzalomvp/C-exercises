#include "stdafx.h"

#include "TElement1.h"

TElement1::TElement1(int i)
{
	m_i = i;
}

void TElement1::PrintElement()
{
	printf("TElement1: %d\n", m_i);
}