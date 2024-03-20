#include "push_swap.h"
#include <stdlib.h>

static void	no_repeat_numbers(t_stack *numbers)
{
    t_stack_node *current, *check;

    current = numbers->head;
    while (current != NULL)
    {
        check = current->next;
        while (check != NULL)
        {
            if (current->nb == check->nb)
            {
                printf("Número repetido: %d\n", current->nb);
                exit(1);
            }
            check = check->next;
        }
        current = current->next;
    }
}

static t_stack	*add_to_stack(t_stack *stack, int num)
{
    t_stack_node *new_node;

    new_node = (t_stack_node*)malloc(sizeof(t_stack_node));
    if (!new_node)
    {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    new_node->nb = num;
    new_node->next = stack->head;
    if (stack->head != NULL)
        stack->head->prev = new_node;
    stack->head = new_node;
    if (stack->tail == NULL)
        stack->tail = new_node;
    return stack;
}

static t_stack	*split_argvs(char *argv, t_stack *numbers)
{
    int		j;
    char	**split;

    split = ft_split(argv, ' ');
    j = 0;
    while (split[j] != NULL)
    {
        numbers = add_to_stack(numbers, atoi(split[j]));
        free(split[j]);
        j++;
    }
    free(split);
    return numbers;
}

int	parse_argvs(int argc, char **argv)
{
    int		i;
    t_stack	*numbers;

    numbers = (t_stack*)malloc(sizeof(t_stack));
    numbers->head = NULL;
    numbers->tail = NULL;
    i = 1;
    while (i < argc)
    {
        numbers = split_argvs(argv[i], numbers);
        i++;
    }
    no_repeat_numbers(numbers);
    return (0);
}