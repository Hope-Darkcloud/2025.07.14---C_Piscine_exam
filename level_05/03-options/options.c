#include "options.h"
#include <unistd.h>

void    putchar_fd(char c)
{
    write(1, &c, 1);
}

void    putstr_fd(const char *s)
{
    while (*s)
        putchar_fd(*s++);
}

void    print_usage(void)
{
    putstr_fd("options: abcdefghijklmnopqrstuvwxyz\n");
}

/* print 32 bits in 4 groups of 8 bits */
void    print_bits(unsigned int mask)
{
    int i = 31;
    while (i >= 0)
    {
        if ((mask >> i) & 1)
            putchar_fd('1');
        else
            putchar_fd('0');
        if (i % 8 == 0 && i != 0)
            putchar_fd(' ');
        i--;
    }
    putchar_fd('\n');
}

int main(int argc, char **argv)
{
    unsigned int mask = 0;
    int i, j;

    if (argc == 1)
    {
        print_usage();
        return (0);
    }
    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
        {
            putstr_fd("Invalid Option\n");
            return (0);
        }
        for (j = 1; argv[i][j]; j++)
        {
            char c = argv[i][j];
            if (c == 'h')
            {
                print_usage();
                return (0);
            }
            if (c < 'a' || c > 'z')
            {
                putstr_fd("Invalid Option\n");
                return (0);
            }
            mask |= 1U << (c - 'a');
        }
    }
    print_bits(mask);
    return (0);
}

