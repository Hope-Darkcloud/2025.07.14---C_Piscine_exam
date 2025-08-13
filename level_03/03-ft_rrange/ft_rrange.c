#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int len;
    int *arr;
    int step;
    int i = 0;

    len = (start <= end) ? end - start + 1 : start - end + 1;
    arr = malloc(len * sizeof(int));
    if (!arr)
        return (NULL);

    step = (end > start) ? -1 : 1; 
    while (i < len)
    {
        arr[i] = end;
        end += step;
        i++;
    }
    return (arr);
}

#include <stdio.h>

int *ft_rrange(int start, int end);

int main(void)
{
    int i;
    int *arr;
    int len;

    arr = ft_rrange(1, 3);
    len = 3;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    arr = ft_rrange(0, -3);
    len = 4; 
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

