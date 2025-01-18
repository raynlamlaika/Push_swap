/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:15:23 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/18 14:47:48 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_passed(char *str, char *sec)
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

int	move(t_list **stack_a, t_list **stack_b, char *str)
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
