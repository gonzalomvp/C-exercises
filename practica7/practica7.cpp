// practica7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4710)

#include "practica7.h"
#include "stdio.h"
#include "string.h"

int main()
{
	char fileName[BUFFER_SIZE];
	strcpy_s(fileName, BUFFER_SIZE, "fuente1.cpp");
	printHeaders(fileName, 0);
	getchar();
	return 0;
}

void printHeaders(char *fileName, unsigned int level)
{
	FILE *pFile;

	fopen_s(&pFile,fileName, "r");
	if (pFile) {
		while (fgets(fileName, BUFFER_SIZE, pFile))
		{
			if (strstr(fileName, "#include"))
			{

				char* token = NULL;
				char* context = NULL;
				
				token = strtok_s(fileName, DELIMS, &context);
				token = strtok_s(NULL, DELIMS, &context);
				for (unsigned int i = 0; i < level; i++)
				{
					printf("\t");
				}
				printf("%s\n", token);
				printHeaders(token, level + 1);
			}
		}
		fclose(pFile);
	}
}
