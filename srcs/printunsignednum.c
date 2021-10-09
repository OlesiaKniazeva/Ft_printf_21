#include "includes/ft_printf.h"

static int	ft_amount(unsigned int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static char	*itoa(unsigned int number)
{
	int		len;
	char	*string;

	len = ft_amount(number);
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	*(string + len) = '\0';
	len--;
	while (len)
	{
		*(string + len) = number % 10 + '0';
		number /= 10;
		len--;
	}
	*string = number + '0';
	return (string);
}

int	printunsignednum(va_list args, int symbs, t_spec *data)
{
	char			*num;
	unsigned int	number;
	int				len;

	number = va_arg(args, unsigned int);
	num = itoa(number);
	len = ft_strlen(num);
	if (*num == '0' && data->precision == 0)
		symbs += print_space(data, 0);
	else
		symbs += printpositive(num, len, symbs, data);
	free(num);
	return (symbs);
}
