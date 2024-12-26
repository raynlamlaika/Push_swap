/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/26 01:26:12 by rlamlaik         ###   ########.fr       */
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

// switch char to integer to preparing to check for doubles
void	switch_int(l_list **stack_a)
{
	int i;
	l_list *curr;

	curr = *stack_a;
	while (curr)
	{	
		i = ft_atoi((char *)curr->data);
		free(curr->data);
		curr->data = malloc(sizeof(int));
		if (!(curr->data))
		{	
			printf("eeeee");
			return ;
		}
		*(int *)(curr->data) = i;
    	curr = curr->next;
	}

}

//check nodes if this in doubles deffenoition in nodes
int check_double(l_list **stack_a )
{
	int i;
	i = 0;

	return i;
}


int main(int ac, char** av)
{
	l_list	*stack_a= NULL;
	l_list	*stack_b = NULL;
	char	*error;
	int		o;

	stack_b = malloc(sizeof(l_list));
	error = "Error\n";

	
	spliting_input(ac, av, &stack_a);
	o = check(stack_a); //check for list size (lst > 3 || 2)
	if (o == 0)
		return ((write(1,error,7)), 0);
	switch_int(&stack_a);
	l_list *xx = stack_a;
	// switch/_int(&xx);
	
	
	while(xx)
	{
		int i;
		i = 23;
		
		printf("|%d|-->",*xx->data);
		// xx = current->next;
		xx = xx->next;
	}
}