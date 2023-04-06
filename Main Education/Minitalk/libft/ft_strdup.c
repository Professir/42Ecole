#include "libft.h"

char *strdup(const char *str){
    char *rstr;
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    rstr = (char *) malloc(sizeof(char) * (i + 1));
    if (!(rstr = (char *) malloc(sizeof(char) * i)))
        return (0);
    i = 0;
    while (str[i] != '\0')
    {
        rstr[i] = str[i];
        i++;
    }
    return (rstr);
}