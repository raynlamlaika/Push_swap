/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opperations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:11 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/06 16:30:46 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): swap the first tow elemment in Stack_a.
int	swap_a(l_list **stack_a)
{
	l_list	*top;
	l_list	*tmp;

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
int	swap_b(l_list **stack_b)
{
	l_list	*top;
	l_list	*tmp;

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

//ss : sa and sb at the same time
int	swap_ab(l_list **stack_b, l_list **stack_a)
{
	if (!(swap_a(stack_b)) || !(swap_b(stack_a)))
		return (0);
	putstr("ss\n");
	return (1);
}

//pa (push a): Take the first element at the top of b and put it at the top of a.
void push_a(l_list **stack_a, l_list **stack_b)
{
	l_list *top_b; // represent the top of stack B

	if (!*stack_b) 
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
	putstr("pa\n");
}

//pb (push b): Take the first element at the top of a and put it at the top of b.
void push_b(l_list **stack_b, l_list **stack_a)
{
	l_list *top_a; // represent the top of stack B

	if (!*stack_a) 
		return;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
	putstr("pb\n");
}

//ra (rotate a): Shift up all elements of stack a by 1.
int rotate_a(l_list **stack_a)
{
	l_list *top;
	l_list *last;

	if (!*stack_a || !(*stack_a)->next)
		return 0; 
	top = *stack_a;
	*stack_a = top->next;
	last = ft_lstlast(*stack_a);
	last->next = top;
	top->next = NULL;
	putstr("ra\n");
	return 1;
}

//rb (rotate b): Shift up all elements of stack b by 1.
int rotate_b(l_list **stack_b)
{
	l_list	*botton;
	l_list	*top;

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
int rotate_ab(l_list **stack_a, l_list **stack_b)
{
	if (!(rotate_a(stack_a)) || !(rotate_b(stack_b)))
		return (0);
	putstr("rr\n");
	return (1);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1
int reverse_rotate_a(l_list **stack_a)
{
	l_list *last;
	l_list *sec;

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
int reverse_rotate_b(l_list **stack_b)
{
	l_list *last;
	l_list *sec;

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
void reverse_rotate_ab(l_list **stack_a, l_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	putstr("rrr\n");
}
