#include "includes/ft_printf.h"

char	*precision(const char *str, t_spec *data, va_list args)
{
	int	a;

	str++;
	if (*str == '*')
	{
		a = va_arg(args, int);
		if (a >= 0)
			data->precision = a;
		str++;
	}
	else if (*str >= '0' && *str <= '9')
	{
		data->precision = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	else if (*str == '-')
	{
		minusflag(str, data);
		data->precision = 0;
	}
	else
		data->precision = 0;
	return ((char *)str);
}
