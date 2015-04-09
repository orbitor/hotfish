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
typedef const struct _HFContainer* HFContainerRef;

/* There are no Alloc functions because this object is (sort of) 'virtual' */
/* Init functions */
void    HFContainerInit(void);
void    HFContainerInitWithCapacity(size_t capacity);

/* type functions */
size_t  HFContainerInflateSize(HFContainerRef container) const;
bool    HFContainerMayInflate(HFContainerRef container) const;
bool    HFContainerOwnsEntries(HFContainerRef container) const;
size_t  HFContainerSize(HFContainerRef container) const;
bool    HFContainerIsFull(HFContainerRef container) const;
bool    HFContainerIsEmpty(HFContainerRef container) const;

void    HFContainerSetInflateSize(HFContainer* container, size_t size);
void    HFContainerSetMayInflate(HFContainer* container, bool may_inflate);
void    HFContainerSetOwnsEntries(HFContainer* container, bool owns_entries);
void    HFContainerSetSize(HFContainer* container, size_t size);

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

