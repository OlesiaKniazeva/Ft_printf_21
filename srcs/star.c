#include "includes/ft_printf.h"

char	*star(const char *str, t_spec *data, va_list args)
{
	int	a;

	a = va_arg(args, int);
	if (a < 0)
	{
		data->minus = 1;
		data->width = (-1) * a;
	}
	else
		data->width = a;
	str++;
	return ((char *)str);
}
