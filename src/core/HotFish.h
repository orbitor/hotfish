/*-------------------------------------------------------------------------*/
/* HotFish - An application toolkit for embedded systems.
 *
 * Copyright (c) 2011, 2012, 2013, 2014, Lucky Green Frog, LLC
 *
 * Maintainer:
 *
 */
/*-------------------------------------------------------------------------*/

#ifndef HOT_FISH_H_
#define HOT_FISH_H_

#ifdef __cplusplus
#   define HF_DECLS_BEGIN   extern "C" {
#   define HF_DECLS_END     }
#else
#   define HF_DECLS_BEGIN
#   define HF_DECLS_END
#endif  /* __cplusplus */

#include <stdint.h>

typedef uint32_t hf_id_t;
typedef uint16_t hf_type_t;

typedef int hf_ret_t;

typedef void* hf_voptr;

#include <assert.h>
#define HF_ASSERT(_x)   assert(_x);

#include <stddef.h>     /* size_t */

HF_DECLS_BEGIN

void* hf_malloc(size_t size);
void hf_free(void* ptr);

HF_DECLS_END

#endif  /* HOT_FISH_H_ */

