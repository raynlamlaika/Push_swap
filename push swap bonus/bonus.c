/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:19:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/13 17:12:28 by rlamlaik         ###   ########.fr       */
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

void write_list(t_list *list)
{
	int  i;

	i = 0;
	while(list)
	{
		printf("-->%d",*list->data);
		i++;
		list=list->next;
	}
	printf("\n");
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*error;
	int		o;
	int		size;
	char	*line;
	char	*tmp;
	char	**moves;

	error = "Error\n";
	stack_a = NULL;
	stack_b = NULL;
	spliting_input(ac, av, &stack_a);
	o = check(stack_a);
	if (o == 0)
		return ((write(1, error, 7)), 0);
	o = check_double(&stack_a);
	if (o == 0)
		return ((write(1, error, 7)), 0);
	switch_int(&stack_a);
	o = sort_check(&stack_a);
	if (o == 0)
		return ((write(1, error, 7)), 0);
	char	*operation;
	char	*tmpp;
	char	*next;
	operation = ft_strdup("");
	if (!operation)
		return (0);
	next = get_next_line(0);
	while (next)
	{
		tmpp = operation;
		operation = ft_strjoin(operation, next);
		if (!operation)
			return (0);
		(free(tmpp), free(next));
		next = get_next_line(0);
	}
	moves = ft_split(operation, '\n');
	o = 0;
	take_line(moves, &stack_a, &stack_b);
	t_list *iii = stack_a;
	o = sort_check(&iii);
	write_list(iii);
	if (o == 0)
		return (putstr("OK\n"), 1);
	if (o == 1)
		return (putstr("KO\n"), 1);

}
