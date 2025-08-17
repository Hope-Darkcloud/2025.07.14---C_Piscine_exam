#include "test_functions.h"
#include "flood_fill.h"
#include <stdio.h>

int main(void)
{
    char **area;
    t_point size = { 8, 5 };
    t_point begin = { 2, 2 };
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
        NULL
    };
    area = make_area(zone);
    print_tab(area);
    flood_fill(area, size, begin);
    printf("\n");
    print_tab(area);
    return (0);
}

