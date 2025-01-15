/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opperations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:11 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/10 10:00:55 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): swap the first tow elemment in Stack_a.
int	swap_a(t_list **stack_a)
{
	t_list	*top;
	t_list	*tmp;

	if (!*stack_a || ft_lstsize(*stack_a) < 2)
		return (0);
	top = *stack_a;
	tmp = top->next;
	top->next = tmp->next;
	tmp->next = top;
	*stack_a = tmp;
	putstr("sa\n");
	return (1);
}

// sb (swap b): swap the first tow elemment in Stack_b
int	swap_b(t_list **stack_b)
{
	t_list	*top;
	t_list	*tmp;

	if (!*stack_b || ft_lstsize(*stack_b) < 2)
		return (0);
	top = *stack_b;
	tmp = top->next;
	top->next = tmp->next;
	tmp->next = top;
	*stack_b = tmp;
	putstr("sb\n");
	return (1);
}

int	swap_ab(t_list **stack_b, t_list **stack_a)
{
	if (!(swap_a(stack_b)) || !(swap_b(stack_a)))
		return (0);
	putstr("ss\n");
	return (1);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (!*stack_b)
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
	putstr("pa\n");
}
