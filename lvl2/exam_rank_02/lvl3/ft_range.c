/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:01:30 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/19 10:27:01 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	*result;
	int	i;

	if (start == end)
		len = 1;
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	result = (int *)malloc((len + 1) * sizeof(int));
	result[len] = '\0';
	i = 0;
	while (i < len)
	{
		result[i] = start;
		if (start > end)
			start--;
		else if (start < end)
			start++;
		i++;
	}
	return (result);
}

/* int	main(int argc, char **argv)
{
	int	start;
	int	end;
	int	*result;

	start = 1;
	end = 3;
	result = ft_range(start, end);
	return (0);
} */
