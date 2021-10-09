#include "includes/ft_printf.h"

int	print_zero_precision(t_spec *data, int len)
{
	int	symbs;

	symbs = 0;
	while ((data->precision - len) > 0)
	{
		write(1, "0", 1);
		symbs++;
		data->precision--;
	}
	return (symbs);
}
