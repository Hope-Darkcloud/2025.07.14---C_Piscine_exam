#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i, j;
    int tmp;

    if (size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}


int main(void)
{
    int tab[] = {5, 3, 8, 1, 4, 3};
    unsigned int size = 6;
    unsigned int i;

    sort_int_tab(tab, size);

    for (i = 0; i < size; i++)
        printf("%d ", tab[i]);
    printf("\n");

    return 0;
}

