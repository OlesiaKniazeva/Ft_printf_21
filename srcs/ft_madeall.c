#include "includes/ft_printf.h"

static int	ft_write(int symbs)
{
	symbs = 0;
	write(1, "%", 1);
	symbs++;
	return (symbs);
}

int	ft_madeall(const char *str, va_list args)
{
	int		symbs;
	t_spec	data;

	symbs = 0;
	while (*str)
	{
		while (*str == '%' && *(str + 1) == '%')
		{
			symbs += ft_write(symbs);
			str = str + 2;
		}
		if (*str == '%')
		{
			ft_init(&data);
			str = ft_readspec(str, &data, args);
			symbs += ft_printspec(&data, args);
		}
		if (*str != '%' && *str)
		{
			write(1, str, 1);
			symbs++;
			str++;
		}
	}
	return (symbs);
}
