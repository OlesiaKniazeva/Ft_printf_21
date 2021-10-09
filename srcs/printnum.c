#include "includes/ft_printf.h"

int	printnum(va_list args, int symbs, t_spec *data)
{
	char	*num;
	int		len;

	num = ft_itoa(va_arg(args, int));
	len = ft_strlen(num);
	if (*num == '0' && data->precision == 0)
	{
		symbs += print_space(data, 0);
	}
	else if (*num == '-')
		symbs += printnegative(num, len, symbs, data);
	else
		symbs += printpositive(num, len, symbs, data);
	free (num);
	return (symbs);
}
