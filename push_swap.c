/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/07 18:26:44 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	spliting_input(int ac, char **av, t_list **linked)
{
	int		i;
	int		j;
	char	**gone;
	int		l;
	t_list	*lst;

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

int	check(t_list *linked)
{
	t_list	*tmp;

	tmp = linked;
	while (tmp)
	{
		if (!is_valid((char *)tmp->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	switch_int(t_list **stack_a)
{
	int		i;
	t_list	*curr;

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
void	write_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("-->%d", *list->data);
		printf("index :-->%d\n", list->index);
		i++;
		list = list->next;
	}
	putstr("\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*error;
	int		o;
	int		size;

	error = "Error\n";
	stack_a = NULL;
	stack_b = NULL;
	spliting_input(ac, av, &stack_a);
	o = check(stack_a);
	if (o == 0)
		return ((write(1, error, 7)), 0);
	switch_int(&stack_a);
	sort_index(stack_a);
	sort_big(&stack_a, &stack_b, size);
	size = ft_lstsize(&stack_a);
	if (size <= 4 && size >= 46)
		insertion_sort(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b, size);
}
