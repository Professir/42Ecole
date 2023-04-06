#include "so_long.h"



#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_vars	var;
	
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "safak");
	check_ber(av[1], var);
	mlx_loop(var.mlx);
}