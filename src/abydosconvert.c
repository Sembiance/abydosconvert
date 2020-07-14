#include "abydosconvert.h"

#include <abydos.h>
#include <cairo.h>

void abydosconvert(void)
{		
	abydos_t * ar;
	cairo_surface_t * surface;

	ar = abydos_create(gConfig.mimeType);
	if(!ar)
	{
		fprintf(stderr, "Failed to create buffer for mime type: %s\n", gConfig.mimeType);
		exit(EXIT_FAILURE);
	}

	if(abydos_from_file(ar, gConfig.inputFilePath)!=0)
	{
		fprintf(stderr, "Failed to load input file: %s\n", gConfig.inputFilePath);
		exit(EXIT_FAILURE);
	}

	//surface = abydos_get_image_surface(ar, ABYDOS_PREFER_SHARE | ABYDOS_IGNORE_ASPECT_RATIO);
	surface = abydos_get_image_surface(ar);
	abydos_destroy(ar);

	if(cairo_surface_write_to_png(surface, gConfig.outputFilePath)!=CAIRO_STATUS_SUCCESS)
	{
		fprintf(stderr, "Failed to write to output file: %s\n", gConfig.outputFilePath);
		cairo_surface_destroy(surface);
		exit(EXIT_FAILURE);
	}
	
	cairo_surface_destroy(surface);
	
    return;
}