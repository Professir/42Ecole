int ft_isalnum(int c){
    if((c >= 48 && c <= 57) || ((c > 64 && c < 91) 
    || (c > 96 && c < 123)))
        return (1);
    return (0);
}