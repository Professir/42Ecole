#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n){
    size_t i;

    if (!dest || !src)
        return (NULL);
    if (dest > src){    
        i = size_t(n - 1);
        while (i >= 0)
        {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i--;
        }
    }
    else{
        i = 0;
        while (i < n){
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dest);
}