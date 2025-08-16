#include <stdlib.h>

int *ft_range(int start, int end)
{
    int size;
    int *arr;
    int i = 0;

    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);

    while (i < size)
    {
        if (start <= end)
            arr[i] = start + i;
        else
            arr[i] = start - i;
        i++;
    }
    return (arr);
}

