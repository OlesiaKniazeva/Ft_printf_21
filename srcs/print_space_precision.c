#include "includes/ft_printf.h"

int	print_space_precision(t_spec *data, int len)
{
	int	symbs;

	symbs = 0;
	while ((data->width - len) > 0)
	{
		write(1, " ", 1);
		symbs++;
		data->width--;
	}
	return (symbs);
}
