/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:28:39 by danjimen          #+#    #+#             */
/*   Updated: 2024/01/18 15:25:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int	negative;

	negative = 0;
	//1. Comprobar si es positivo o negativo
	if (n < 0)
		negative = 1;

	//2. Convertir el número a cadenas (comenzando desde el final)

	//3. Agregar el caracter Nulo

	//4. Manejar casos especiales (0, INT_MIN, INT_MAX, nº más grandes que INT, nº que comiencen por ceros...)
}

int	main(void)
{
    // Test 1: Número positivo
    int num1 = 12345;
    char* str1 = ft_itoa(num1);
    printf("Test 1: %d convertido a cadena: %s\n", num1, str1);
    free(str1);

    // Test 2: Número negativo
    int num2 = -9876;
    char* str2 = ft_itoa(num2);
    printf("Test 2: %d convertido a cadena: %s\n", num2, str2);
    free(str2);

    // Test 3: Número cero
    int num3 = 0;
    char* str3 = ft_itoa(num3);
    printf("Test 3: %d convertido a cadena: %s\n", num3, str3);
    free(str3);

    // Test 4: Número grande
    int num4 = 2147483647; // Máximo valor para un int en sistemas de 32 bits
    char* str4 = ft_itoa(num4);
    printf("Test 4: %d convertido a cadena: %s\n", num4, str4);
    free(str4);

    // Test 5: Número mínimo para un int en sistemas de 32 bits
    int num5 = -2147483648;
    char* str5 = ft_itoa(num5);
    printf("Test 5: %d convertido a cadena: %s\n", num5, str5);
    free(str5);

	// Test 6: Número positivo con muchos dígitos
    int num6 = 12345678901234567890;
    char* str6 = ft_itoa(num6);
    printf("Test 6: %d convertido a cadena: %s\n", num6, str6);
    free(str6);

    // Test 7: Número negativo con muchos dígitos
    int num7 = -99987654321;
    char* str7 = ft_itoa(num7);
    printf("Test 7: %d convertido a cadena: %s\n", num7, str7);
    free(str7);

    // Test 8: Número con varios ceros al principio
    int num8 = 0005000;
    char* str8 = ft_itoa(num8);
    printf("Test 8: %d convertido a cadena: %s\n", num8, str8);
    free(str8);

    // Test 9: Número con varios ceros al final
    int num9 = 120000;
    char* str9 = ft_itoa(num9);
    printf("Test 9: %d convertido a cadena: %s\n", num9, str9);
    free(str9);

    // Test 10: Número con varios ceros intermedios
    int num10 = 10203;
    char* str10 = ft_itoa(num10);
    printf("Test 10: %d convertido a cadena: %s\n", num10, str10);
    free(str10);

    return 0;
}
