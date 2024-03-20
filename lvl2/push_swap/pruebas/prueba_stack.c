#include "../push_swap.h"
#include "../libft/libft.h"
#include "../printf/ft_printf.h"

int	main(void)
{
	char	*str = "1 3 -5 4 8 6 9 0";
	char	**split;
	int		i = 0;

	split = ft_split(str, ' ');
	ft_printf("Print strings:\n");
	while (split[i] != NULL)
	{
		ft_printf("split[%d] = %s\n", i, split[i]);
		i++;
	}

	i = 0;
	ft_printf("Print ints:\n");
	while (split[i] != NULL)
	{
		ft_printf("split[%d] = %d\n", i, ft_atoi(split[i]));
		i++;
	}
	ft_printf("Print sum %d + %d:\n", ft_atoi(split[0]), ft_atoi(split[2]));
	ft_printf("%d\n", (ft_atoi(split[0]) + ft_atoi(split[2])));
	return (0);
}