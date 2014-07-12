
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

