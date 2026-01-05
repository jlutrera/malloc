#include "malloc.h"
#include <stdio.h>

extern t_zone *g_zones;

void show_alloc_mem(void)
{
    t_zone *z = g_zones;

    while (z)
    {
        printf("Zone %p - size %zu\n", z, z->size);

        t_block *b = z->blocks;
        while (b)
        {
            printf("  Block %p - size %zu - %s\n",
                b, b->size, b->free ? "free" : "used");
            b = b->next;
        }
        z = z->next;
    }
}
