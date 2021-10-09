#include "includes/ft_printf.h"

static char	ft_convert(unsigned int num)
{
	int	a;

	a = num % 16;
	if (a == 10)
		return ('A');
	if (a == 11)
		return ('B');
	if (a == 12)
		return ('C');
	if (a == 13)
		return ('D');
	if (a == 14)
		return ('E');
	if (a == 15)
		return ('F');
	return (0);
}

static int	ft_amount(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char	*tosixteenhigh(unsigned int num)
{
	char	*sixtnnumb;
	int		amount;

	amount = ft_amount(num);
	sixtnnumb = malloc(sizeof(char) * (amount + 1));
	if (sixtnnumb == NULL)
		return (NULL);
	*(sixtnnumb + amount) = '\0';
	amount--;
	while (amount)
	{
		if (num % 16 >= 10)
			*(sixtnnumb + amount) = ft_convert(num);
		else
			*(sixtnnumb + amount) = num % 16 + '0';
		num /= 16;
		amount--;
	}
	if (num >= 10)
		*sixtnnumb = ft_convert(num);
	else
		*sixtnnumb = num + '0';
	return (sixtnnumb);
}
