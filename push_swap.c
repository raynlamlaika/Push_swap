/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/18 20:50:53 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(int ac,char **av)
{
	int i;
	int j;
	int integer;

	i = 1;
	j = 2;
	if (ac > 1)
	{
		while (ac > i)
		{
			j = 0;
			while(av[i][j])
			{
				if (!(ft_isdigit(av[i][j])))
					return (write(2, "Invalid argument passed", 24), 0); // handel the overflow for the args !!
				j++;
			}
			integer =  ft_atoi(av[i]);
			printf("the arg passsed: %d\n",integer);
			i++;

		}
		return (1);
	}
	return (0);
}

int	switch_to_intger(int *ac, char **av, int *stack_a)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (ac[i])
	{
		stack_a[j] = ac[i++];
		printf("%d",stack_a[j++]);

	}

	return (i);
}
int main(int ac, char **av)
{
	int stack_a[500];
	int stack_b[500];
	char *error;

	error = "Error\n";
	if(!(check_args(ac, av))) // check for thet argemment that are all valide
		return (write(1, error, 7), 0);
	// switch and appand the stack from av to stack
	printf(" this is in pass");

	switch_to_intger(&ac, av, stack_a);
	//sort_args();
	//sorting the stack a and b right here


	return 0;
}