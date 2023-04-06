#include "libft.h"

int ft_lstsize(t_list *lst){
    int x;

    x = 0;
    while (lst){
        lst = lst -> new;
        x++;
    }
    return  (x);
}