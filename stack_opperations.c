/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opperations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:11 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/07 15:56:33 by rlamlaik         ###   ########.fr       */
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

void	push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*top_a;

	if (!*stack_a)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
	putstr("pb\n");
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
	putstr("ra\n");
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
	putstr("rb\n");
	return (1);
}

//rr : ra and rb at the same time.
int	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	if (!(rotate_a(stack_a)) || !(rotate_b(stack_b)))
		return (0);
	putstr("rr\n");
	return (1);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1
int	reverse_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*sec;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	last = ft_lstlast(*stack_a);
	sec = lst_second(*stack_a);
	last->next = *stack_a;
	*stack_a = last;
	sec->next = NULL;
	putstr("rra\n");
	return (1);
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1.
int	reverse_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*sec;

	if (!*stack_b || !(*stack_b)->next)
		return (0);
	last = ft_lstlast(*stack_b);
	sec = lst_second(*stack_b);
	last->next = *stack_b;
	*stack_b = last;
	sec->next = NULL;
	putstr("rrb\n");
	return (1);
}

//rrr : rra and rrb at the same time.
void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	putstr("rrr\n");
}
