#include "includes/ft_printf.h"

char	*minusflag(const char *str, t_spec *data)
{
	data->minus = 1;
	data->zero = 0;
	str++;
	return ((char *)str);
}
