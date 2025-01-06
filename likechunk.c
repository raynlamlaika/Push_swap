/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   likechunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:47:32 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/06 15:42:51 by rlamlaik         ###   ########.fr       */
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

void	set_position(l_list *stack)
{
	l_list	*curr;
	int				i;

	i = 0;
	curr = stack;
	while (curr)
	{
		curr->position_in_stack = i;
		i++;
		curr = curr->next;
	}
}

int	max_node_positon(l_list *stack)
{
	l_list	*tmp;
	l_list	*max;

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



void	move_back_to_a(l_list **a, l_list **b, int size_of_stack)
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
void sort_big(l_list **stack_a, l_list **stack_b)
{
	int i;
	int chunk;

	i = 0;
	chunk = 34; // it will be in deffrant val later
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
	int size = ft_lstsize(*stack_b);
	move_back_to_a(stack_a, stack_b,size);//therealsort(stack_a, stack_b);
}


