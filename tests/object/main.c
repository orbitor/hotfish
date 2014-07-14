
#include "HotFish.h"
#include "hotfish-object.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
    HfObject* obj = HfObjectAlloc();
    HfObjectInit(obj, 32, 104329);

    printf("HfObject %p\tisa %u\tid %u\n",
            obj,
            obj->_isa,
            obj->_id);

    printf("sizeof HfObject: %lu\n",
            sizeof(*obj));

    obj->Destroy(obj);
    obj = NULL;
    HfObjectDestroy(obj);
}

