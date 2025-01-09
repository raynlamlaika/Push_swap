/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:19:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/09 11:54:30 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
int checker(char **str, t_list **stack_a, t_list **stack_b)
{
	int i;
	
	i = 0;
	if (passed(str[i]))
	{
		if (str[i] == "pa")
			push_a(stack_a, stack_b);
		else if (str[i] == "sa")
			swap_a(stack_b);
		else if (str[i] == "sb")
			swap_b(stack_b);
		else if (str[i] == "ss")
			swap_ab(stack_b, stack_a);
		else if(str[i] == "pb")
			push_b(stack_a, stack_b);
		else if (str[i] == "ra")
			rotate_a(stack_a);
		else if (str[i] == "rb")
			rotate_b(stack_b);
		else if (str[i] == "rr")
			rotate_ab(stack_a, stack_b);
		else if (str[i] == "rra")
			reverse_rotate_a(stack_a);
		else if (str[i] == "rrb")
			reverse_rotate_b(stack_b);
		else if (str[i] == "rrr")
			reverse_rotate_ab(stack_a, stack_b);
		else
		 	return(write(2, "Error\n", 7), 0);
		i++;
	}
	return (0);
}

//check if the linkedlist are sorted
int sort_check(t_list **stack_a)
{
	t_list *tmp;

	while (*stack_a)
	{
		tmp =(*stack_a)->next;
		if (*(*stack_a)->data < *tmp->data)
			*stack_a = (*stack_a)->next;
		else
			return(write(2, "Error\n", 7),0);
	}
	return (1);
}

int main(int ac, char **av)
{
	int		i;
	int		j;
	t_list	*stack_a;
	int		size;
	char	*error;
	char	*line;
	char	*pp = NULL;

	i = 1;
	spliting_input(ac, av, &stack_a);
	line = get_next_line(0);
	
	while (line)
	{
		pp = ft_strjoin(pp, line);
		line = get_next_line(0);
	}
	pp = ft_strjoin(pp, line);
	char **noorm = ft_split(pp, '\n');
	if (noorm)
	{
		checker(noorm, stack_a, stack_b);
		printf("thisis the array [%s]\n",noorm[i++]);
	}
	return (0);
}