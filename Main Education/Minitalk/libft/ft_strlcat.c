#include "libft.h"

size_t strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t d;
    size_t s;
    size_t max;

    max = ft_strlen(dst)
    s = ft_strlen(src);
    d = ft_strlen(dst);
    if (d >= dize)
        return (s + size);
    i = 0;
    while (max < size - 1 && src[i])
    {
        dest[max] = src[i];
        i++;
        max++;
    }
    dest[max] = '\0';
    return (d + s);
}