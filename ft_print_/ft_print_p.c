#include "../includes/printflib.h"

static int print_min(t_printf *tmp, char *num)
{
	int i;
	int len;

	len = 0;
	i = tmp->width - ft_strlen(num);
	if (i > 0)
	{
		ft_putstr(num);
		len += ft_strlen(num);
		while (i-- > 0)
			len += ft_putchar(tmp->flag_sym);
	} else
	{
		ft_putstr(num);
		len += ft_strlen(num);
	}
	free(num);
	return (len);
}

static int print(t_printf *tmp, char *num)
{
	int i;
	int len;

	len = 0;
	i = tmp->width - ft_strlen(num);
	if (i > 0)
	{
		while (i-- > 0)
			len += ft_putchar(tmp->flag_sym);
		ft_putstr(num);
		len += ft_strlen(num);
	} else
	{
		ft_putstr(num);
		len += ft_strlen(num);
	}
	free(num);
	return (len);
}

static char* check_preci(unsigned int n, char *num, t_printf *temp)
{
	char *tmp;

	tmp = convert(n, 16, "0123456789abcdef", temp);
	if (*tmp == '0')
		num = ft_strjoin("0x", tmp);
	else
		num = ft_strjoin("0x10", tmp);
	free(tmp);
	return (num);
}

static int check_flag(t_printf *tmp, unsigned int n)
{
	int len;
	char *num;

	num = NULL;
	num = check_preci(n, num, tmp);
	if (tmp->flag == '-')
		len = print_min(tmp, num);
	else
		len = print(tmp, num);
	return (len);
}

int ft_print_p(const char *fmt, va_list ap, int len,  t_printf *tmp)
{
	unsigned int val;

	val = va_arg(ap, unsigned int);
	len += check_flag(tmp, val);
	return ft_printf_aux(fmt, ap, len);
}