/*-------------------------------------------------------------------------*/
/* HotFish - An application toolkit for embedded systems.
 *
 * Copyright (c) 2011, 2012, 2013, 2014, Lucky Green Frog, LLC
 *
 * Maintainer:
 *
 */
/*-------------------------------------------------------------------------*/

#ifndef COM_LUCKYGREENFROG_HF_ARRAY_H_
#define COM_LUCKYGREENFROG_HF_ARRAY_H_

#include "HotFish.h"

HF_DECLS_BEGIN

/* typedef for the object */
typedef const struct __HFArray* HFArrayRef;
typedef struct __HFArray* HFMutableArrayRef;

typedef void (*HFArrayApplierFunction)(const void* value, void* context);

HFArrayRef  HFArrayCreate(HFTypeRef*);
HFArrayRef  HFArrayCreateCopy(HFArrayRef arrayRef);

HFMutableArrayRef HFArrayCreateMutable();
HFMutableArrayRef HFArrayCreateMutableCopy(HFArrayRef arrayRef);

void HFArrayApplyFunction(HFArrayRef array, HFApplyFunction func);
void HFArrayApplyFunctionOverRange(HFArrayRef arrayRef, HFArrayApplierFunction func, HFRange range);


HFArray*    HFArray_AllocInit(void);
HFArray*    HFArray_AllocInitWithArray(HFArray* array);
HFArray*    HFArray_AllocInitWithObjects(const hf_voptr objects, int count);

void        HFArray_Init(HFArray *self);
void        HFArray_ObjFuncsInit(hf_voptr vself);

/* type functions */

/* member declaration */
#define HF_ARRAY_MEMBERS_DECLARE \
    HR_CONTAINER_MEMBERS_DECLARE \
    HFObject**  _array; \
    bool        _is_finalized; \
    bool        _is_sorted; \
    bool        _is_compacted;

/* object declaration */
struct _HFArray
{
    HF_OBJECT_MEMBERS_DECLARE
};

HF_DECLS_END

#endif  /* COM_LUCKYGREENFROG_HF_ARRAY_H_ */

