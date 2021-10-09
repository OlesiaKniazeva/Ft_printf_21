#include "includes/ft_printf.h"

char	*zeroflag(const char *str, t_spec *data)
{
	if (data->minus == 1)
		data->zero = 0;
	else
		data->zero = 1;
	str++;
	return ((char *)str);
}
