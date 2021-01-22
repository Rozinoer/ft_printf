/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:14:09 by dmyesha           #+#    #+#             */
/*   Updated: 2020/11/17 19:08:25 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_maxminint(long int n, char *dst)
{
	int len;

	len = ft_nbrlen(n);
	if (!(dst = (char *)malloc(len + 1)))
		return (NULL);
	if (n == -2147483648)
		dst = ft_strcpy(dst, "-2147483648");
	if (n == 2147483647)
		dst = ft_strcpy(dst, "2147483647");
	return (dst);
}

static char	*ft_fill(long int n, char *dst, int len)
{
	*(dst + len--) = '\0';
	if (n == 0)
	{
		*dst = '0';
		return (dst);
	}
	if (n < 0)
	{
		*dst = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		*(dst + (len--)) = n % 10 + '0';
		n = n / 10;
	}
	return (dst);
}

char		*ft_itoa(long int n)
{
	char		*dst;
	int			len;

	if (n == -2147483648)
	{
		dst = NULL;
		dst = ft_maxminint(n, dst);
		return (dst);
	}
	len = ft_nbrlen(n);
	if (!(dst = (char *)malloc(len + 1)))
		return (NULL);
	dst = ft_fill(n, dst, len);
	return (dst);
}
