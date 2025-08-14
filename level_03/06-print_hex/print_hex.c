#include <unistd.h>

int	ft_atoi(char *str)
{
	int n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n);
}

void	print_hex_rec(unsigned int n)
{
	char *hex = "0123456789abcdef";
	if (n >= 16)
		print_hex_rec(n / 16);
	write(1, &hex[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		unsigned int num = ft_atoi(argv[1]);
		print_hex_rec(num);
	}
	write(1, "\n", 1);
	return (0);
}

