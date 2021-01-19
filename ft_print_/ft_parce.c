/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:18:46 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/19 20:20:52 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printflib.h"

void	init_format(t_printf *tmp)
{
	tmp->flag = 0;
	tmp->width = 0;
	tmp->preci = -1;
	tmp->type = 0;
	tmp->flag_sym = ' ';
	tmp->sign = 0;
}

int		ft_parse(const char *fmt, t_printf *tmp, va_list ap)
{
	int		i;
	int		val;

	val = 0;
	while (1)
	{
		i = ft_seek_flags(fmt, tmp);
		fmt = (fmt + i);
		val = val + i;
		i = ft_seek_width((char *)fmt, tmp, ap);
		fmt = (fmt + i);
		val = val + i;
		i = ft_seek_preci((char *)fmt, tmp, ap);
		fmt = (fmt + i);
		val = val + i;
		i = ft_seek_type(fmt, tmp);
		val = val + i;
		break ;
	}
	return (val);
}
