#include "includes/ft_printf.h"

static int	for_space(int actlen, int len, int symbs, t_spec *data)
{
	symbs = 0;
	if (actlen > len - 1)
		symbs += print_space(data, actlen + 1);
	if (actlen <= len - 1)
		symbs += print_space(data, len);
	return (symbs);
}

static int	writenum(char *num)
{
	int	symbs;

	symbs = 0;
	while (*num)
	{
		write(1, num, 1);
		num++;
		symbs++;
	}
	return (symbs);
}

static int	printprecision(char *num, int len, int symbs, t_spec *data)
{
	int	actlen;
	int	width;

	width = data->width;
	actlen = data->precision;
	if (width - actlen + 2 > 0 && data->minus == 0)
		symbs += for_space(actlen, len, symbs, data);
	if (actlen - len >= 0)
	{
		write(1, "-", 1);
		symbs++;
		num++;
		symbs += print_zero_precision(data, len - 1);
	}
	symbs += writenum(num);
	if (width - actlen + 2 > 0 && data->minus == 1)
		symbs += for_space(actlen, len, symbs, data);
	return (symbs);
}

int	printnegative(char *num, int len, int symbs, t_spec *data)
{
	if (data->precision == -1)
	{
		if (data->width - len > 0 && data->minus == 0)
		{
			if (data->zero == 0)
				symbs += print_space(data, len);
			else
			{
				write(1, "-", 1);
				symbs++;
				num++;
				symbs += print_zero(data, len);
			}
		}
		symbs += writenum(num);
		if (data->width - len > 0 && data->minus == 1)
			symbs += print_space(data, len);
	}
	else
		symbs += printprecision(num, len, symbs, data);
	return (symbs);
}
