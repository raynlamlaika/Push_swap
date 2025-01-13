/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:54:00 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/13 12:16:34 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min_unsorted(t_list *stack_a, int sorted_count)
{
	t_list	*current = stack_a;
	t_list	*min = NULL;
	int		index = 0;

	while (current)
	{
		if (index >= sorted_count && (!min || *current->data < *min->data))
			min = current;
		current = current->next;
		index++;
	}
	return (min);
}

static void	rotate_to_top(t_list **stack_a, int steps)
{
	while (steps > 0)
	{
		rotate_a(stack_a);
		steps--;
	}
	while (steps < 0)
	{
		reverse_rotate_a(stack_a);
		steps++;
	}
}

void sort_three(t_list **stack)
{
    int top = *(*stack)->data;
    int mid = *(*stack)->next->data;
    int bot = *(*stack)->next->next->data;
    if (top > mid && mid > bot)
    {
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    else if (top > bot && bot > mid)
        rotate_a(stack);
    else if (mid > top && top > bot)
        reverse_rotate_a(stack);
    else if (mid > bot && bot > top)
    {
        swap_a(stack);
        rotate_a(stack);
    }
    else if (bot > top && top > mid)
        swap_a(stack);
}


void sort_small_stack(t_list **stack_a, t_list **stack_b)
{
    while (ft_lstsize(*stack_a) > 3)
    {
        t_list *min = find_min(*stack_a);
        int rotations = nbt_rotations_needed(*stack_a, min);

        if (rotations > ft_lstsize(*stack_a) / 2)
            rotations -= ft_lstsize(*stack_a);

        rotate_to_top(stack_a, rotations);
        push_b(stack_b, stack_a);
    }
    sort_three(stack_a);
    while (*stack_b)
        push_a(stack_a, stack_b);
}
