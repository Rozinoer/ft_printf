/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rank.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:42:06 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/21 18:43:21 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rank(unsigned long long num, unsigned long long base)
{
	int rank;

	if (num < 0)
		num = -num;
	rank = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		rank++;
	}
	return (rank);
}
