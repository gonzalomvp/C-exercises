#include "Imagen.h"

class CJpg : public CImagen
{
public:
	CJpg::CJpg();

	int SetJpgFile(const char *pszJpgFile);

private:
	int UncompressImage();
};