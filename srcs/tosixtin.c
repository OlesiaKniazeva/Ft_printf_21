#include "includes/ft_printf.h"

static char	ft_convert(unsigned long adr)
{
	int	a;

	a = adr % 16;
	if (a == 10)
		return ('a');
	if (a == 11)
		return ('b');
	if (a == 12)
		return ('c');
	if (a == 13)
		return ('d');
	if (a == 14)
		return ('e');
	if (a == 15)
		return ('f');
	return (0);
}

static int	ft_amount(unsigned long adr)
{
	int	count;

	count = 0;
	if (adr == 0)
		return (1);
	while (adr)
	{
		adr /= 16;
		count++;
	}
	return (count);
}

char	*tosixtin(unsigned long adr)
{
	char	*sixtnnumb;
	int		amount;

	amount = ft_amount(adr);
	sixtnnumb = malloc(sizeof(char) * (amount + 1));
	*(sixtnnumb + amount) = '\0';
	amount--;
	while (amount)
	{
		if (adr % 16 >= 10)
			*(sixtnnumb + amount) = ft_convert(adr);
		else
			*(sixtnnumb + amount) = adr % 16 + '0';
		adr /= 16;
		amount--;
	}
	if (adr >= 10)
		*sixtnnumb = ft_convert(adr);
	else
		*sixtnnumb = adr + '0';
	return (sixtnnumb);
}
