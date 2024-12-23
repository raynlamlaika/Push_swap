/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/23 15:28:23 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//parccing the input (node by node)
void spliting_input(int ac, char **av, l_list **linked)
{
	int i;
	int j;
	char **gone;
	int l;
	l_list *lst;

	i = 1;
	while (ac > i && ac > 2)
	{
		gone = ft_split(av[i++], ' ');
		l = 0;
		while (gone[l])
		{
			lst = ft_lstnew(gone[l++]);
			if (!lst)
			{
				j = 0;
				while (gone[j])
					free(gone[j++]);
				free(gone);
				return ;
			}
			ft_lstadd_back(linked, lst);
		}
	}
}
//Parccing: check for not digit argemment

int	check(l_list *linked)
{
	l_list *tmp;

	tmp = linked;
	while(tmp)
	{
		if (!is_valid((char *)tmp->data))
			return (0);
		tmp = tmp->next;
	}
	return 1;
}

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

void	push_a()
{


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




int main(int ac, char** av)
{
	l_list	*stack_a= NULL;
	l_list	*stack_b = NULL;
	char	*error;

	error = "Error\n";
	spliting_input(ac, av, &stack_a);
	int o = check(stack_a); //check for list size (lst > 3 || 2)
	if (o == 0)
		return((write(1,error,7)),0);
	l_list *current = stack_a;

	while(current)
	{
		printf("this is are the input splitiong |%s|\n",(char *)current->data);
		current = current->next;
	}
	l_list *xx = stack_a;
	write(1,"\n\n\n",3);
	swap_a(&xx);
	while(xx)
	{
		printf("this is are the input splitiong |%s|\n",(char *)xx->data);
		xx = xx->next;
	}
	
}