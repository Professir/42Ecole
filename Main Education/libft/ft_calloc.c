#include "libft.h"

void *calloc(size_t num, size_t size)
{
    void *rcal;

    rcal = malloc(num * size);
    if (!(rcal = malloc(num * size)))
        return (0);
    ft_bzero(rcal, size * num);
    return (rcal);
}