/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:55:19 by danjimen          #+#    #+#             */
/*   Updated: 2024/02/07 13:55:19 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c)
{
	int	write_error;

	write_error = write(1, &c, 1);
	if (write_error < 0)
		return (-1);
	return (0);
}

int	ft_putstr_printf(char *str)
{
	int	write_error;

	if (!str)
		return ;
	while (*str)
	{
		write_error = ft_putchar_printf(*str);
		if (write_error < 0)
			return (-1);
		str++;
	}
	return (0);
}