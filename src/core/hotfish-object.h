/*-------------------------------------------------------------------------*/
/* HotFish - An application toolkit for embedded systems.
 *
 * Copyright (c) 2011, 2012, 2013, 2014, Lucky Green Frog, LLC
 *
 * Maintainer:
 *
 */
/*-------------------------------------------------------------------------*/

#ifndef COM_LUCKYGREENFROG_HF_OBJECT_H_
#define COM_LUCKYGREENFROG_HF_OBJECT_H_

HF_DECLS_BEGIN

/* typedef for the object */
typedef struct _HFObject HFObject;
typedef const struct _HFObject* HFObjectRef;

/* alloc and init functions */
HFObject*   HFObjectAlloc(void);
HFObject*   HFObjectAllocInit(hf_type_t isa, hf_id_t id);
void        HFObjectInit(hf_voptr vself, hf_type_t isa, hf_id_t id);
void        HFObjectObjFuncsInit(hf_voptr vself);

/* type functions */
hf_type_t   HFObjectIsa(hf_voptr vself);
void        HFObjectSetIsa(hf_voptr vself, hf_type_t isa);
hf_id_t     HFObjectId(hf_voptr vself);
void        HFObjectSetId(hf_voptr vself, hf_id_t id);

/* member declaration */
#define HF_OBJECT_MEMBERS_DECLARE \
    void (*Destroy) (hf_voptr vself); \
    hf_type_t       _isa; \
    hf_id_t         _id;

/* substitutive functions */
void HFObjectDestroy(hf_voptr vself);

/* object declaration */
struct _HFObject
{
    HF_OBJECT_MEMBERS_DECLARE
};

HF_DECLS_END

#endif  /* COM_LUCKYGREENFROG_HF_OBJECT_H_ */

