#ifndef __ABYDOSCONVERT_H
#define __ABYDOSCONVERT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "version.h"

/*-----------------------------------------------------------------------------
 * Constants
 *----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 * Data types
 *----------------------------------------------------------------------------*/
typedef struct
{
	bool verbose;
	char * mimeType;
	char * inputFilePath;
	char * outputFilePath;
} Config;

/*-----------------------------------------------------------------------------
 * Globals
 *----------------------------------------------------------------------------*/
extern Config gConfig;

/*-----------------------------------------------------------------------------
 * Macros
 *----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
 * Functions prototypes
 *----------------------------------------------------------------------------*/

// abydosconvert.c
void abydosconvert(void);

#endif
