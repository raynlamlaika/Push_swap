/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:00:30 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/11 21:20:28 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*top_a;

	if (!*stack_a)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
}

//rr : ra and rb at the same time.
int	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	if (!(rotate_a(stack_a)) || !(rotate_b(stack_b)))
		return (0);
	return (1);
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}
