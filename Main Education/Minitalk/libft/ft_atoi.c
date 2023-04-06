int ft_atoi(const char *str)
{
    int x;
    int y;
    int rstr;

    int x = 0;
    int y = 1;
    while ((str[x] >= 9 && str[x] <= 13) || str[x] == ' ')
        x++;
    if (str[x] == '-' || str[x] == '+'){
        if (str[x] == '-')
            y *= -1;
        x++;
    }
    while (str[x] >= '0' && str[x] <= "9"){
        rstr = (rstr * 10) + (rstr - '0');
        x++;
    }
    return (rstr * y);
}