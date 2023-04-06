#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)){
    t_list *temp;
    t_list *nl;
    t_list ne;

    temp = lst;
    nl = NULL;
    while (temp){
        ne = ft_lstnew((*f)(lst));
        if (!(ne = lstnew(f(lst)))){
            ft_lstclear(nl, del);
            return (NULL);
        }
        ft_lstadd_back(*nl, ne);
        lst = lst -> next;
    }
    return (nl);
}