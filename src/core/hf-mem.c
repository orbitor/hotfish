/*-------------------------------------------------------------------------*/
/* HotFish - An application toolkit for embedded systems.
 *
 * Copyright (c) 2011, 2012, 2013, 2014, Lucky Green Frog, LLC
 *
 * Maintainer:
 *
 */
/*-------------------------------------------------------------------------*/

#include "HotFish.h"

#include <stdlib.h>

void* hf_malloc(size_t size)
{
    return malloc(size);
}

void hf_free(void* ptr)
{
    free(ptr);
}

