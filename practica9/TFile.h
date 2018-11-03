#pragma once

struct TFile
{
	static const unsigned int FILE_ERROR = 0xFFFFFFFF;
	static const unsigned int NAME_SIZE = 256;

	//Constructor
	TFile(const char *fileName);

	//Destructor
	~TFile();

	//Utilidades
	unsigned int OpenFile(const char *mode);
	unsigned int CloseFile();
	unsigned int ReadFile(char *buffer, unsigned int n);
	unsigned int WriteFile(const char *buffer, unsigned int n);

private:
	//Puntero al fichero
	void *m_file;

	//Nombre del fichero
	char *m_fileName;
};