// practica8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning( disable : 4710)
#include "file.h"
#include "IFileUtils.h"

int main()
{
	const unsigned int n = 100;
	char buffer[n];

	//Prueba File
	void * file1 = NFile::OpenFile("test.txt", "r");

	unsigned int readBytes = NFile::ReadFile(file1, buffer, n);
	printf("Bytes leidos: %d\n", readBytes);
	printf("Cadena leida: %.*s\n", readBytes, buffer);

	printf("Resultado de cerrar el fichero:%d\n", NFile::CloseFile(file1));

	file1 = NFile::OpenFile("test2.txt", "w");
	printf("Bytes escritos: %d\n", NFile::WriteFile(file1, buffer, readBytes));
	printf("Resultado de cerrar el fichero:%d\n", NFile::CloseFile(file1));

	//Prueba FileUtils
	printf("%d\n", IFileUtils::countStringsInFile("test.txt", "non"));
	printf("%d\n", IFileUtils::sumIntsInFile("ints.txt"));

	getchar();
	return 0;
}

