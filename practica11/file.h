#pragma once

namespace NFile{

void * OpenFile(const char *fileName, const char *mode);
int CloseFile(void *file);
unsigned int ReadFile(void *file, char *buffer, unsigned int n);
unsigned int WriteFile(void *file, const char *buffer, unsigned int n);

}