#include "includes/ft_printf.h"

int	ft_printspec(t_spec *data, va_list args)
{
	int	symbs;

	symbs = 0;
	if (data->type == 'c')
		symbs = printsymb(args, symbs, data);
	else if (data->type == 's')
		symbs = printstring(args, symbs, data);
	else if (data->type == 'p')
		symbs = printaddress(args, symbs, data);
	else if (data->type == 'i' || data->type == 'd')
		symbs = printnum(args, symbs, data);
	else if (data->type == 'u')
		symbs = printunsignednum(args, symbs, data);
	else if (data->type == 'x' || data->type == 'X')
		symbs = printsixteen(args, symbs, data);
	else if (data->type == 0)
		return (0);
	else
		symbs = printother(symbs, data);
	return (symbs);
}
