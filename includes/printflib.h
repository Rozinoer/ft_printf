/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:45:58 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/19 21:06:22 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINTFLIB_H
# define FT_PRINTF_PRINTFLIB_H

# include "stdarg.h"
# include "../libft/libft.h"

typedef struct	s_printf
{
	char		flag;
	long long	width;
	long long	preci;
	char		type;
	char		flag_sym;
	int			sign;
}				t_printf;

int				ft_print_c(const char *fmt, va_list ap, int len, t_printf *tmp);
int				ft_print_d(const char *fmt, va_list ap, int len, t_printf *tmp);
int				ft_print_s(const char *fmt, va_list ap, int len, t_printf *tmp);
int				ft_print_u(const char *fmt, va_list ap, int len, t_printf *tmp);
int				ft_print_x(const char *fmt, va_list ap, int len, t_printf *tmp);
int				ft_print_p(const char *fmt, va_list ap, int len, t_printf *tmp);
int				ft_print_proc(const char *fmt, va_list ap,
				int len, t_printf *tmp);
int				ft_printf_aux(const char *fmt, va_list ap, int len);
char			*convert(unsigned long long n, unsigned int base,
				const char *digits, t_printf *tmp);
int				ft_parse(const char *fmt, t_printf *tmp, va_list ap);
int				ft_seek_flags(const char *fmt, t_printf *tmp);
int				ft_seek_width(char *fmt, t_printf *tmp, va_list ap);
int				ft_seek_preci(char *fmt, t_printf *tmp, va_list ap);
int				ft_seek_type(const char *fmt, t_printf *tmp);
void			init_format(t_printf *tmp);
int				ft_printf(const char *fmt, ...);

#endif
