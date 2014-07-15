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

/* typedef for the object */
typedef struct _HFObject HFObject;

/* alloc and init functions */
HFObject*   HFObject_Alloc(void);
HFObject*   HFObject_AllocInit(hf_type_t isa, hf_id_t id);
void        HFObject_Init(hf_voptr vself, hf_type_t isa, hf_id_t id);
void        HFObject_ObjFuncsInit(hf_voptr vself);

/* type functions */
hf_type_t   HFObject_Isa(hf_voptr vself);
void        HFObject_IsaSet(hf_voptr vself, hf_type_t isa);
hf_id_t     HFObject_Id(hf_voptr vself);
void        HFObject_IdSet(hf_voptr vself, hf_id_t id);

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

#endif  /* COM_LUCKYGREENFROG_HF_OBJECT_H_ */

