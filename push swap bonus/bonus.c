/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:19:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/15 19:37:58 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	is_passed(char *str, char *sec)
{
	int	i;

	i = 0;
	while (str[i] || sec[i])
	{
		if (str[i] != sec[i])
			return (0);
		i++;
	}
	return (1);
}

static int	move(int i, t_list **stack_a, t_list **stack_b, char *str)
{
	if (is_passed(str, "pa"))
		push_a(stack_a, stack_b);
	else if (is_passed(str, "sa"))
		swap_a(stack_a);
	else if (is_passed(str, "sb"))
		swap_b(stack_b);
	else if (is_passed(str, "ss"))
		swap_ab(stack_b, stack_a);
	else if (is_passed(str, "pb"))
		push_b(stack_b, stack_a);
	else if (is_passed(str, "ra"))
		rotate_a(stack_a);
	else if (is_passed(str, "rb"))
		rotate_b(stack_b);
	else if (is_passed(str, "rr"))
		rotate_ab(stack_a, stack_b);
	else if (is_passed(str, "rra"))
		reverse_rotate_a(stack_a);
	else if (is_passed(str, "rrb"))
		reverse_rotate_b(stack_b);
	else if (is_passed(str, "rrr"))
		reverse_rotate_ab(stack_a, stack_b);
	else
		return (write(2, "Error\n", 7), 0);
	return (1);
}

static int	take_line(char **str, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = move(i, stack_a, stack_b, str[i]);
		if (j == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*error;
	int		o;
	int		size;
	char	**moves;
	char	*operation;
	char	*tmpp;
	char	*next;

	error = "Error\n";
	stack_a = NULL;
	stack_b = NULL;
	spliting_input(ac, av, &stack_a);
	o = check(stack_a);
	if (o == 0)
		return (freed(stack_a), (write(1, error, 7)), 0);
	if (o == 2)
		return (freed(stack_a), 0);
	switch_int(&stack_a);
	o = check_double(&stack_a);
	if (o == 0)
		return ((write(1, error, 7)), 0);
	o = sort_check(&stack_a);
	if (o == 0)
		return (freed(stack_a), (write(1, error, 7)), 0);
	operation = ft_strdup("");
	if (!operation)
		return (free(operation) ,0);
	next = get_next_line(0);
	if (!next)
		return (freed(stack_a), free(next), (write(1, error, 7)), 0);
	while (next)
	{
		tmpp = operation;
		operation = ft_strjoin(operation, next);
		if (!operation)
			return (freed(stack_a),free(operation), 0);
		free(tmpp);
		free(next);
		next = get_next_line(0);
	}
	moves = ft_split(operation, '\n');
	free(operation);
	o = 0;
	o = take_line(moves, &stack_a, &stack_b);
	if (o == 0)
		return (freed(stack_a), free(next), 0);
	t_list *iii = stack_a;
	o = sort_check(&iii);
	clean_2(moves);
	free(next);
	if (o == 0)
		return (freed(stack_a), putstr("OK\n"), 1);
	if (o == 1)
		return (freed(stack_a), putstr("KO\n"), 1);
}
