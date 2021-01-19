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
	char *p1 = "Hello1";
	char *p2 = "Hello2";
	char *str = "white";

	printf("%p\n",p);
//	printf("%p\n",ft_utoa(p1,16,"0123456789abcdef"));
//	printf("%p\n",ft_utoa(p2,16,"0123456789abcdef"));
	am1 = printf("   printf = [%s]\n", ft_utoa(p,16,"0123456789abcdef"));
	am = ft_printf("ft_printf = [%p]\n", p);
	printf("\nmy printf = %d\nsystem printf = %d\n",am,am1);
	am1 = printf("   printf = [%p]\n", str);
	am = ft_printf("ft_printf = [%p]\n", str);
	printf("\nmy printf = %d\nsystem printf = %d\n",am,am1);
    return 0;
}
