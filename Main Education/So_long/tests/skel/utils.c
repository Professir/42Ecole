#include "testlib.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ml;
	size_t	strlen;

	i = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen || !len)
		return (ft_strdup(""));
	if (strlen > len)
		strlen = len;
	ml = (char *)malloc((strlen + 1) * sizeof(char));
	if (!ml)
		return (NULL);
	ml[strlen] = '\0';
	while (strlen--)
		ml[i++] = s[start++];
	return (ml);
}

int	charcounter(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && (*s != c))
	{
		i++;
		s++;
	}
	return (i);
}

void	check_map(char **map)
{
	int		i;
	int		max_y;
	int		max_x;
	char	*abc;

	i = 0;
	if (!map)
		return ;
	max_x = ft_strlen(*map) - 1;
	max_y = count_double(map) - 1;
	while (1)
	{
		if(i != max_x - 1)
			if(map[0][i] != '1' && map[max_y][i] != '1')
				error_log(1);
		if(i != max_y - 1)
			if(map[i][0] != '1' && map[i][max_x] != '1')
				error_log(1);
		if(i >= max_x && i >= max_y)
			break;
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

void ft_print_matrix(char **matrix)
{
	// char matrix[5][10] = {\
	// 	"1211111111",\
	// 	"3000000001",\
	// 	"1000000001",\
	// 	"1000000001",\
	// 	"1111111111"\
	// 	};
	char **mtx = matrix;
	printf("%s\n", mtx);

	// int rows_count = sizeof(matrix) / sizeof(*matrix);
	// int colum_count = sizeof(*matrix);

	// printf("%s\n", matrix);
	// printf("%d\n", rows_count);
	// printf("%d\n", sizeof(matrix));

	// write(1, matrix[0], 1);


	// for(int x = 0; x < rows_count; x++){
	// 	for(int y = 0; y < colum_count; y++){
	// 		write(1, &matrix[x][y], 1);
	// 	}
	// 	write(1, "\n", 1);
	// }
}
int	count_char(char *str, char s)
{
	int	k;

	k = -1;
	while (*str && s)
	{
		if (*str == s)
			k++;
		++str;
	}
	return (k);
}
int	count_double(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	error_log(int error_id)
{
	ft_putstr("Error\n");
	if (error_id == 1)
		ft_putstr("Wrong walls");
	if (error_id == 2)
		ft_putstr("The map is not in the correct format");
	if (error_id == 3)
		ft_putstr("The map is empty");
	if (error_id == 4)
		ft_putstr("Use .ber extension file");
	exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*temp;

	if (!str1 && !str2)
		return (ft_strdup(""));
	if (str1 && !str2)
		return (str1);
	if (!str1 && str2)
		return (str2);
	temp = (char *)malloc((ft_strlen(str1) + ft_strlen(str2)) * sizeof(char)
			+ 1);
	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[j])
		temp[i++] = str1[j++];
	j = 0;
	while (str2[j])
		temp[i++] = str2[j++];
	temp[i] = 0;
	return (temp);
}

char	**ft_double(char *str, char s)
{
	char	**dabs;
	int		i;
	int		len;
	int		b;

	dabs = (char **)malloc(sizeof(char *) * count_char(str, s) + 1);
	if (!dabs)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == s && *str)
			str++;
		dabs[i] = ft_substr(str, 0, charcounter(str, s));
		i++;
		str = str + charcounter(str, s);
	}
	dabs[i] = 0;
	return (dabs);
}
