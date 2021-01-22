/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:39:08 by dmyesha           #+#    #+#             */
/*   Updated: 2020/11/14 14:51:17 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long value;
	long s;

	value = 0;
	s = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			s = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str++ - '0');
		if (value == 999999999)
		{
			if (s == 1)
				return (-1);
			else
				return (0);
		}
	}
	return ((int)(s * value));
}
