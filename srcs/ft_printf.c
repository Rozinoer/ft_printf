/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:06:44 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/20 16:13:11 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static int	call_func(const char *fmt, va_list ap, int len, t_printf *tmp)
{
	int		i;
	char	*type;

	i = -1;
	type = "csdixXup%";
	while (*type)
	{
		if (tmp->type == *type)
		{
			(*type == 'c') ? i = ft_print_c(fmt, ap, len, tmp) : i;
			(*type == 's') ? i = ft_print_s(fmt, ap, len, tmp) : i;
			(*type == 'd') ? i = ft_print_d(fmt, ap, len, tmp) : i;
			(*type == 'i') ? i = ft_print_d(fmt, ap, len, tmp) : i;
			(*type == 'x') ? i = ft_print_x(fmt, ap, len, tmp) : i;
			(*type == 'X') ? i = ft_print_x(fmt, ap, len, tmp) : i;
			(*type == 'u') ? i = ft_print_u(fmt, ap, len, tmp) : i;
			(*type == 'p') ? i = ft_print_p(fmt, ap, len, tmp) : i;
			(*type == '%') ? i = ft_print_proc(fmt, ap, len, tmp) : i;
			break ;
		}
		type++;
	}
	return (i);
}

int			ft_printf_aux(const char *fmt, va_list ap, int len)
{
	int			c;
	t_printf	tmp;
	int			i;

	init_format(&tmp);
	while (*fmt)
	{
		c = (unsigned char)*fmt++;
		if (c != '%')
			len += ft_putchar((char)c);
		else
		{
			i = ft_parse(fmt, &tmp, ap);
			if ((len = call_func(fmt + i, ap, len, &tmp)) > -1)
				return (len);
			else
			{
				if (tmp.type == '\0')
					break ;
				len += ft_putchar((char)tmp.type);
				fmt++;
			}
		}
	}
	return (len);
}

char		*convert(unsigned long long n, unsigned int base,
		const char *digits, t_printf *tmp)
{
	int		res;
	char	*dig;

	res = ft_rank(n, 16);
	if (!(dig = malloc(res + 1)))
		return (NULL);
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

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;

	va_start(ap, fmt);
	n = ft_printf_aux(fmt, ap, 0);
	va_end(ap);
	return (n);
}
