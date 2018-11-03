#include "stdafx.h"
#pragma warning( disable : 4710)

#include "IFileUtils.h"
#include "fileUtils.h"


unsigned int IFileUtils::countStringsInFile(const char *fileName, const char *string)
{
	
	return NFileUtils::countStringsInFile(fileName, string);
}

int IFileUtils::sumIntsInFile(const char *fileName)
{
	
	return NFileUtils::sumIntsInFile(fileName);
}