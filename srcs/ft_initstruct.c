#include "includes/ft_printf.h"

void	ft_init(t_spec	*data)
{
	data->type = 0;
	data->width = 0;
	data->minus = 0;
	data->zero = 0;
	data->precision = -1;
}
