/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:21:07 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/19 20:21:43 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printflib.h"

int ft_print_c(const char *fmt, va_list ap, int len,  t_printf *tmp)
{
	int c;
	char sym;

	if (tmp->flag == '0')
		sym = tmp->flag;
	else
		sym = ' ';
	c = va_arg(ap, int);
	if (--tmp->width > 0)
	{
		if (tmp->flag == '-')
		{
			ft_putchar((char)c);
			if (tmp->width > 0)
				while (tmp->width-- != 0)
				{
					ft_putchar(sym);
					len++;
				}
		}
		else
		{
			while (tmp->width-- > 0)
			{
				ft_putchar(' ');
				len++;
			}
			ft_putchar((char)c);
		}
	} else
		ft_putchar((char)c);
	return ft_printf_aux(fmt, ap, len + 1);
}

int ft_print_proc(const char *fmt, va_list ap, int len,  t_printf *tmp)
{
	char c;

	if (tmp->flag == '0')
		c = tmp->flag;
	else
		c = ' ';
	if (--tmp->width > 0 && tmp->flag != '-')
	{
		while (tmp->width-- != 0) {
			ft_putchar(c);
			len++;
		}
		ft_putchar((char)*fmt);
	}
	else
	{
		ft_putchar((char)*fmt);
		if (tmp->width > 0)
			while (tmp->width-- != 0)
			{
				ft_putchar(c);
				len++;
			}
	}
	fmt++;
	return ft_printf_aux(fmt, ap, len + 1);
}
