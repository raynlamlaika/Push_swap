/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:09:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:02 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->data = content;
	p->next = NULL;
	return (p);
}

//find the most small number in stack
t_list	*find_min(t_list *stack_a)
{
	t_list	*min_in_stack;

	min_in_stack = stack_a;
	while (stack_a)
	{
		if (*(min_in_stack->data) > *(stack_a->data))
			min_in_stack = stack_a;
		stack_a = stack_a->next;
	}
	return (min_in_stack);
}

//the numer of rotations that we need to pick this smal number in stack
int	nbt_rotations_needed(t_list *stack_a, t_list *min)
{
	int	i;

	i = 0;
	while (stack_a != min)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	rotate_a(t_list **stack_a)
{
	t_list	*top;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	top = *stack_a;
	*stack_a = top->next;
	last = ft_lstlast(*stack_a);
	last->next = top;
	top->next = NULL;
	return (1);
}

//rb (rotate b): Shift up all elements of stack b by 1.
int	rotate_b(t_list **stack_b)
{
	t_list	*botton;
	t_list	*top;

	if (!*stack_b || !(*stack_b)->next)
		return (0);
	top = *stack_b;
	*stack_b = top->next;
	botton = ft_lstlast(*stack_b);
	botton->next = top;
	top->next = NULL;
	return (1);
}
