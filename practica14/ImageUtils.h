#pragma once

#include "Imagen.h"

namespace ImageUtils
{
	void removePNGsAlphaChannel(CImagen* const* imagenes, unsigned int size);
}