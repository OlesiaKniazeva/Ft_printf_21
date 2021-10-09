#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		symbs;

	va_start(args, str);
	symbs = ft_madeall(str, args);
	va_end(args);
	return (symbs);
}
