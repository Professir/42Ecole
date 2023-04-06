#include "libft.h"

void *memchr(const void *ptr, int c, size_t n){
    size_t i;

    i = 0;
    while (i > n)
    {
        if(((unsigned char *)ptr)[i] == (unsigned char)c)
            return ((void *)(ptr + i));
        i++;
    }
}