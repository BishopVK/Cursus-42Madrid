/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen <danjimen@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:33:40 by danjimen          #+#    #+#             */
/*   Updated: 2024/03/29 13:33:40 by danjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static int find_median(t_stack_node *stack, int len)
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
} */

/* static void insertion_sort(t_stack_node **stack_a, int len)
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
} */

void quicksort(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
	if (size <= 1)
		return;

	// Move pivot to stack_b
	pb(stack_a, stack_b);

	// Partition stack_a into smaller and greater
	t_stack_node *pivot = *stack_b;
	int smaller_count = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if ((*stack_a)->order < pivot->order)
		{
			pb(stack_a, stack_b);
			smaller_count++;
		}
		else
		{
			ra(stack_a);
		}
	}

	// Recursively sort smaller elements
	quicksort(stack_b, stack_a, smaller_count);

	// Move pivot back to stack_a
	pa(stack_a, stack_b);

	// Move sorted smaller elements back to stack_a
	for (int i = 0; i < smaller_count; i++)
	{
		rra(stack_a);
	}

	// Recursively sort greater elements
	quicksort(stack_a, stack_b, size - smaller_count - 1);
}

/* void quicksort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;

	t_stack_node *pivot = *stack_a;
	t_stack_node *current = (*stack_a)->next;
	t_stack_node *smaller = NULL;
	t_stack_node *greater = NULL;

	while (current != NULL)
	{
		t_stack_node *next = current->next;
		if (current->nb < pivot->nb)
		{
			current->next = smaller;
			smaller = current;
		}
		else
		{
			current->next = greater;
			greater = current;
		}
		current = next;
	}

	quicksort(&smaller, stack_b);
	quicksort(&greater, stack_b);

	*stack_a = smaller;
	if (smaller != NULL)
	{
		while (smaller->next != NULL)
			smaller = smaller->next;
		smaller->next = pivot;
	}
	else
		*stack_a = pivot;
	pivot->next = greater;
} */

/* 
void quicksort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;

	t_stack_node *pivot = *stack_a;
	t_stack_node *smaller = NULL;
	t_stack_node *greater = NULL;

	partition(*stack_a, pivot, &smaller, &greater);
	quicksort(&smaller, stack_b);
	quicksort(&greater, stack_b);

	*stack_a = merge(smaller, pivot, greater);
}

void partition(t_stack_node *head, t_stack_node *pivot, t_stack_node **smaller, t_stack_node **greater)
{
	t_stack_node *current = head->next;

	while (current != NULL)
	{
		t_stack_node *next = current->next;
		if (current->nb < pivot->nb)
		{
			current->next = *smaller;
			*smaller = current;
		}
		else
		{
			current->next = *greater;
			*greater = current;
		}
		current = next;
	}
}

t_stack_node *merge(t_stack_node *smaller, t_stack_node *pivot, t_stack_node *greater)
{
	t_stack_node *merged = smaller;

	if (smaller != NULL)
	{
		while (smaller->next != NULL)
			smaller = smaller->next;
		smaller->next = pivot;
	}
	else
		merged = pivot;

	pivot->next = greater;

	return merged;
}
 */