#include "so_long.h"

int		col_counts;

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

void	count_collectables(char **a)
{
	int	i;
	int	b;
	int	k;

	i = -1;
	b = 0;
	while (a[++i])
	{
		k = -1;
		while (a[i][++k] == 'C')
			b++;
	}
	col_counts = b;
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
