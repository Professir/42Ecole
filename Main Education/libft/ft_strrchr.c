#include "libft.h"

char *ft_strrchr(const char *str, int c){
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    i--;
    while (i >= 0)
    {
        if (str[i] == (char)c)
            return (((char *)(str + i))
        i--;
    }
    return (0);
}