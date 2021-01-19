#include "../includes/libft.h"

int ft_rank(long int num)
{
	int rank;

	if (num < 0)
		num = -num;
	rank = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		rank++;
	}
	return (rank);
}

