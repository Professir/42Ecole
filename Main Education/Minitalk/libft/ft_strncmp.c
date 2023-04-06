#include "libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t n){
    size_t i;

    i = 0;
    if (n == 0)
		return (0);
    while (str1[i] != '\0' && i < n - 1 
    && str2[i] != '\0' && str1[i] == str2[i])
        i++;
    return (str1[i] - str2[i]);
}