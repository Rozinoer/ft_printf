#include "../includes/libft.h"

int ft_rank(unsigned long long num, unsigned long long base)
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

