#include <unistd.h>

void maff_alpha()
{
    int i = 0;

    while (i < 26)
    {
        char c;

        if (i % 2 == 0)
            c = 'a' + i;
        else
            c = 'A' + i;

        write(1, &c, 1);
        i++;
    }

    write(1, "\n", 1);
}

int main(void)
{
    maff_alpha();
    return 0;
}
