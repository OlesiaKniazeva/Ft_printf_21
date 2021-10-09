#include "includes/ft_printf.h"

static int	print_for_zero(t_spec *data, int symbs)
{
	if (data->minus == 0 && data->width > 2)
		symbs += print_space(data, 2);
	write(1, "0x", 2);
	symbs += 2;
	if (data->minus == 1 && data->width > 2)
		symbs += print_space(data, 2);
	return (symbs);
}

static int	ft_printadr(unsigned long adr, int symbs, t_spec *data)
{
	char	*sixtnnumb;
	int		len;	

	if (data->precision == 0 && adr == 0)
	{
		symbs += print_for_zero(data, symbs);
		return (symbs);
	}
	sixtnnumb = tosixtin(adr);
	len = ft_strlen(sixtnnumb) + 2;
	if (data->minus == 0 && data->width - len > 0)
		symbs += print_space(data, len);
	write(1, "0x", 2);
	symbs += 2;
	write (1, sixtnnumb, len - 2);
	symbs += len - 2;
	if (sixtnnumb)
		free(sixtnnumb);
	if (data->minus == 1 && data->width - len > 0)
		symbs += print_space(data, len);
	return (symbs);
}

int	printaddress(va_list args, int symbs, t_spec *data)
{
	unsigned long	adr;

	adr = va_arg(args, unsigned long);
	symbs += ft_printadr(adr, symbs, data);
	return (symbs);
}
