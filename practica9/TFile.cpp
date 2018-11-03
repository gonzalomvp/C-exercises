#include "stdafx.h"

#include "TFile.h"
#include "stdio.h"
#include "assert.h"
#include "string.h"

TFile::TFile(const char *fileName)
{
	assert(fileName);

	m_file = nullptr;
	m_fileName = new char[NAME_SIZE];
	strcpy_s(m_fileName, NAME_SIZE, fileName);
}

TFile::~TFile()
{
	CloseFile();
	delete []m_fileName;
}

unsigned int TFile::OpenFile(const char *mode)
{
	assert(mode);
	
	unsigned int ret = FILE_ERROR;
	FILE *pFile;

	if (!m_file && fopen_s(&pFile, m_fileName, mode) == 0) {
		m_file = pFile;
		ret = 0;
	}

	return ret;
}

unsigned int TFile::CloseFile()
{
	unsigned int ret = FILE_ERROR;
	if (m_file && fclose(static_cast<FILE *>(m_file)) == 0)
	{
		ret = 0;
		m_file = nullptr;
	}

	return ret;
}

unsigned int TFile::ReadFile(char *buffer, unsigned int n)
{
	assert(buffer);

	unsigned int ret = FILE_ERROR;
	if (m_file)
	{
		unsigned int readBytes = fread(buffer, sizeof(char), n, static_cast<FILE *>(m_file));
		if (readBytes > 0)
		{
			ret = readBytes;
		}
	}

	return ret;
}

unsigned int TFile::WriteFile(const char *buffer, unsigned int n)
{
	assert(buffer);

	unsigned int ret = FILE_ERROR;
	if (m_file)
	{
		unsigned int readBytes = fwrite(buffer, sizeof(char), n, static_cast<FILE *>(m_file));
		if (readBytes > 0)
		{
			ret = readBytes;
		}
	}

	return ret;
}