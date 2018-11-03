#include "Imagen.h"

class CPng : public CImagen
{
public:
	CPng::CPng();

	int SetPngFile(const char *pszFile);
	void RemoveAlphaChannel();

private:
	int UncompressImage();
};