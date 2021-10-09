#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_spec
{
	char	type;
	int		width;
	int		minus;
	int		zero;
	int		precision;
}	t_spec;

int		ft_printf(const char *str, ...);
int		ft_madeall(const char *str, va_list args);
void	ft_init(t_spec	*data);
char	*ft_readspec(const char *str, t_spec *data, va_list args);
char	*zeroflag(const char *str, t_spec *data);
char	*minusflag(const char *str, t_spec *data);
char	*width(const char *str, t_spec *data);
char	*precision(const char *str, t_spec *data, va_list args);
char	*star(const char *str, t_spec *data, va_list args);
int		ft_printspec(t_spec *data, va_list args);
int		printsymb(va_list args, int	symbs, t_spec *data);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		printstring(va_list args, int symbs, t_spec *data);
int		printaddress(va_list args, int symbs, t_spec *data);
char	*tosixtin(unsigned long adr);
char	*tosixteenlow(unsigned int num);
char	*tosixteenhigh(unsigned int num);
int		print_space(t_spec *data, int len);
int		printnum(va_list args, int symbs, t_spec *data);
int		print_zero(t_spec *data, int len);
int		print_zero_precision(t_spec *data, int len);
char	*ft_itoa(int n);
int		printpositive(char *num, int len, int symbs, t_spec *data);
int		printnegative(char *num, int len, int symbs, t_spec *data);
int		printunsignednum(va_list args, int symbs, t_spec *data);
int		printsixteen(va_list args, int symbs, t_spec *data);
int		printother(int symbs, t_spec *data);

#endif
