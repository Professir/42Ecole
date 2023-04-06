#include "so_long.h"

char	**g_maps;
t_objs	g_adr_objs;
t_vars	g_var;

void	err_fd(int i, char **kaps, char *str)
{
	if (i == -1)
	{
		free(kaps);
		free(str);
		ft_putstr("Error\nfd Okunamadi");
		exit(0);
	}
}

char	**get_map(int fd)
{
	char		**mapss;
	char		*str;
	char		*temp;
	int			byte_read;
	static char	map[1];

	str = ft_strdup("");
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, map, 1);
		temp = str;
		str = ft_strjoin(temp, map);
		free(temp);
	}
	mapss = ft_double(str, '\n');
	free(str);
	err_fd(byte_read, mapss, str);
	return (mapss);
}

void	check_map(char **map, t_vars *t_data)
{
	int		i;
	int		max_y;
	int		max_x;
	int 	k;

	i = -1;	
	if (!map)
		return ;
	t_data -> max_y = count_double(map);
	while (map[++i])
	{
		if(map[i][0] != '1')
			error_log(1);
	}
	k = 0;
	t_data -> max_x = ft_strlen(*map);
	while(k < i)
	{
		if(map[k][ft_strlen(map[k]) - 1] != '1')
				error_log(1);
		k++;
	}
}
void	load_map(char **map, t_vars t_data)
{
	int	i;
	int	k;
	t_objs	*g_adr_objs;

	t_data.win = mlx_new_window(t_data.mlx, t_data.max_x * 64, t_data.max_y * 64, "safak");

	g_adr_objs = malloc(sizeof(t_objs));
	if(!g_adr_objs)
		return ;
	g_adr_objs->wall 		= mlx_xpm_file_to_image(t_data.mlx, "content/wall.xpm", &i, &k);
	g_adr_objs->character 	= mlx_xpm_file_to_image(t_data.mlx, "content/character.xpm",
			&i, &k);
	g_adr_objs->exs 			= mlx_xpm_file_to_image(t_data.mlx, "content/exit.xpm", &i, &k);
	g_adr_objs->collects 	= mlx_xpm_file_to_image(t_data.mlx, "content/collects.xpm",
			&i, &k);
	g_adr_objs->floor 		= mlx_xpm_file_to_image(t_data.mlx, "content/floor.xpm", &i,
			&k);
	init_map(map, t_data, g_adr_objs);
}

void	check_ber(char *map, t_vars t_data)
{
	int len;
	t_vars var;

	len = ft_strlen(map);
	if (!(map[len - 1] == 'r' && map[len - 2] == 'e' && map[len - 3] == 'b'
			&& map[len - 4] == '.'))
		error_log(4);
	else
	{
		g_maps = get_map(open(map, O_RDONLY));
		check_map(g_maps, &t_data);
		load_map(g_maps, t_data);
	}
}