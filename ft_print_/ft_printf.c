#include "../includes/printflib.h"

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
			if (ft_print_dispatch[tmp.type] == NULL)
			{
				if (c == '\0')
					break;
				ft_putchar((char)c);
				len++;
				fmt++;
			} else
				return ft_print_dispatch[c](fmt + i, ap, len, &tmp);
		}
	}
	return len;
}

char* convert(unsigned int n, unsigned int base, const char *digits, t_printf *tmp)
{
	int res;
	unsigned long long temp;
	char* dig;

	temp = n;
	res = 1;
	if (n == 0)
		res++;
	while (n > 0)
	{
		res++;
		n = n / base;
	}
	dig = malloc(res);
	dig[--res] = '\0';
	while (--res >= 0)
	{
		if (tmp->type == 'X')
			dig[res] = (char)ft_toupper(digits[temp % base]);
		else
			dig[res] = digits[temp % base];
		temp = temp / base;
	}
	return (dig);
}

int ft_vprintf(const char *fmt, va_list ap)
{
	return ft_printf_aux(fmt, ap, 0);
}

int ft_printf(const char *fmt, ...) {
	va_list ap;
	int n;
	va_start(ap, fmt);
	n = ft_printf_aux(fmt, ap, 0);
	va_end(ap);
	return n;
}
