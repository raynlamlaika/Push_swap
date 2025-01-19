/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:19:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/19 10:39:40 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	take_line(char **str, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = move(stack_a, stack_b, str[i]);
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

void	*parce(int ac, char **av, int o, t_list *stack_a)
{
	t_list	*pp;

	pp = stack_a;
	spliting_input(ac, av, &stack_a);
	o = check(stack_a);
	if (o == 0)
		return (freed(stack_a), (write(1, "Error\n", 7)), NULL);
	if (o == 2)
		return (freed(stack_a), NULL);
	switch_int(&stack_a);
	o = check_double(&pp);
	if (o == 0)
		return (freed(stack_a), (write(1, "Error\n", 7)), NULL);
	o = sort_check(&stack_a);
	if (o == 0)
		return (freed(stack_a), (write(1, "Error\n", 7)), NULL);
	return (stack_a);
}

int	final_result(t_list *stack_a, t_list *stack_b, int o)
{
	if (o == 0 && ft_lstsize(stack_b) == 0)
		return (freed(stack_a), freed(stack_b), putstr("OK\n"), 1);
	if (o == 1 || ft_lstsize(stack_b) > 0)
		return (freed(stack_a), freed(stack_b), putstr("KO\n"), 1);
	return (1);
}

char	**moooves(t_list *stack_a, char *error, t_list *stack_b)
{
	char	**moves;
	char	*tmpp;
	char	*next;
	char	*operation;
	int		i;

	operation = ft_strdup("");
	if (!operation)
		return (free(operation), freed(stack_a), NULL);
	next = get_next_line(0);
	if (!next)
		return (freed(stack_a), free(next)
		, free(operation), (write(1, error, 7)), NULL);
	while (next)
	{
		i = search_search(next);
		if (i == 0)
			return (freed(stack_a), freed(stack_b), free(operation), \
			free(next), free(tmpp), NULL);
		tmpp = operation;
		operation = ft_strjoin(operation, next);
		if (!operation)
			return (freed(stack_a), free(operation), NULL);
		free(tmpp);
		free(next);
		next = get_next_line(0);
	}
	moves = ft_split(operation, '\n');
	return (free(operation), free(next), moves);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ii;
	int		o;
	char	**moves;

	o = 0;
	stack_a = NULL;
	stack_a = parce(ac, av, o, stack_a);
	if (!stack_a)
		return (freed(stack_a), freed(stack_b), 0);
	o = 0;
	moves = moooves(stack_a, "Error\n", stack_b);
	if (!moves)
		return (freed(stack_b), 0);
	o = take_line(moves, &stack_a, &stack_b);
	if (o == 0)
		return (freed(stack_a), freed(stack_b), clean_2(moves), 0);
	clean_2(moves);
	ii = stack_a;
	o = sort_check(&ii);
	return (final_result(stack_a, stack_b, o));
}
