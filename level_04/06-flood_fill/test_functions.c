#include <stdlib.h>
#include <stdio.h>
#include "test_functions.h"

char	**make_area(char **zone)
{
	int		y = 0;
	int		width = 0;
	while (zone[0][width])
		width++;
	while (zone[y])
		y++;

	char **area = malloc(sizeof(char *) * (y + 1));
	for (int i = 0; i < y; i++)
	{
		area[i] = malloc(width + 1);
		int j = 0;
		while (zone[i][j])
		{
			area[i][j] = zone[i][j];
			j++;
		}
		area[i][j] = '\0';
	}
	area[y] = NULL;
	return (area);
}

void	print_tab(char **area)
{
	int i = 0;
	while (area[i])
	{
		int j = 0;
		while (area[i][j])
		{
			printf("%c ", area[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

