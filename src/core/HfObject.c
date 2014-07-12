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
#include "HfObject.h"

#define HF_ASSERT_TO_SELF() \
    HF_ASSERT(vself); \
    HfObject* self = (HfObject*) vself;

/* alloc and init functions */
HfObject* HfObjectAlloc(void)
{
    HfObject* obj = hf_malloc(sizeof(HfObject));
    return obj;
}

HfObject* HfObjectAllocInit(hf_type_t isa, hf_id_t id)
{
    HfObject* obj = HfObjectAlloc();
    HF_ASSERT(obj);

    HfObjectInit(obj, isa, id);

    return obj;
}

void HfObjectInit(hf_voptr vself, hf_type_t isa, hf_id_t id)
{
    HF_ASSERT_TO_SELF();
    self->_isa = isa;
    self->_id = id;
    HfObjectObjFuncsInit(self);
}

void HfObjectObjFuncsInit(hf_voptr vself)
{
    HF_ASSERT_TO_SELF();
    self->Destroy = HfObjectDestroy;
}

/* type functions */
hf_type_t HfObjectIsa(hf_voptr vself)
{
    HF_ASSERT_TO_SELF();
    return self->_isa;
}

void HfObjectIsaSet(hf_voptr vself, hf_type_t isa)
{
    HF_ASSERT_TO_SELF();
    self->_isa = isa;
}

hf_id_t HfObjectId(hf_voptr vself)
{
    HF_ASSERT_TO_SELF();
    return self->_id;
}

void HrObjectIdSet(hf_voptr vself, hf_id_t id)
{
    HF_ASSERT_TO_SELF();
    self->_id = id;
}

/* substitutive functions */
void HfObjectDestroy(hf_voptr vself)
{
    hf_free(vself);
}

