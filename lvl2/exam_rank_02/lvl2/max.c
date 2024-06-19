/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 23:08:32 by danjimen          #+#    #+#             */
/*   Updated: 2024/06/19 09:53:49 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	unsigned int	higger;
	unsigned int	i;

	if (len == 0)
		return (0);
	i = 0;
	higger = tab[i];
	while (i < len)
	{
		if (tab[i] > higger)
			higger = tab[i];
		i++;
	}
	return (higger);
}
