#include "libft.h"

void ft_putnbr_fd(int n, int fd){
    long int rn;

    rn = n;
    if (rn < 0){
        rn *= -1;
        write(fd, "-", 1);
    }
    if (rn > 9){
        ft_putnbr_fd((rn / 10), fd);
        ft_putnbr_fd((rn % 10), fd);
    }
    else
        ft_puthcar_fd((rn + '0'), fd);
}