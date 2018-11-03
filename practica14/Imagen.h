#pragma once

#include "stdafx.h"

class CImagen
{
public:
	enum ImageType
	{
		Unknown,
		Png,
		Jpg,
	};
	
	CImagen();
	~CImagen();

	int										SetImageFile				(const char *pszFile);
	unsigned int					GetNumPixels				() const;
	unsigned int					GetUncompressedSize	() const;
	const unsigned char *	GetBuffer						() const;
	int										Draw								() const;
	int										InvertImage					();
	ImageType getType() const;

protected:
	unsigned int		m_uResX;
	unsigned int		m_uResY;
	unsigned int		m_uColorBytes;
	unsigned char *	m_pBuffer;
	unsigned int		m_uSize;
	ImageType type;
};