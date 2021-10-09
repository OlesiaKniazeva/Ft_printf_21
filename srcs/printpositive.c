#include "includes/ft_printf.h"

static int	printprecision(char *num, int len, int symbs, t_spec *data)
{
	int	actlen;
	int	width;

	width = data->width;
	actlen = data->precision;
	if (width - actlen > 0 && data->minus == 0)
	{
		if (actlen > len)
			symbs += print_space(data, actlen);
		if (actlen <= len)
			symbs += print_space(data, len);
	}
	if (actlen - len > 0)
		symbs += print_zero_precision(data, len);
	write (1, num, len);
	symbs += len;
	if (width - actlen > 0 && data->minus == 1)
	{
		if (actlen > len)
			symbs += print_space(data, actlen);
		if (actlen <= len)
			symbs += print_space(data, len);
	}
	return (symbs);
}

int	printpositive(char *num, int len, int symbs, t_spec *data)
{
	if (data->precision == -1)
	{
		if (data->width - len > 0 && data->minus == 0)
		{
			if (data->zero == 0)
				symbs += print_space(data, len);
			else
				symbs += print_zero(data, len);
		}
		write(1, num, len);
		symbs += len;
		if (data->width - len > 0 && data->minus == 1)
			symbs += print_space(data, len);
	}
	else
		symbs += printprecision(num, len, symbs, data);
	return (symbs);
}
