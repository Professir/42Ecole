#include "libft.h"

static size_t ft_lng(char const *s, char c){
    size_t x;

    x = 1;
    if (!s)
        return (0);
    while (*s){
        if (*s == c)
            x++;
        *s++;
    }
    return (x);
}

char **ft_split(char const *s, char c)
{
    size_t i;
    size_t y;
    char **rstr;

    i = 0;
    rstr = (char **) malloc (sizeof(char *) * ft_lng(s, c));
    if (!s || !(rstr = (char **) malloc (sizeof(char *)) * ft_lng(s, c)))
        return (NULL);
    while (*s){
        if (*s != c){
            y = 0;
            while (*s && *s != c && y++)
                s++;
            rstr[i++] = ft_substr(s - y, 0, y);
        }
        else
            s++;
    }
    rstr[i] = '\0';
    return (rstr);
}