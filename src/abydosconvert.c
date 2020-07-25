#include "abydosconvert.h"

#include <abydos.h>

void abydosconvert(void)
{		
	char outputFilePath[16384];
	abydos_t * ar;
    const char * basename = strrchr(gConfig.inputFilePath, '/');
    basename = basename ? basename+1 : gConfig.inputFilePath;

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

	abydos_info_t info;
	abydos_get_info(ar, &info);
	printf("{ \"width\" : %d", info.width);
	printf(", \"height\" : %d", info.height);
	printf(", \"scalable\" : %s", info.features&ABYDOS_FEATURE_SCALABLE_SIZE ? "true" : "false");
	printf(", \"animated\" : %s", abydos_can_animate(ar) ? "true" : "false");
	printf(", \"pages\" : %d", abydos_get_page_count(ar));
	printf(", \"layers\" : %d", abydos_get_layer_count(ar));
	printf(", \"variants\" : %d", abydos_get_variant_count(ar));
	printf(", \"frames\" : %d", abydos_get_frame_count(ar));
	printf(", \"scalableTime\" : %s }\n", info.features&ABYDOS_FEATURE_SCALABLE_TIME ? "true" : "false");

	if(info.features&ABYDOS_FEATURE_SCALABLE_SIZE || abydos_can_animate(ar))
	{
		if(info.features&ABYDOS_FEATURE_SCALABLE_SIZE)
		{
			sprintf(outputFilePath, "%s/%s.svg", gConfig.outputDirPath, basename);
			abydos_write_to_svg(ar, outputFilePath);
		}

		if(abydos_can_animate(ar))
		{
			sprintf(outputFilePath, "%s/%s.webp", gConfig.outputDirPath, basename);
			abydos_write_to_webp(ar, outputFilePath);
		}
	}
	else
	{
		sprintf(outputFilePath, "%s/%s.png", gConfig.outputDirPath, basename);
		abydos_write_to_png(ar, outputFilePath);
	}
	
    return;
}
