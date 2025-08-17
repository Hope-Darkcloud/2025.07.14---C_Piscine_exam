#include <unistd.h>
#include <stdlib.h>

static void put_str(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	char *str = argv[1];
	int i = 0, j, k = 0;
	int count = 0;

	// 1. Kelime sayısını bul
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}

	// 2. Kelimeleri tutacak array
	char **words = (char **)malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			j = i;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			int len = i - j;
			words[k] = (char *)malloc(len + 1);
			for (int m = 0; m < len; m++)
				words[k][m] = str[j + m];
			words[k][len] = '\0';
			k++;
		}
	}
	words[k] = NULL;

	// 3. Kelimeleri ters sırada yazdır
	for (int n = count - 1; n >= 0; n--)
	{
		put_str(words[n]);
		if (n > 0)
			write(1, " ", 1);
		free(words[n]);
	}
	free(words);
	write(1, "\n", 1);
	return (0);
}

