
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int   i;
	char *s;
	int   printed_word;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	i = 0;
	printed_word = 0;

	
	while (s[i] && is_space(s[i]))
		i++;

	while (s[i])
	{
		
		while (s[i] && !is_space(s[i]))
		{
			write(1, &s[i], 1);
			i++;
			printed_word = 1;
		}
	
		while (s[i] && is_space(s[i]))
			i++;
		
		if (s[i] && printed_word)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}

