#include "libft.h"

size_t ft_strlen(const char *str){
    size_t a;

    a = 0;
    while (*str != '\0')
        a++;
    return (a);
}