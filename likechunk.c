/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   likechunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:47:32 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/07 16:00:46 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_index(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		tmp1->index = 0;
		tmp1 = tmp1->next;
	}
	tmp1 = lst;
	while (tmp1)
	{
		tmp2 = lst;
		while (tmp2)
		{
			if (*tmp1->data > *tmp2->data)
				tmp1->index++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int	value_of_j(t_list **stack)
{
	int	j;
	int	list_size;

	list_size = ft_lstsize(*stack) - 1;
	j = 0;
	if (list_size > 100)
		return (j = 35);
	else if (list_size < 100)
		return (j = 15);
	else
		return (j = 20);
	return (j);
}

void	set_position(t_list *stack)
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

int	max_node_positon(t_list *stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = stack;
	max = tmp;
	while (tmp)
	{
		if (*tmp->data > *max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max->position_in_stack);
}

void	move_back_to_a(t_list **a, t_list **b, int size_of_stack)
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

void	sort_big(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = value_of_j(&stack_a);
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
	move_back_to_a(stack_a, stack_b, size);
}
