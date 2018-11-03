#include "stdafx.h"

#include "ImageUtils.h"
#include "Jpg.h"
#include "Png.h"


void ImageUtils::removePNGsAlphaChannel(CImagen* const* imagenes, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		CImagen *imagen = imagenes[i];

		if (imagen->getType() == CImagen::Png)
		{
			CPng *png = static_cast<CPng*>(imagen);
			png->RemoveAlphaChannel();
		}

	}
}