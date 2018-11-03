#include "stdafx.h"

#include "file.h"
#include "stdio.h"
#include "assert.h"


void * OpenFile(const char *fileName, const char *mode)
{
	assert(fileName);
	assert(mode);

	FILE *pFile;
	fopen_s(&pFile, fileName, mode);
	return pFile;
}

int CloseFile(void *file)
{
	assert(file);
	return fclose(static_cast<FILE *>(file));
}

unsigned int ReadFile(void *file, char *buffer, unsigned int n)
{
	assert(file);
	assert(buffer);
	return fread(buffer, sizeof(char), n, static_cast<FILE *>(file));
}

unsigned int WriteFile(void *file, const char *buffer, unsigned int n)
{
	assert(file);
	assert(buffer);
	return fwrite(buffer, sizeof(char), n, static_cast<FILE *>(file));
}