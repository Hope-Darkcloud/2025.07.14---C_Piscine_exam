#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*digits = "0123456789ABCDEF";
	long	n;
	int		len = 0;
	int		neg = 0;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
	{
		str = (char *)malloc(2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (value < 0 && base == 10)
		neg = 1;
	n = value;
	if (n < 0)
		n = -n;

	long tmp = n;
	while (tmp > 0)
	{
		tmp /= base;
		len++;
	}
	str = (char *)malloc(len + neg + 1);
	if (!str)
		return (NULL);
	str[len + neg] = '\0';
	while (len > 0)
	{
		str[len + neg - 1] = digits[n % base];
		n /= base;
		len--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
#include <stdio.h>

int main()
{
	printf("%s\n", ft_itoa_base(255, 16)); 
	printf("%s\n", ft_itoa_base(-255, 10));
	printf("%s\n", ft_itoa_base(255, 2));
	printf("%s\n", ft_itoa_base(-42, 16));
}

