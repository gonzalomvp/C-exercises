#include "stdafx.h"

#include "CFile.h"
#include "windows.h"

int CFile::Open()
{
	printf("CFile Open()\n");
	return 0;
}

int CFile::Close()
{
	printf("CFile Close()\n");
	return 0;
}

int CFile::Read()
{
	printf("CFile Read()\n");
	return 0;
}

int CFile::Write()
{
	printf("CFile Write()\n");
	return 0;
}

void CFile::AsyncRead(IObserver *pObserver)
{
	printf("Leyendo fichero...\n");
	Sleep(5000);
	printf("Fichero leido\n");

	if (pObserver)
	{
		pObserver->onReadEnd();
	}
}

