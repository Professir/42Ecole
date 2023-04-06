#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size){
    size_t i;
    size_t srcsize;

    srcsize = ft_strlen(src)
    if (!dst || !src)
		return (0);
    i = 0;
    if (size != 0){
        while (size > i){
            (unsigned char *(dest))[i] = ((unsigned char *)src)[i];
             i++;
        }
        dest[i] = '\0';
    }
    return (srcsize);
}