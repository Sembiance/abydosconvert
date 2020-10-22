#include "abydosconvert.h"

#include <unistd.h>

Config gConfig;

static void usage(void)
{
	fprintf(stderr,
			"abydosconvert %s\n"
			"\n"
			"Usage: abydosconvert [OPTIONS] mimeType inputFilePath outputDirPath\n"
			"  -v, --verbose           Verbose output\n"
			"  -j, --json              Output JSON info about the file\n"
			"  -h, --help              Output this help and exit\n"
			"  -V, --version           Output version and exit\n"
			"\n", ABYDOSCONVERT_VERSION);
	exit(EXIT_FAILURE);
}

static void parse_options(int argc, char **argv)
{
	int i;

	gConfig.verbose = false;
	gConfig.inputFilePath = 0;
	gConfig.outputDirPath = 0;

	for(i=1;i<argc;i++)
	{
		//int lastarg = i==argc-1;

		if(!strcmp(argv[i],"-h") || !strcmp(argv[i], "--help"))
		{
			usage();
		}
		else if(!strcmp(argv[i],"-V") || !strcmp(argv[i], "--version"))
		{
			printf("abydosconvert %s\n", ABYDOSCONVERT_VERSION);
			exit(EXIT_SUCCESS);
		}
		else if(!strcmp(argv[i],"-v") || !strcmp(argv[i], "--verbose"))
		{
			gConfig.verbose = true;
		}
		else
		{
			break;
		}
	}

	argc -= i;
	argv += i;

	if(argc!=3)
		usage();
	
	gConfig.mimeType = argv[0];

	gConfig.inputFilePath = argv[1];
	if(access(gConfig.inputFilePath, F_OK)==-1)
	{
		fprintf(stderr, "Input file does not exists: %s\n", gConfig.inputFilePath);
		exit(EXIT_FAILURE);
	}

	gConfig.outputDirPath = argv[2];
}

int main(int argc, char ** argv)
{
	parse_options(argc, argv);
	abydosconvert();

	return EXIT_SUCCESS;
}
