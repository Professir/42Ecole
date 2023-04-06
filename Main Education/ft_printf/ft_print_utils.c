#include "ft_printf.h"

int ft_print_char(char c)
{
    int len;
    
    len = 0;
    len = write(1, &c, 1);
    return (len);
}

int ft_print_str(char *str)
{
    int len;
    len = 0;
    if(!str)
        return (ft_print_str("(null)"));
    len = write(1, str, ft_strlen(str));
    return (len);
}

int ft_print_pointer(void *point)
{
    int len;
    unsigned long rep;
    
    len = 0;
    rep = (unsigned long)point;
    if (rep >= 16)
    {
        len += ft_print_pointer((void *)(rep / 16));
        len += ft_print_pointer((void *)(rep % 16));
    }
    else
        len += ft_print_char("0123456789abcdef"[rep % 16]);
    return (len);
}

int ft_print_nbr(int num)
{
    char *rnum;
    int len;

    len = 0;
    rnum = ft_itoa(num);
    len += ft_print_str(rnum);
    free(rnum);
    return (len);
}

int ft_print_unbr(unsigned int num)
{
    int len;

    len = 0;
    if (num > 9)
    {
        len += ft_print_unbr(num / 10);
        len += ft_print_unbr(num % 10);
    }
    else
        len += ft_print_char("0123456789"[num % 10]);
    return (len);
}

int ft_print_hexnum(unsigned int num, char const format)
{
    int len;

	len = 0;
    if (format == 'x')
    {
        if (num >= 16)
        {
            len += ft_print_hexnum((num / 16), format);
            len += ft_print_hexnum((num % 16), format);
        }
        else
            len += ft_print_char("0123456789abcdef"[num % 16]);
    }
    else if (format == 'X')
    {
        if (num >= 16)
        {
            len += ft_print_hexnum((num / 16), format);
            len += ft_print_hexnum((num % 16), format);
        }
        else
            len += ft_print_char("0123456789ABCDEF"[num % 16]);
    }
    return (len);
}