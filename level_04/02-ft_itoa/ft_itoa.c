#include <stdlib.h>
#include <stdio.h>
char *ft_itoa(int nbr)
{
    long n = nbr;
    int len = (n <= 0) ? 1 : 0; // negatif veya 0 için 1 karakter
    long tmp = n;

    while (tmp)
    {
        len++;
        tmp /= 10;
    }

    char *str = malloc(len + 1);
    if (!str)
        return NULL;

    str[len] = '\0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }

    if (n == 0)
        str[0] = '0';

    while (n)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }

    return str;
}

int    main(void)
{
    int i = 0;
    int tab[5] = {-2147483648, -42, 0, 42, 2147483647};

    while (i < 5)
        printf("%s\n", ft_itoa(tab[i++]));

    return 0;
}
