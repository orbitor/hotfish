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
#include "hotfish-object.h"

#define HF_ASSERT_TO_SELF() \
    HF_ASSERT(vself); \
    HFObject* self = (HFObject*) vself;

/* alloc and init functions */
HFObject* HFObjectAlloc(void)
{
    HFObject* obj = hf_malloc(sizeof(HFObject));
    return obj;
}

HFObject* HFObjectAllocInit(hf_type_t isa, hf_id_t id)
{
    HFObject* obj = HFObjectAlloc();
    HF_ASSERT(obj);

    HFObjectInit(obj, isa, id);

    return obj;
}

void HFObjectInit(hf_voptr vself, hf_type_t isa, hf_id_t id)
{
    HF_ASSERT_TO_SELF();
    self->_isa = isa;
    self->_id = id;
    HFObjectObjFuncsInit(self);
}

void HFObjectObjFuncsInit(hf_voptr vself)
{
    HF_ASSERT_TO_SELF();
    self->Destroy = HFObjectDestroy;
}

/* type functions */
hf_type_t HFObjectIsa(hf_voptr vself)
{
    HF_ASSERT_TO_SELF();
    return self->_isa;
}

void HFObjectSetIsa(hf_voptr vself, hf_type_t isa)
{
    HF_ASSERT_TO_SELF();
    self->_isa = isa;
}

hf_id_t HFObjectId(hf_voptr vself)
{
    HF_ASSERT_TO_SELF();
    return self->_id;
}

void HFObjectSetId(hf_voptr vself, hf_id_t id)
{
    HF_ASSERT_TO_SELF();
    self->_id = id;
}

/* substitutive functions */
void HFObjectDestroy(hf_voptr vself)
{
    hf_free(vself);
}

