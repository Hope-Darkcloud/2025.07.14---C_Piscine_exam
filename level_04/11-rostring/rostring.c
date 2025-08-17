#include <unistd.h>

static void put_word(char *start, int len)
{
	write(1, start, len);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	char *str = argv[1];
	int i = 0, start, len;

	// 1. Başlangıçtaki boşlukları atla
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	// 2. İlk kelimeyi kaydet
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	len = i - start;

	// 3. Sonraki kelimeleri yazdır
	int first = 1;
	while (str[i])
	{
		// boşlukları atla
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			if (!first)
				write(1, " ", 1);
			first = 0;

			int j = i;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
			put_word(str + j, i - j);
		}
	}

	// 4. İlk kelimeyi sona ekle
	if (len > 0)
	{
		if (!first)
			write(1, " ", 1);
		put_word(str + start, len);
	}

	write(1, "\n", 1);
	return (0);
}

