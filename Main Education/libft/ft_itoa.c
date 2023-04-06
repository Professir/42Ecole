static int		ft_numlen(int num)
{
	int		len;

	len = 0;
	if (num == 0)
	{
		len = 1;
	}
	if (num < 0)
	{
		len++;
		num = -1 * num;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		nlen;
	char	*str;
	long int     num;

	nlen = 0;
	num = n;
	nlen = ft_numlen(n);
	if (!(str = malloc(nlen + 1)))
		return (NULL);
	str[nlen] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	nlen--;
	while (nlen >= 0 && num != 0)
	{
		str[nlen] = (num % 10) + '0';
		num = num / 10;
		nlen--;
	}
	return (str);
}