#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <stddef.h>
# include "../libft/include/libft.h"

# define TINY_MAX   64
# define SMALL_MAX  1024

typedef struct s_block
{
    size_t              size;
    int                 free;
    struct s_block     *next;
}   t_block;

typedef struct s_zone
{
    size_t              size;
    struct s_zone      *next;
    t_block            *blocks;
}   t_zone;

void    *malloc(size_t size);
void    free(void *ptr);
void    *realloc(void *ptr, size_t size);
void    show_alloc_mem(void);

#endif
