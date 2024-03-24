#include <stdio.h>

void	suma(int *nbr)
{
	*nbr += 1;
}

int	main(void)
{
	int	nbr;

	nbr = 0;
	printf("nbr = %d\n", nbr);
	suma(&nbr);
	printf("nbr = %d\n", nbr);
	return (0);
}