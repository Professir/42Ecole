#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>


int ft_print_hexnum(unsigned int num, char const format);
int ft_print_unbr(unsigned int num);
int ft_print_nbr(int num);
int ft_print_pointer(void *point);
int ft_print_str(char *str);
int ft_print_char(char c);
int ft_printf(const char *str, ...);

#endif