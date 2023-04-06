#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *res;

    res = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!(res = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
        return (NULL);
    else{
        ft_strcpy(res, s1);
        ft_strcat(res, s2);
    }
    return (res);
}