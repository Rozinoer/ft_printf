#include <stdio.h>
#include "includes/printflib.h"

char	*ft_utoa(unsigned int n,unsigned int base, const char *digits)
{
	char			*p;
	int				size;
	unsigned int	x;

	x = n;
	size = 1;
	while (x > 16)
	{
		x /= 16;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 16;
			p[size] = digits[x % base];
			n = n / 16;
			size--;
		}
	}
	return (p);
}

int main() {
	int am;
	int am1;
	char *p = "Hello";
	printf("   printf = [%p]\n", p);
	ft_printf("ft_printf = [%p]\n", p);
    return 0;
}
