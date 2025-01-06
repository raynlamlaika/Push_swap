/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   likechunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:47:32 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/06 10:59:02 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
// implemment the sorting index
int sort_index(l_list *lst)
{
	l_list *tmp1;
	l_list *tmp2;

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
	return  (1);
}

//the the position of i
int position()
{

	
}

// implemment the functionn to pick the value of the varible j(like size of every chunk)
int  value_of_j(l_list **stack)
{
	int j;
	int list_size;

	list_size = ft_lstsize(*stack) - 1;
	j = 0;
	if (list_size > 100)
		return (j = 35);
	else if (list_size < 100)
		return (j = 15);	
	else
		return(j = 20);


	return(j);
}


int mid(l_list **stack_b, int size)
{
	int i;
	l_list *curr;

	i = 0;
	curr = *stack_b;
	while (curr)
	{
		if(curr->index != size)
			i++;
		curr = curr->next;
	}
	return  (i);
}

// pick the func to pick the meduim
void therealsort(l_list **stack_a, l_list **stack_b)
{
	int i;
	int size;

	size = ft_lstsize(*stack_b) - 1;
	while (*stack_b)
	{
		i = mid(stack_b, size);
		size = ft_lstsize(*stack_b) -1;
		if ((*stack_b)->index == size)
			push_a(stack_a, stack_b);
		else if (size / 2 < i)
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
}

//the main function to sort the big stack
void sort_big(l_list **stack_a, l_list **stack_b)
{
	int i;
	int chunk;

	i = 0;
	chunk = 15; // it will be in deffrant val later
	while ((*stack_a))
	{
		if ((*stack_a)->index <= i)
			push_b(stack_b, stack_a);
		else if ((*stack_a)->index < (i + chunk))
		{
			push_b(stack_b, stack_a);
			rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
	}
	therealsort(stack_a, stack_b);
}



void	isitsorted(l_list **stack_a, l_list **stack_b)
{
	int	i;
	int	size;

	size = ft_lstsize(*stack_b);
	while (*stack_b)
	{
		size = ft_lstsize(*stack_b) - 1;
		i = position(*stack_b, size);
		if ((*stack_b)->index == size)
			push_a(stack_a, stack_b);
		else if (i > size / 2)
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
	
}

