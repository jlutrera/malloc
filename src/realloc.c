#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    if (!ptr)
        return malloc(size);

    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    t_block *b = (t_block *)ptr - 1;

    if (b->size >= size)
        return ptr;

    void *new = malloc(size);
    if (!new)
        return NULL;

    size_t copy = (b->size < size) ? b->size : size;
    for (size_t i = 0; i < copy; i++)
        ((char *)new)[i] = ((char *)ptr)[i];

    free(ptr);
    return new;
}
