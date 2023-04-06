#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	var;
	
	// var.max_x = ft_strlen(av[1]);
	// var.max_y = count_double(av) + 2;
	// char *abc = ft_itoa(var.max_x);
	// write(1, &abc[0], 1);
	var.mlx = mlx_init();
	// var.win = mlx_new_window(var.mlx, var.max_x * 64, var.max_y * 64, "safak");
	check_ber(av[1], var); 
	system("leaks a.out");
	mlx_loop(var.mlx);

	
}