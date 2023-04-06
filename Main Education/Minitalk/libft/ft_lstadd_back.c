#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list new){
    t_list *temp;

    if (!new)
        return (0);
    if (!*lst){
        *lst = new;
        return (0);
    }
    temp = ft_lstlast(*lst);
    temp -> next = new;
    lst = temp;
}