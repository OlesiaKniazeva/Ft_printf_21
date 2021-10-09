#include "includes/ft_printf.h"

int	printstring(va_list args, int symbs, t_spec *data)
{
	char	*c;
	int		len;

	c = va_arg(args, char *);
	if (c == NULL)
		c = "(null)";
	len = ft_strlen(c);
	if (data->precision < len && data->precision != -1)
		len = data->precision;
	if ((data->width - len) > 0 && data->minus == 0)
		symbs += print_space(data, len);
	write(1, c, len);
	symbs += len;
	if (data->minus == 1)
		symbs += print_space(data, len);
	return (symbs);
}
