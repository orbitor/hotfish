/*-------------------------------------------------------------------------*/
/* HotFish - An application toolkit for embedded systems.
 *
 * Copyright (c) 2011, 2012, 2013, 2014, Lucky Green Frog, LLC
 *
 * Maintainer:
 *
 */
/*-------------------------------------------------------------------------*/

#ifndef HF_OBJECT_H_
#define HF_OBJECT_H_

/* typedef for the object */
typedef struct _HfObject HfObject;

/* alloc and init functions */
HfObject*   HfObjectAlloc(void);
HfObject*   HfObjectAllocInit(hf_type_t isa, hf_id_t id);
void        HfObjectInit(hf_voptr vself, hf_type_t isa, hf_id_t id);
void        HfObjectObjFuncsInit(hf_voptr vself);

/* type functions */
hf_type_t   HfObjectIsa(hf_voptr vself);
void        HfObjectIsaSet(hf_voptr vself, hf_type_t isa);
hf_id_t     HfObjectId(hf_voptr vself);
void        HrObjectIdSet(hf_voptr vself, hf_id_t id);

/* member declaration */
#define HF_OBJECT_MEMBERS_DECLARE \
    void (*Destroy) (hf_voptr vself); \
    hf_type_t _isa; \
    hf_id_t _id;

/* substitutive functions */
void HfObjectDestroy(hf_voptr vself);

/* object declaration */
struct _HfObject
{
    HF_OBJECT_MEMBERS_DECLARE
};

#endif  /* HF_OBJECT_H_ */

