#include "biggest_pal.h"
#include <unistd.h>

/* write helpers */
void    putchar_fd(char c)
{
    write(1, &c, 1);
}

void    putstr_fd(const char *s)
{
    while (*s)
        putchar_fd(*s++);
}

/* palindrome check */
int is_pal(const char *s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return (0);
        start++;
        end--;
    }
    return (1);
}

/* brute force: try all substrings */
void find_biggest_pal(const char *s, int *best_start, int *best_len)
{
    int i, j;
    int len = 0;
    *best_start = 0;
    *best_len = 0;
    for (i = 0; s[i]; i++)
    {
        for (j = i; s[j]; j++)
        {
            if (is_pal(s, i, j))
            {
                len = j - i + 1;
                if (len > *best_len || (len == *best_len && i > *best_start))
                {
                    *best_len = len;
                    *best_start = i;
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    int start, len, i;

    if (argc != 2)
    {
        putchar_fd('\n');
        return (0);
    }
    find_biggest_pal(argv[1], &start, &len);
    for (i = 0; i < len; i++)
        putchar_fd(argv[1][start + i]);
    putchar_fd('\n');
    return (0);
}

