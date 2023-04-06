#include "libft.h"

void ft_puthcar_fd(char c, int fd)
{
    write(fd, &c, 1);
}