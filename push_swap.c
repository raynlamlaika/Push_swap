/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/25 18:39:54 by rlamlaik         ###   ########.fr       */
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
	stack_b = malloc(sizeof(l_list));
	char	*error;

	error = "Error\n";
	spliting_input(ac, av, &stack_a);
	int o = check(stack_a); //check for list size (lst > 3 || 2)
	if (o == 0)
		return((write(1,error,7)),0);
	l_list *current = stack_a;
	l_list *xx = stack_a;
	reverse_rotate_ab(&xx, &current);
	int i= 0;
	while(xx )
	{
		printf("|%s|-----------|%s|\n",(char *)current->data,(char *)xx->data);
		current = current->next;
		xx = xx->next;
	}

	// l_list *xx = stack_a;
	// printf("\n\n\n");
	// stack_b->data = (int *)"we";
	// stack_b->next->data = (int *)"ee";
	// rotate_a(&xx);

	// while(stack_b || xx)
	// {
	// 	printf("this is are the input splitiong |%s| thi thi tui  |%s|\n",(char *)stack_b->data,(char *)xx->data);
	// 	stack_b = stack_b->next;
	// 	xx=xx->next;
	// }
	//lets check push oppertions
	
}