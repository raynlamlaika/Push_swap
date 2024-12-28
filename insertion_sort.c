/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:54:00 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/28 15:59:23 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find the most small number in stack
l_list *find_min(l_list *stack_a)
{
	l_list *min_in_stack;

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
int nbt_rotations_needed(l_list *stack_a, l_list *min)
{
	int i;

	i = 0;
	while (stack_a != min)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

//rotate to take the small number to the top (as number of retations taht we calulat prevesely)
void rotate_to_top(l_list **stack_a, int steps)
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


// push the must small number to the stack_B
void push_to_b(l_list **stack_a, l_list **stack_b);

//sorting stack b to "prepar it to push it into stack_a "
void sort_b(l_list **stack_b);

//push all the element back to the stack_a
void push_back_to_a(l_list **stack_a, l_list **stack_b);


// insertion algo rghit here 
void insertion_sort(l_list **stack_a, l_list **stack_b)
{

}

// Add necessary functions, e.g., ft_lstnew, ft_lstadd_back, rotate_a, reverse_rotate_a, etc.

