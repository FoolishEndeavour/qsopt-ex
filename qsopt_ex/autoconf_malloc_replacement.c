
/*
This file exists as a workaround to defines inserted by autoconf.
*/
#include <config.h>
#undef malloc
#undef realloc

#include <sys/types.h>

void *malloc (size_t);
void *realloc (void*, size_t);

/* Allocate an N-byte block of memory from the heap.
   If N is zero, allocate a 1-byte block.  */

void *
rpl_malloc (size_t n)
{
  if (n == 0)
    n = 1;
  return malloc (n);
}

void *
rpl_realloc (void* p, size_t n)
{
  if (n == 0)
    n = 1;
  return realloc (p, n);
}
