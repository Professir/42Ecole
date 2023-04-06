#include "libft.h"

char *ft_strmapi(char const *s, char *f(unsigned int, char)){
    size_t i;
    size_t len;
    char *str;

    i = 0;
    if (!s || !f)
        return (NULL);
    len = ft_strlen(s);
    str = (char *) malloc(len + 1);
    if(!(str = (char *) malloc(len + 1)))
        return (NULL);
    while (len > i){
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}