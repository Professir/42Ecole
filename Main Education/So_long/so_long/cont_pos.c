#include "so_long.h"

void	check_pos(char **pos)
{
	int	i;
	int	k;
	t_vector	*ex;
	t_vector	*player;

	i = 0;
	while (pos[i])
	{
		k = 0;
		while (pos[i][k])
		{
			if (pos[i][k] == 'P')
			{
				player->x = k;
				player->y = i;
			}
			if (pos[i][k] == 'E')
			{
				ex->x = k;
				ex->y = i;
			}
			k++;
		}
		i++;
	}
	count_collectables(pos);
}

void	init_map(char **har, t_vars t_data, t_objs *g_adr_objs)
{
	int	i;
	int	k;

	i = 0;
	// t_data.win = mlx_new_window(t_data.mlx, t_data.max_x * 64, t_data.max_y * 64, "safak");
	mlx_clear_window(t_data.mlx, t_data.win);
	while (har[i])
	{
		k = 0;
		while (har[i][k])
		{
			if (har[i][k] == '1')
				mlx_put_image_to_window(t_data.mlx, t_data.win, g_adr_objs->wall, k * 64, i * 64);
			else if (har[i][k] == 'P'){
				mlx_put_image_to_window(t_data.mlx, t_data.win, g_adr_objs->floor, k * 64, i * 64);
				mlx_put_image_to_window(t_data.mlx, t_data.win, g_adr_objs->character, k * 64, i * 64);
			}
			else if (har[i][k] == '0' )
					mlx_put_image_to_window(t_data.mlx, t_data.win, g_adr_objs->floor, k * 64, i * 64);
			else if (har[i][k] == 'E')
				mlx_put_image_to_window(t_data.mlx, t_data.win, g_adr_objs->exs, k * 64, i * 64);
			else if (har[i][k] == 'C'){
				mlx_put_image_to_window(t_data.mlx, t_data.win, g_adr_objs->floor, k * 64, i * 64);
				mlx_put_image_to_window(t_data.mlx, t_data.win, g_adr_objs->collects, k * 64, i * 64);
			}
			k++;
		}
		i++;
	}
}

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char *str;
	long n;
	int i;

	n = nb;
	i = len(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}