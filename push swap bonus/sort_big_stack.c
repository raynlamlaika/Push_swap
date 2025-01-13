/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:47:32 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/13 12:17:38 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunksize(t_list **stack_a)
{
	int	j;
	int	list_size;

	list_size = ft_lstsize(*stack_a) - 1;
	return (j =list_size / 10);
}

static void	set_position(t_list *stack)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = stack;
	while (curr)
	{
		curr->position_in_stack = i;
		i++;
		curr = curr->next;
	}
}

static void	move_back_to_a(t_list **a, t_list **b, int size_of_stack)
{
	int	max_node_position;

	size_of_stack = ft_lstsize(*b);
	while (size_of_stack)
	{
		set_position(*b);
		max_node_position = max_node_positon(*b);
		if (max_node_position < size_of_stack / 2)
		{
			while ((*b)->position_in_stack != max_node_position)
				rotate_b(b);
		}
		else
		{
			while ((*b)->position_in_stack != max_node_position)
				reverse_rotate_b(b);
		}
		push_a(a, b);
		size_of_stack--;
	}
}

//the main function to sort the big stack
void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = chunksize(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			push_b(stack_b, stack_a);
			i++;
		}
		else if ((*stack_a)->index < (i + chunk))
		{
			push_b(stack_b, stack_a);
			rotate_b(stack_b);
			i++;
		}
		else
		{
			rotate_a(stack_a);
		}
	}
	move_back_to_a(stack_a, stack_b, ft_lstsize(*stack_b));
}
