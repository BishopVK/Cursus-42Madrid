/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:06:46 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/11 19:06:46 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cc push_swap.c push_swap.a libft/libft.a printf/libftprintf.a
#define MAX_NUMBERS 500

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        ft_printf("Uso: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    if (argc - 1 > MAX_NUMBERS) {
        ft_printf("Se excedió el límite de %d números enteros.\n", MAX_NUMBERS);
        return 1;
    }

    int numbers[MAX_NUMBERS];
    int i, num;

    for (i = 1; i < argc; i++) {
        num = atoi(argv[i]);
        if (num == 0 && argv[i][0] != '0') {
            ft_printf("Error: '%s' no es un número entero válido.\n", argv[i]);
            return 1;
        }
        numbers[i - 1] = num;
    }

    qsort(numbers, argc - 1, sizeof(int), compare);

    ft_printf("Números ordenados: ");
    for (i = 0; i < argc - 1; i++) {
        ft_printf("%d ", numbers[i]);
    }
    ft_printf("\n");

    return 0;
}