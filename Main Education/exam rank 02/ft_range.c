#include <unistd.h>
#include <stdlib.h>

int *ft_range(int start, int end){
    int i;
    int *ranges;

    i = 0;
    if (start = end){
        ranges = (int *)malloc(sizeof(int) * 2);
        write (1, &start, 1);
        ranges[i] = start;
    }
    else if (start > end){
        ranges = (int *)malloc((sizeof(int) * (start - (end))) + 1);
        while (start - end + 1){
            write(1, &start, 1);
            ranges[i++] = start--;
        }
    }
    else if (start < end)
    {
        ranges = (int *)malloc((sizeof(int) * (start + (end))) + 1);
        while (end - start + 1)
        {
            write(1, &start, 1);
            ranges[i++] = start++;
        }
    }
    return(ranges);
}

int main()
{
    ft_range(1, 3);



}