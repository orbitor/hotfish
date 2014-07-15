/*-------------------------------------------------------------------------*/
/* HotFish - An application toolkit for embedded systems.
 *
 * Copyright (c) 2011, 2012, 2013, 2014, Lucky Green Frog, LLC
 *
 * Maintainer:
 *
 */
/*-------------------------------------------------------------------------*/

#ifndef COM_LUCKYGREENFROG_HF_CONTAINER_H_
#define COM_LUCKYGREENFROG_HF_CONTAINER_H_

#include "hotfish-object.h"

/* typedef for the object */
typedef struct _HFContainer HFContainer;

/* There are no Alloc functions because this object is (sort of) 'virtual' */
/* Init functions */
void    HFContainer_Init(void);
void    HFContainer_InitWithCapacity(size_t capacity);

/* type functions */
size_t  HFContainer_inflateSize(const HFContainer* container) const;
bool    HFContainer_mayInflate(const HFContainer* container) const;
bool    HFContainer_ownsEntries(const HFContainer* container) const;
size_t  HFContainer_size(const HFContainer* container) const;
bool    HFContainer_isFull(const HFContainer* container) const;
bool    HFContainer_isEmpty(const HFContainer* container) const;

void    HFContainer_setInflateSize(HFContainer* container, size_t size);
void    HFContainer_setMayInflate(HFContainer* container, bool may_inflate);
void    HFContainer_setOwnsEntries(HFContainer* container, bool owns_entries);
void    HFContainer_setSize(HFContainer* container, size_t size);

/* member declaration */
#define HF_CONTAINER_MEMBERS_DECLARE \
    HF_OBJECT_MEMBERS_DECLARE \
    size_t      _size; \
    size_t      _inflate_size; \
    size_t      _capacity; \
    bool        _may_inflate; \
    bool        _owns_entries; \
    bool        _is_empty; \
    bool        _is_full;

#endif  /* COM_LUCKYGREENFROG_HF_CONTAINER_H_ */

