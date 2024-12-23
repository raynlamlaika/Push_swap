/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opperations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:17:11 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/23 16:17:52 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"



// sa (swap a): swap the first tow elemment in Stack_a.
void	*swap_a(l_list **stack_a)
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
	return (1);
}

// sb (swap b): swap the first tow elemment in Stack_b
void	*swap_b(l_list **stack_b)
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
	return (1);
}

//ss : sa and sb at the same time
void	*swap_ab(l_list **stack_b, l_list **stack_a)
{
	if (!(swap_a(&stack_b)) && !(swap_b(&stack_a)))
		return (0);
	return (1);
}

//pa (push a): Take the first element at the top of b and put it at the top of a.
void	push_a(l_list *stack_b, l_list *stack_a)
{
	l_list	*take_a;
	l_list	*take_b;

	if (!stack_b || ft_lstsize(stack_b) < 1 || !stack_a)
		return (0);
	take_a = stack_a;
	take_b = stack_b;
	take_a->next = take_b;
	stack_a = stack_a->next;
	printf("lets seee %s",stack_a->data);
	
	return ;
}

//pb (push b): Take the first element at the top of a and put it at the top of b.

//ra (rotate a): Shift up all elements of stack a by 1.

//rb (rotate b): Shift up all elements of stack b by 1.

//rr : ra and rb at the same time.

//rra (reverse rotate a): Shift down all elements of stack a by 1

//rrb (reverse rotate b): Shift down all elements of stack b by 1.

//rrr : rra and rrb at the same time.

// SORTING ALGOOOOO

