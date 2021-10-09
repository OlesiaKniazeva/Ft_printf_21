#include "includes/ft_printf.h"

int	printsixteenlow(va_list args, int symbs, t_spec *data)
{
	unsigned int	number;
	char			*num;
	int				len;

	number = va_arg(args, unsigned int);
	num = tosixteenlow(number);
	len = ft_strlen(num);
	if (*num == '0' && data->precision == 0)
		symbs += print_space(data, 0);
	else
		symbs += printpositive(num, len, symbs, data);
	free(num);
	return (symbs);
}
