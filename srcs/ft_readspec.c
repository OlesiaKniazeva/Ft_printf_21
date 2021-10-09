#include "includes/ft_printf.h"

char	*ft_readspec(const char *str, t_spec *data, va_list args)
{
	str++;
	if (!*str)
		return ((char *) str);
	while (*str == '-' || *str == '0' || *str == '*'
		|| *str == '.' || (*str >= '0' && *str <= '9'))
	{
		if (*str == '0')
			str = zeroflag(str, data);
		if (*str == '-')
			str = minusflag(str, data);
		if (*str > '0' && *str <= '9')
			str = width(str, data);
		if (*str == '.')
			str = precision(str, data, args);
		if (*str == '*')
			str = star(str, data, args);
	}
	data->type = *str;
	if (*str)
		str++;
	return ((char *)str);
}
