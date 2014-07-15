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

#include "hotfish-container.h"

/* typedef for the object */
typedef struct _HFArray HFArray;

/* alloc and init functions */
HFArray*    HFArray_Alloc(void);
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

#endif  /* COM_LUCKYGREENFROG_HF_ARRAY_H_ */

