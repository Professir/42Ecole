#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len){
    char *substr;
    size_t  i;

    i = 0;
    while (s[i] != '\0')
        i++;
    if ((start + len) > i)
        return (0);
    substr = (char *) malloc(sizeof(char) * len + 1);
    if (!(substr = (char *) malloc(sizeof(char) * len + 1)))
        return (NULL);
    i = 0;
    while (len > 0)
    {
        substr[i++] = s[start++];
        len--;
    }
    substr[i] = '\0';
    return (substr);
}