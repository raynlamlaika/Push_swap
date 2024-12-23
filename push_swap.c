/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/23 16:19:03 by rlamlaik         ###   ########.fr       */
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
	//lets check push oppertions
	push_a(stack_a, stack_b);
	
}