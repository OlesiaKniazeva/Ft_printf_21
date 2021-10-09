#include "includes/ft_printf.h"

int	print_zero(t_spec *data, int len)
{
	int	symbs;

	symbs = 0;
	while ((data->width - len) > 0)
	{
		write(1, "0", 1);
		symbs++;
		data->width--;
	}
	return (symbs);
}
