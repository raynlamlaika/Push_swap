/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:19:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/01/07 18:52:30 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	int		j;
	t_list	*stack_a;
	int		size;
	char *error;

	i = 1;
	spliting_input(ac, av, &stack_a);
	checker(&stack_a);
	if (i > 2)
	{
		j = 0;
		while (av[i][j])
		{
			
		}
	}
	return (0);
}