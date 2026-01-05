#include "malloc.h"

void free(void *ptr)
{
    if (!ptr)
        return;

    t_block *b = (t_block *)ptr - 1;
    b->free = 1;
}
