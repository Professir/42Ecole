#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char)){
    size_t i;
    size_t len;

    i = 0;
    len = 0;
    if (!s || !f)
        return (NULL);
    len = ft_strlen(s);
    while (len > i){
        f(i, s[i]);
        i++;
    }
}