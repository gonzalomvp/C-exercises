#pragma once

const unsigned short BUFFER_SIZE = 256;

//El maximo numero de caracteres que puede tener un int teniendo en cuenta el signo es 11 "–2147483648"
const unsigned short INT_CHARS = 11;

unsigned int countStringsInFile(const char *fileName, const char *string);
int sumIntsInFile(const char *fileName);