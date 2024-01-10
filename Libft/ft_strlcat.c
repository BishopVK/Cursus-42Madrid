/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:31:47 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/10 08:38:18 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <strings.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	dest_lenght;
	unsigned int	i;
	unsigned int	j;

	src_length = ft_strlen(src);
	i = 0;
	while (dest[i] != '\0')
		i++;
	dest_lenght = i;
	if (size <= dest_lenght)
		return (src_length + size);
	j = 0;
	while (src[j] != '\0' && j < size - dest_lenght - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (src_length + dest_lenght);
}

/*int	main(void)
{
	char			dest[20] = "Hola ";
	char			src[] = "mundo1234567890abcdefghi";
	unsigned int	length;

	length = ft_strlcat(dest, src, 20);
	printf("%s\n", dest);
	printf("%u\n", length);
	return (0);
}*/
