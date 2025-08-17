#include <unistd.h>
#include <stddef.h>
#include <stdio.h> 
                     
static void	print_hex(unsigned char c)
{
	char *hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

static void	print_ascii(const unsigned char *addr, size_t size, size_t offset)
{
	size_t i;
	unsigned char c;

	i = 0;
	while (i < 16 && (offset + i) < size)
	{
		c = addr[offset + i];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	const unsigned char *ptr = (const unsigned char *)addr;
	size_t i = 0;
	size_t j;

	while (i < size)
	{
		j = 0;
		while (j < 16 && (i + j) < size)
		{
			print_hex(ptr[i + j]);
			if (j % 2 == 1)
				write(1, " ", 1);
			j++;
		}
		// boşluk doldurma (satır tam 16 byte değilse)
		while (j < 16)
		{
			write(1, "  ", 2);
			if (j % 2 == 1)
				write(1, " ", 1);
			j++;
		}
		print_ascii(ptr, size, i);
		i += 16;
	}
}



void	print_memory(const void *addr, size_t size);

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}

