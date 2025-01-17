/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:00 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/17 14:03:08 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(t_list *linked)
{
	t_list	*tmp;

	tmp = linked;
	if (ft_lstsize(linked) < 2)
		return (2);
	while (tmp)
	{
		if (!is_valid((char *)tmp->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long	switch_int(t_list **stack_a)
{
	long	i;
	t_list	*curr;

	curr = *stack_a;
	while (curr)
	{
		i = ft_atoi((char *)curr->data);
		if (i == 2147483649)
			return(freed(*stack_a), 0);
		free(curr->data);
		curr->data = malloc(sizeof(int));
		if (!(curr->data))
		{
			freed(*stack_a);
			return (0);
		}
		*(int *)(curr->data) = i;
		curr = curr->next;
	}
	return (1);
}

int	check_double(t_list **stack)
{
	t_list	*tmp;
	t_list	*pass;

	tmp = *stack;
	while (tmp)
	{
		pass = tmp->next;
		while (pass)
		{
			if (*(tmp->data) == *(pass->data))
				return (freed(*stack), 0);
			pass = pass->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	spliting_input(int ac, char **av, t_list **linked)
{
	int		i;
	int		l;
	t_list	*lst;
	char	**gone;

	i = 1;
	while (ac > i)
	{
		gone = ft_split(av[i++], ' ');
		l = 0;
		while (gone[l])
		{
			lst = ft_lstnew(gone[l++]);
			if (!lst)
			{
				clean_2(gone);
				freed(*linked);
				return ;
			}
			ft_lstadd_back(linked, lst);
		}
		free(gone);
	}
}