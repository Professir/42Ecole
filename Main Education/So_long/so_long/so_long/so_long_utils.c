#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
