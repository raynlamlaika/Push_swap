/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:19:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/11 21:50:01 by rlamlaik         ###   ########.fr       */
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

static int	move(int i, t_list **stack_a, t_list **stack_b, char **str)
{
	//printf("this is the val of i :%s\n", str[i]);
	if (is_passed(str[i], "pa"))
		push_a(stack_a, stack_b);
	
	else if (is_passed(str[i], "sa"))	
		swap_a(stack_b);
	
	else if (is_passed(str[i], "sb"))	
		swap_b(stack_b);
	
	else if (is_passed(str[i], "ss"))	
		swap_ab(stack_b, stack_a);
	
	else if (is_passed(str[i], "pb"))	
		push_b(stack_a, stack_b);
	
	else if (is_passed(str[i], "ra"))	
		rotate_a(stack_a);
	
	else if (is_passed(str[i], "rb"))	
		rotate_b(stack_b);
	
	else if (is_passed(str[i], "rr"))	
		rotate_ab(stack_a, stack_b);
	
	else if (is_passed(str[i], "rra"))	
		reverse_rotate_a(stack_a);
	
	else if (is_passed(str[i], "rrb"))	
		reverse_rotate_b(stack_b);
	
	else if (is_passed(str[i], "rrr"))	
		reverse_rotate_ab(stack_a, stack_b);
	
	else
		return (write(2, "Error\n", 7), 0);
	return (1);
}

static int	take_line(char **str, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		move(i, stack_a, stack_b, str);
		i++;
	}
	return (0);
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

//check if the linkedlist are sorted
int	sort_check(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (*tmp->data > *tmp->next->data)
			return (0);
		tmp = tmp->next;
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
	if (o == 1)
		return ((write(1, error, 7)), 0);
	line = get_next_line(0);
	while (tmp)
	{
		tmp = get_next_line(0);
		line = ft_strjoin(line, tmp);
	}
	moves = ft_split(line, '\n');
	o =0 ;
	take_line(moves, &stack_a, &stack_b);
	o = sort_check(&stack_a);
	if (o == 1)
		return (putstr("it wooorks OK\n"), 1);
	if (o == 0)
		return (putstr("KO\n"), 1);

}
