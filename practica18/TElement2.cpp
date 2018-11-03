#include "stdafx.h"

#include "TElement2.h"

TElement2::TElement2(const char *cadena)
{
	m_cadena = cadena;
}

void TElement2::PrintElement()
{
	printf("TElement2: %s\n", m_cadena);
}