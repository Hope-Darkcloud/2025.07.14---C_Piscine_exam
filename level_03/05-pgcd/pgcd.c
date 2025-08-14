#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("\n");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int temp;


    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    printf("%d\n", a);
    return 0;
}

