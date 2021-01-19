#include "../includes/printflib.h"

static int call_func(const char *fmt, va_list ap, int len,  t_printf *tmp, char *type)
{
	int i;

	i = -1;
	while (*type)
	{
		if (tmp->type == *type)
		{
			if (*type == 'c')
				i = ft_print_c(fmt, ap, len, tmp);
			if (*type == 's')
				i = ft_print_s(fmt, ap, len, tmp);
			if (*type == 'd' || *type == 'i')
				i = ft_print_d(fmt, ap, len, tmp);
			if (*type == 'x' || *type == 'X')
				i = ft_print_x(fmt, ap, len, tmp);
			if (*type == 'u')
				i = ft_print_u(fmt, ap, len, tmp);
			if (*type == '%')
				i = ft_print_proc(fmt, ap, len, tmp);
			if (*type == 'p')
				i = ft_print_p(fmt, ap, len, tmp);
			break ;
		}
		type++;
	}
	return (i);
}

int ft_printf_aux(const char *fmt, va_list ap, int len)
{
	int c;
	t_printf tmp;
	int i;

	init_format(&tmp);
	while (*fmt) {
		c = (unsigned char)*fmt++;
		if (c != '%')
		{
			ft_putchar((char)c);
			len++;
		}else
		{
			i = ft_parse(fmt, &tmp, ap);
			c = (unsigned char)tmp.type;
			if ((len = call_func(fmt + i, ap, len, &tmp, "csXxdiup%")) > -1)
				return (len);
			else
			{
				if (c == '\0')
					break;
				ft_putchar((char)c);
				len++;
				fmt++;
			}
		}
	}
	return len;
}

char* convert(unsigned long long n, unsigned int base, const char *digits, t_printf *tmp)
{
	int res;
	char* dig;

	res = ft_rank(n, 16);
	if(!(dig = malloc(res)))
		return NULL;
	dig[res] = '\0';
	while (--res >= 0)
	{
		if (tmp->type == 'X')
			dig[res] = (char)ft_toupper(digits[n % base]);
		else
			dig[res] = digits[n % base];
		n = n / base;
	}
	return (dig);
}

int ft_printf(const char *fmt, ...) {
	va_list ap;
	int n;

	va_start(ap, fmt);
	n = ft_printf_aux(fmt, ap, 0);
	va_end(ap);
	return n;
}
