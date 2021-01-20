/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:03:13 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/20 16:06:23 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printflib.h"

int		ft_seek_flags(const char *fmt, t_printf *tmp)
{
	int i;

	i = 1;
	if (*fmt == '-' || *fmt == '0' || *fmt == ' ')
	{
		tmp->flag = *fmt;
		while (*(fmt + 1) == '-' || *(fmt + 1) == '0')
		{
			if (*(fmt + 1) == '-')
				tmp->flag = '-';
			fmt++;
			i++;
		}
		if (tmp->flag == '0')
			tmp->flag_sym = '0';
		return (i);
	}
	return (0);
}

int		ft_seek_width(char *fmt, t_printf *tmp, va_list ap)
{
	int flag;
	int i;

	flag = 0;
	if (*fmt == '*')
	{
		i = va_arg(ap, int);
		if (i < 0)
		{
			tmp->flag = '-';
			tmp->flag_sym = ' ';
			i = -1 * i;
		}
		tmp->width = i;
		return (1);
	}
	while (*fmt == '0')
	{
		fmt++;
		flag++;
	}
	tmp->width = ft_atoi(fmt);
	if (tmp->width > 0)
		return (ft_rank(tmp->width, 10) + flag);
	return (0);
}

int		ft_seek_preci(char *fmt, t_printf *tmp, va_list ap)
{
	int i;

	i = 0;
	if (*fmt++ == '.')
	{
		while (*fmt == '0')
		{
			fmt++;
			i++;
		}
		if (*fmt == '*')
		{
			tmp->preci = va_arg(ap, int);
			return (2);
		}
		else if (ft_isdigit(*fmt))
			tmp->preci = ft_atoi(fmt);
		else
		{
			tmp->preci = 0;
			return (1 + i);
		}
		return (ft_rank(tmp->preci, 10) + 1 + i);
	}
	return (0);
}

int		ft_seek_type(const char *fmt, t_printf *tmp)
{
	if (*fmt == '%')
	{
		tmp->type = '%';
		return (0);
	}
	if (*fmt == 's' || *fmt == 'c' || *fmt == 'd' || *fmt == 'o'
			|| *fmt == 'u' || *fmt == 'x' || *fmt == 'X'
			|| *fmt == 'p' || *fmt == 'i')
	{
		tmp->type = *fmt;
		return (1);
	}
	return (0);
}
