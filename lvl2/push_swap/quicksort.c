/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:42:33 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/29 12:42:33 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_median(t_stack_node *stack, int len)
{
    int *arr;
    int i, j, key;
    int median;

    arr = (int *)malloc(sizeof(int) * len);
    if (!arr)
        return (-1);

    for (i = 0; i < len && stack; i++)
    {
        arr[i] = stack->nb;
        stack = stack->next;
    }

    // Ordenación por inserción
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    median = arr[len / 2];
    free(arr);

    return (median);
}

static void insertion_sort(t_stack_node **stack_a, int len)
{
    t_stack_node *stack_b = NULL;
    int i, j;

    for (i = 1; i < len; i++)
    {
        j = i;

        while (j > 0 && *stack_a && (*stack_a)->next && (*stack_a)->nb < (*stack_a)->next->nb)
        {
            ra(stack_a);
            j--;
        }

        pb(stack_a, &stack_b);
    }

    for (i = 0; i < len; i++)
        pa(&stack_b, stack_a);
}

void quicksort(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
    int pivot;
    int i;
    int len_less, len_greater;

    if (len < 2)
        return;

    if (len < 10)
    {
        insertion_sort(stack_a, len);
        return;
    }

    pivot = find_median(*stack_a, len);
    len_less = 0;
    len_greater = len;

    for (i = 0; i < len && *stack_a; i++)
    {
        if ((*stack_a)->nb <= pivot)
        {
            pb(stack_a, stack_b);
            len_less++;
            len_greater--;
        }
        else
        {
            ra(stack_a);
        }
    }

    quicksort(stack_b, stack_a, len_less);

    for (i = 0; i < len_less; i++)
    {
        pa(stack_b, stack_a);
    }

    quicksort(stack_a, stack_b, len_greater);
}