#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int found = 0;

    if (argc != 2)
    {
        write(1, "z\n", 2);
        return 0;
    }

    while (argv[1][i])
    {
        if (argv[1][i] == 'z')
        {
            write(1, "z", 1);
            found = 1;
            break;
        }
        i++;
    }

    if (found == 0)
        write(1, "z", 1);

    write(1, "\n", 1);
    return 0;
}
