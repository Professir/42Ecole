#include "libft.h"

static int	ft_cont(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == s1)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	x = ft_strlen(s1);
	while (s1[i] && ft_cont(s1[i], set))
		i++;
	while (j > i && ft_cont(s1[k - 1], set))
		x--;
	str = (char *)malloc(sizeof(char) * (x - i + 1));
	if (!(str = (char *)malloc(sizeof(char) * (x - i + 1))))
		return (NULL);
	while (i < x)
		str[y++] = s1[i++];
	str[y] = '\0';
	return (str);
}