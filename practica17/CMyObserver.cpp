#include "stdafx.h"

#include "CMyObserver.h"

void CMyObserver::onReadEnd()
{
	printf("La lectura asincrona ha finalizado\n");
}