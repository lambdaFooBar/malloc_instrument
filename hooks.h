#ifndef HOOKS_H_

#include <cstdio>

typedef void* (*malloc_hook_t) (size_t size, const void *caller);
typedef void* (*realloc_hook_t) (void *ptr, size_t size, const void *caller);

typedef void (*free_hook_t) (void *ptr, const void *caller);

typedef void* (*memalign_hook_t) (size_t alignment, size_t size, const void *caller);

void init_hook ();

#endif