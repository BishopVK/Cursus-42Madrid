/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:38:49 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/14 00:25:39 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*uc_str;

	uc_str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (uc_str[i] == (unsigned char)c)
			return ((void *)(uc_str + i));
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char *str = "Hola, mundo!";
    char c = 'n';
    size_t num = strlen(str);

    void *result = ft_memchr(str, c, num);

    if (result != NULL) {
        printf("Byte encontrado: %c\n", *(char *)result);
    } else {
        printf("Byte no encontrado\n");
    }

	return (0);
}*/