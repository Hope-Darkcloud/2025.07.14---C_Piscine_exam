#include <unistd.h>

int is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    char c;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    j = 1;
    while (j < argc)
    {
        i = 0;
        while (argv[j][i])
        {
            c = to_lower(argv[j][i]);
            if (is_letter(c) &&
                (argv[j][i + 1] == ' ' || argv[j][i + 1] == '\t' || argv[j][i + 1] == '\0'))
                c = to_upper(c);
            write(1, &c, 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
    }
    return (0);
}

