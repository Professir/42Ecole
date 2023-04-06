#include "so_long.h"

t_vars	var;

#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	check_ber(av[1]);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "safak");
	mlx_loop(var.mlx);
}