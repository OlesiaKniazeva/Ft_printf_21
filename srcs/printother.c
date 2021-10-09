#include "includes/ft_printf.h"

int	printother(int symbs, t_spec *data)
{
	if (data->type >= 0 && data->type <= 9)
		return (0);
	if ((data->width - 1) > 0 && data->minus == 0)
	{
		if (data->zero == 0)
			symbs += print_space(data, 1);
		else
			symbs += print_zero(data, 1);
	}
	write(1, &data->type, 1);
	symbs ++;
	if (data->minus == 1)
		symbs += print_space(data, 1);
	return (symbs);
}
