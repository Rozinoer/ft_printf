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
	}
	else
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
		if (tmp->flag == '0' && tmp->sign == '-')
		{
			len += ft_putchar('-');
			i--;
		}
		while (i-- > 0)
			len += ft_putchar(tmp->flag_sym);
		ft_putstr(num);
		len += ft_strlen(num);
	}
	else
	{
		ft_putstr(num);
		len += ft_strlen(num);
	}
	free(num);
	return (len);
}

static char* check_preci(int n, char *num, t_printf *temp)
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
			free(tmp);
		}
	}
	else
		num = ft_itoa(n);
	if (temp->sign == '-' && (temp->flag != '0' ||
	temp->width== ft_strlen(num) || temp->width == 0 || temp->width < ft_strlen(num)))
	{
		tmp = num;
		num = ft_strjoin("-", num);
		free(tmp);
	}
	return (num);
}

static int check_flag(t_printf *tmp, int n)
{
	int len;
	char *num;
	char *str;

	num = NULL;
	if (tmp->preci == 0 && n == 0)
	{
		num = malloc(1);
		num[0] = '\0';
	}
	else
		num = check_preci(n, num, tmp);
	if (tmp->flag == ' ')
	{
		str = num;
		num = ft_strjoin(" ", num);
		free(str);
	}
	if (tmp->flag == '-')
		len = print_min(tmp, num);
	else
		len = print(tmp,num);
	return (len);
}
int ft_print_d(const char *fmt, va_list ap, int len,  t_printf *tmp)
{
	int n ;

	n = va_arg(ap, int);
	if (tmp->preci >= 0 && tmp->flag == '0')
	{
		tmp->flag = 0;
		tmp->flag_sym = ' ';
	}
	if (n < 0 && n != -2147483648)
	{
		tmp->sign = '-';
		n = -1 * n;
	}
	len +=check_flag(tmp,n);
	return ft_printf_aux(fmt, ap, len);
}

