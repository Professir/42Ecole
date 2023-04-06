#include "libft.h"

void *ft_memset(void *dest, int c, size_t n){
    size_t i;

    i = 0;
    while (i < n)
    {
        ((unsigned char *)dest)[i] = c;
        i++;
    }
    return (dest);
}