#include <stdlib.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	word_count(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (!is_sep(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(char *start, int len)
{
	char	*word;
	int		i = 0;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		words = word_count(str);
	int		i = 0, j, len;

	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (*str)
	{
		if (!is_sep(*str))
		{
			j = 0;
			while (str[j] && !is_sep(str[j]))
				j++;
			tab[i] = word_dup(str, j);
			i++;
			str += j;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}

