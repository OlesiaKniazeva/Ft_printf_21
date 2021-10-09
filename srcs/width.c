#include "includes/ft_printf.h"

char	*width(const char *str, t_spec *data)
{
	data->width = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	return ((char *)str);
}
