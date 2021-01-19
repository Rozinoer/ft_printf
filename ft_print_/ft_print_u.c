#include "../includes/printflib.h"

static char* check_preci(unsigned int n, char *num, t_printf *temp)
{
	char *tmp;

	if (temp->preci > ft_rank(n))
	{
		temp->preci = temp->preci - ft_rank(n);
		num = ft_itoa(n);
		while (temp->preci-- > 0)
		{
			tmp = num;
			num = ft_strjoin("0\0", num);
			if (*num == '0')
				free(tmp);
		}
	}
	else
		num = ft_itoa(n);
	return (num);
}

static int print_min(t_printf *tmp, unsigned int n, char *num)
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

static int print(t_printf *tmp, unsigned int n, char *num)
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

static int check_flag(t_printf *tmp, unsigned int n)
{
	int len;
	char *num;

	num = NULL;
	if (tmp->preci == 0 && n == 0)
	{
		num = malloc(1);
		num[0] = '\0';
	}
	else
		num = check_preci(n, num, tmp);
	if (tmp->flag == '-')
		len = print_min(tmp, n, num);
	else
		len = print(tmp, n, num);
	return (len);
}

int ft_print_u(const char *fmt, va_list ap, int len,  t_printf *tmp)
{
	unsigned int n;

	n = va_arg(ap, unsigned int);
	if (tmp->preci >= 0 && tmp->flag == '0')
	{
		tmp->flag = 0;
		tmp->flag_sym = ' ';
	}
	len+=check_flag(tmp,n);
	return ft_printf_aux(fmt, ap, len);
}
