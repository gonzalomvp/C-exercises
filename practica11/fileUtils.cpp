#include "stdafx.h"
#pragma warning( disable : 4710)

#include "fileUtils.h"
#include "file.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"

unsigned int NFileUtils::countStringsInFile(const char *fileName, const char *string)
{
	assert(fileName);
	assert(string);
	unsigned int ret = 0;

	void *file = NFile::OpenFile(fileName, "r");

	if (file)
	{
		//Se crea un buffer del tamaño definido por la constante
		char buffer[BUFFER_SIZE];

		//longitud de la cadena que se busca
		unsigned int stringLength = strlen(string);

		//contador de caracteres coincidentes de la cadena
		unsigned int matchedChars = 0;
		
		//bytes que se han leido de fichero
		unsigned int bytesRead = 0;

		//bytes desplazados al comienzo cuando se llega al final del buffer
		unsigned int movedBytes = 0;

		//La primera vez leera el tamaño del bloque completo
		bytesRead = NFile::ReadFile(file, buffer, BUFFER_SIZE);
		while (bytesRead)
		{
			//indice para recorrer el buffer buscando coincidencias
			unsigned int bufferIndex = 0;

			//hay que comprobar tantos bytes como la suma de los leidos más los movidos en la iteracion anterior
			unsigned int bytesToCheck = bytesRead + movedBytes;

			//repito hasta que que el indice apunta una posicion del buffer donde ya no cabría la cadena
			while (bufferIndex + stringLength <= bytesToCheck)
			{
				//si el caracter coincide sumo uno al contador y sigo comparando
				if (buffer[bufferIndex + matchedChars] == string[matchedChars])
				{
					matchedChars++;
					//si han coincidido tantos caracteres como la longitud de la cadena ha habido un match
					if (matchedChars == stringLength)
					{
						ret++;
						bufferIndex = bufferIndex + matchedChars;
						matchedChars = 0;
					}

				}

				//si los caracteres no coinciden reseteo el contador y empiezo a comparar desde el siguiente caracter del buffer
				else
				{
					matchedChars = 0;
					bufferIndex++;
				}
			}
			
			//Los bytes que quedan por comprobar se mueven al principio del buffer antes de volver a leer
			movedBytes = 0;
			while (bufferIndex < bytesToCheck)
			{
				buffer[movedBytes] = buffer[bufferIndex];
				movedBytes++;
				bufferIndex++;
			}

			//Las siguientes lecturas de fichero descontarán los bytes desplazados.
			bytesRead = NFile::ReadFile(file, buffer + movedBytes, BUFFER_SIZE - movedBytes);
		}

		NFile::CloseFile(file);
	}
	return ret;
}

int NFileUtils::sumIntsInFile(const char *fileName)
{
	assert(fileName);
	int ret = 0;

	void *file = NFile::OpenFile(fileName, "r");

	if (file)
	{
		//Se crea un buffer del tamaño definido por la constante
		char buffer[BUFFER_SIZE];

		//Buffer para procesar el int. Se añade un char al final para meter un '\0' durante el procesamiento 
		char integer[INT_CHARS + 1] = {'\0'};

		//indice para recorrer el integer durante el procesado
		unsigned int integerIndex = 0;

		//almacena los bytes que se han leido de fichero
		unsigned int bytesRead = 0;

		bytesRead = NFile::ReadFile(file, buffer, BUFFER_SIZE);
		while (bytesRead)
		{
			//indice para recorrer el buffer
			unsigned int bufferIndex = 0;

			//repito hasta que llego al final del buffer leido
			while (bufferIndex < bytesRead)
			{
				//Si el caracter no es una ',' lo añado al buffer para procesar el int
				if (buffer[bufferIndex] != ',')
				{
					integer[integerIndex] = buffer[bufferIndex];
					integerIndex++;
				}
				else
				{
					//Si el caracter es una ',' añado un '\0' al final del int y lo proceso
					integer[integerIndex] = '\0';
					ret += atoi(integer);
					integerIndex = 0;
				}
				bufferIndex++;
			}
			bytesRead = NFile::ReadFile(file, buffer, BUFFER_SIZE);
		}

		//Si el último int del fichero no tiene una "," al final no se ha procesado asi que lo hago ahora
		integer[integerIndex] = '\0';
		ret += atoi(integer);

		NFile::CloseFile(file);
	}
	return ret;
}

void NFileUtils::getListFromFile(const char *fileName, TList &list)
{
	assert(fileName);


	void *file = NFile::OpenFile(fileName, "r");

	if (file)
	{
		//Se crea un buffer del tamaño definido por la constante
		char buffer[BUFFER_SIZE];

		//Buffer para procesar el int. Se añade un char al final para meter un '\0' durante el procesamiento 
		char integer[INT_CHARS + 1] = { '\0' };

		//indice para recorrer el integer durante el procesado
		unsigned int integerIndex = 0;

		//almacena los bytes que se han leido de fichero
		unsigned int bytesRead = 0;

		bytesRead = NFile::ReadFile(file, buffer, BUFFER_SIZE);
		while (bytesRead)
		{
			//indice para recorrer el buffer
			unsigned int bufferIndex = 0;

			//repito hasta que llego al final del buffer leido
			while (bufferIndex < bytesRead)
			{
				//Si el caracter no es una ',' lo añado al buffer para procesar el int
				if (buffer[bufferIndex] != ',')
				{
					integer[integerIndex] = buffer[bufferIndex];
					integerIndex++;
				}
				else
				{
					//Si el caracter es una ',' añado un '\0' al final del int y lo proceso
					integer[integerIndex] = '\0';
					list.Push(integer);
					integerIndex = 0;
				}
				bufferIndex++;
			}
			bytesRead = NFile::ReadFile(file, buffer, BUFFER_SIZE);
		}

		//Si el último int del fichero no tiene una "," al final no se ha procesado asi que lo hago ahora
		integer[integerIndex] = '\0';
		list.Push(integer);

		NFile::CloseFile(file);
	}
}