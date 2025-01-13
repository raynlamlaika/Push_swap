/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/13 23:35:49 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freed(t_list *lst)
{
	while (lst)
	{
		free(lst->data);
		lst = lst->next;
	}
	free(lst);
}

void	clean_2(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	spliting_input(int ac, char **av, t_list **linked,char	**gone)
{
	int		i;
	int		j;
	int		l;
	t_list	*lst;

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
				freed(lst);
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
	if (ft_lstsize(linked) < 2)
		return (freed(linked), 0);
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
			freed(curr);
			return ;
		}
		*(int *)(curr->data) = i;
		curr = curr->next;
	}
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
				return (0);
			pass = pass->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	sort_check(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (*tmp->data > *tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*error;
	int		o;
	int		size;
	char	**gone;

	error = "Error\n";
	stack_a = NULL;
	stack_b = NULL;
	spliting_input(ac, av, &stack_a, gone);
	o = check(stack_a);
	if (o == 0)
		return (freed(stack_a), (write(1, error, 7)), 0);
	switch_int(&stack_a);
	o = check_double(&stack_a);
	if(o == 0)
		return (freed(stack_a), (write(1, error, 7)), 0);
	o = sort_check(&stack_a);
	if(o == 0)
		return (freed(stack_a), (write(1, error, 7)), 0);
	sort_index(stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
		swap_a(&stack_a);
	else if (size == 3 )
		sort_three(&stack_a);
	else if (size > 2 && size <= 10)
		sort_small_stack(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	freed(stack_a);
}
