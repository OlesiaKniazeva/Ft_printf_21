#include "includes/ft_printf.h"

int	printsymb(va_list args, int	symbs, t_spec *data)
{
	char	c;

	c = va_arg(args, int);
	if (data->width - 1 > 0 && data->minus == 0)
		symbs = print_space(data, 1);
	write(1, &c, 1);
	symbs++;
	if (data->minus == 1)
		symbs += print_space(data, 1);
	return (symbs);
}
