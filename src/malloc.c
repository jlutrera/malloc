#include "malloc.h"

static t_zone *g_zones = NULL;

static t_zone *create_zone(size_t size)
{
    size_t total = sizeof(t_zone) + size;
    t_zone *zone = mmap(NULL, total,
                        PROT_READ | PROT_WRITE,
                        MAP_ANON | MAP_PRIVATE, -1, 0);
    if (zone == MAP_FAILED)
        return NULL;

    zone->size = total;
    zone->next = NULL;
    zone->blocks = (t_block *)(zone + 1);

    zone->blocks->size = size - sizeof(t_block);
    zone->blocks->free = 1;
    zone->blocks->next = NULL;

    return zone;
}

static t_block *find_free_block(t_zone *zone, size_t size)
{
    t_block *b = zone->blocks;
    while (b)
    {
        if (b->free && b->size >= size)
            return b;
        b = b->next;
    }
    return NULL;
}

void *malloc(size_t size)
{
    if (size == 0)
        return NULL;

    size_t alloc_size = size;

    if (!g_zones)
        g_zones = create_zone(4096);

    t_zone *z = g_zones;
    t_block *b = find_free_block(z, alloc_size);

    if (!b)
        return NULL;

    b->free = 0;
    return (void *)(b + 1);
}
