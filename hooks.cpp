#include "hooks.h"
#include "malloc.h"
#include <stdio.h>
#include <execinfo.h>

#define PRINT_TRACE
void print_trace();

static malloc_hook_t old_malloc_hook;
static free_hook_t old_free_hook;
static realloc_hook_t old_realloc_hook;

static void *my_malloc_hook (size_t, const void *);
static void my_free_hook (void*, const void *);
static void *my_realloc_hook (void *ptr, size_t size, const void *caller);

static inline void save_old_hook() {
  old_malloc_hook = __malloc_hook;
  old_free_hook = __free_hook;
  old_realloc_hook = __realloc_hook;
}

static inline void set_our_hook() {
  __malloc_hook = my_malloc_hook;
  __free_hook = my_free_hook;
  __realloc_hook = my_realloc_hook;
}

static inline void restore_old_hook() {
    __malloc_hook = old_malloc_hook;
    __free_hook = old_free_hook;
    __realloc_hook = old_realloc_hook;
}

void init_hook () {
    save_old_hook();
    set_our_hook();
}



static void * my_malloc_hook (size_t size, const void *caller) {
  void *result;
  /* Restore all old hooks */
  restore_old_hook();
  /* Call recursively */
  result = malloc (size);
  /* Save underlying hooks */
  save_old_hook();
  /* printf might call malloc, so protect it too. */
  printf ("malloc (%u) returns %p, Caller %p\n", (unsigned int) size, result, caller);
  print_trace();
  /* Restore our own hooks */
  set_our_hook();
  return result;
}

static void *my_realloc_hook (void *ptr, size_t size, const void *caller) {
  void *result;
  /* Restore all old hooks */
  restore_old_hook();
  /* Call recursively */
  result = realloc(ptr, size);
  /* Save underlying hooks */
  save_old_hook();
  /* printf might call malloc, so protect it too. */
  printf ("realloc (%p, %u) returns %p, Caller %p\n", ptr, (unsigned int) size, result, caller);
  print_trace();
  /* Restore our own hooks */
  set_our_hook();
  return result;
}

static void my_free_hook (void *ptr, const void *caller) {
  /* Restore all old hooks */
  restore_old_hook();
  /* Call recursively */
  free (ptr);
  /* Save underlying hooks */
  save_old_hook();
  /* printf might call free, so protect it too. */
  printf ("freed pointer %p, Caller %p\n", ptr, caller);
  print_trace();
  /* Restore our own hooks */
  set_our_hook();
}


//Adding backtrace
//Refer to  https://www.gnu.org/software/libc/manual/html_node/Backtraces.html
void print_trace() {
#ifdef PRINT_TRACE
    char **strings;
    size_t i, size;
    enum Constexpr { MAX_SIZE = 1024 };
    void *array[MAX_SIZE];
    size = backtrace(array, MAX_SIZE);
    strings = backtrace_symbols(array, size);
    for (i = 0; i < size; i++)
        printf("%s\n", strings[i]);
    puts("");
    free(strings);
#endif
}