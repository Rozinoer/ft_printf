#include "../includes/libft.h"

int	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s != 0)
		while (*s)
		{
			ft_putchar(*s++);
			i++;
		}
	return (i);
}