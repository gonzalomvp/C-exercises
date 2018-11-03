#include "stdafx.h"

#include "CCom.h"
#include "windows.h"

int CCom::Open()
{
	printf("CCom Open()\n");
	return 0;
}

int CCom::Close()
{
	printf("CCom Close()\n");
	return 0;
}

int CCom::Read()
{
	printf("CCom Read()\n");
	return 0;
}

int CCom::Write()
{
	printf("CCom Write()\n");
	return 0;
}

void CCom::AsyncRead(IObserver *pObserver)
{
	printf("Leyendo puerto serie...\n");
	Sleep(2000);
	printf("Puerto serie leido\n");

	if (pObserver)
	{
		pObserver->onReadEnd();
	}
}
