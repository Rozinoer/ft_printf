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
