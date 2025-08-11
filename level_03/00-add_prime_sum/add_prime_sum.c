#include <unistd.h>

int is_prime(int n)
{
    int i;

    if (n < 2)
        return 0;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void    ft_putnbr(int n)
{
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int n;
    int sum = 0;
    int i = 2;

    if (argc != 2)
    {
        write(1, "0\n", 2);
        return 0;
    }

  
    n = 0;
    while (*argv[1])
    {
        if (*argv[1] < '0' || *argv[1] > '9')
        {
            write(1, "0\n", 2);
            return 0;
        }
        n = n * 10 + (*argv[1] - '0');
        argv[1]++;
    }

    while (i <= n)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }

    ft_putnbr(sum);
    write(1, "\n", 1);

    return 0;
}

