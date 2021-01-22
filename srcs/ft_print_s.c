/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:53:39 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/20 15:57:45 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static int		print_width_minus(int width, int len, const char *s)
{
	while (*s)
	{
		ft_putchar(*s++);
		len++;
	}
	while (width-- > 0)
	{
		ft_putchar(' ');
		len++;
	}
	return (len);
}

static int		print_width(int width, int flag, int len)
{
	if (flag == 0)
	{
		while (width-- > 0)
		{
			ft_putchar(' ');
			len++;
		}
	}
	else if (flag == '0')
		while (width-- > 0)
		{
			ft_putchar('0');
			len++;
		}
	return (len);
}

static char		*preci(int preci, const char *s, char *new_s)
{
	int len;

	len = preci + 1;
	if (s != NULL)
	{
		new_s = malloc(len);
		len--;
		new_s[len] = '\0';
		new_s = ft_memcpy(new_s, s, preci);
	}
	else
	{
		new_s = malloc(len);
		len--;
		new_s[len] = '\0';
		new_s = ft_memcpy(new_s, "(null)", preci);
	}
	return (new_s);
}

static void		str_free(char *s, int flag)
{
	if (flag >= 0)
		free(s);
}

int				ft_print_s(const char *fmt, va_list ap, int len, t_printf *tmp)
{
	const char	*s;
	char		*new_s;

	s = va_arg(ap, const char *);
	new_s = (char *)s;
	if (s == NULL)
		new_s = "(null)";
	if (tmp->preci >= 0)
		new_s = preci(tmp->preci, s, new_s);
	if (tmp->width > 0)
	{
		if (tmp->flag != '-')
			len = print_width(tmp->width - ft_strlen(new_s), tmp->flag, len);
		else if (tmp->flag == '-')
		{
			len = (print_width_minus(tmp->width - ft_strlen(new_s),
						len, new_s));
			str_free(new_s, tmp->preci);
			return (ft_printf_aux(fmt, ap, len));
		}
	}
	len += ft_putstr(new_s);
	str_free(new_s, tmp->preci);
	return (ft_printf_aux(fmt, ap, len));
}
