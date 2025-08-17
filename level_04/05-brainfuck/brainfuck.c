#include <unistd.h>
#include <stdlib.h>

#define TAPE_SIZE 2048

static void	brainfuck(char *src)
{
	unsigned char	tape[TAPE_SIZE] = {0};
	unsigned char	*ptr = tape;
	int				i = 0;
	int				loop;

	while (src[i])
	{
		if (src[i] == '>')
			ptr++;
		else if (src[i] == '<')
			ptr--;
		else if (src[i] == '+')
			(*ptr)++;
		else if (src[i] == '-')
			(*ptr)--;
		else if (src[i] == '.')
			write(1, ptr, 1);
		else if (src[i] == '[' && *ptr == 0)
		{
			loop = 1;
			while (loop > 0)
			{
				i++;
				if (src[i] == '[')
					loop++;
				else if (src[i] == ']')
					loop--;
			}
		}
		else if (src[i] == ']' && *ptr != 0)
		{
			loop = 1;
			while (loop > 0)
			{
				i--;
				if (src[i] == ']')
					loop++;
				else if (src[i] == '[')
					loop--;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		brainfuck(argv[1]);
	return (0);
}

