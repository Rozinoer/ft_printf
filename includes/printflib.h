
#ifndef FT_PRINTF_PRINTFLIB_H
#define FT_PRINTF_PRINTFLIB_H

#include "stdarg.h"
#include "libft.h"

typedef struct	s_printf
{
	char        flag;
	int         width;
	int			preci;
	char        type;
	char        flag_sym;
	int         sign;
}				t_printf;

int ft_print_c(const char *fmt, va_list ap, int len,  t_printf *tmp);
int ft_print_d(const char *fmt, va_list ap, int len,  t_printf *tmp);
int ft_print_s(const char *fmt, va_list ap, int len, t_printf *tmp);
int ft_print_u(const char *fmt, va_list ap, int len,  t_printf *tmp);
int ft_print_x(const char *fmt, va_list ap, int len,  t_printf *tmp);
int ft_print_p(const char *fmt, va_list ap, int len,  t_printf *tmp);
int ft_print_proc(const char *fmt, va_list ap, int len,  t_printf *tmp);
int ft_printf_aux(const char *fmt, va_list ap, int len);
char* convert(unsigned int n, unsigned int base, const char *digits, t_printf *tmp);
int ft_parse(const char *fmt, t_printf *tmp, va_list ap);
int ft_seek_flags(const char *fmt, t_printf *tmp);
int ft_seek_width(char *fmt, t_printf *tmp, va_list ap);
int ft_seek_preci(char *fmt, t_printf *tmp, va_list ap);
int ft_seek_type(const char *fmt, t_printf *tmp);
void	init_format(t_printf *tmp);


typedef int (*ft_print_dispatch_f)(const char *fmt, va_list ap, int len,  t_printf *tmp);

static ft_print_dispatch_f const ft_print_dispatch[256] = {
		['c'] = ft_print_c,
		['d'] = ft_print_d,
		['i'] = ft_print_d,
		['u'] = ft_print_u,
		['x'] = ft_print_x,
		['X'] = ft_print_x,
		['s'] = ft_print_s,
		['p'] = ft_print_p,
		['%'] = ft_print_proc,
};

int     ft_printf(const char *fmt, ...);

#endif
