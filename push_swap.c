/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/18 21:16:13 by rlamlaik         ###   ########.fr       */
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
			printf("the arg passsed is: %d\n",integer);
			i++;

		}
		return (1);
	}
	return (0);
}



int linked_list_appand(int , int , )
// sa (swap a): swap the first tow elemment in Stack_a.



// sb (swap b): swap the first tow elemment in Stack_b



//ss : sa and sb at the same time



//pa (push a): Take the first element at the top of b and put it at the top of a.



//pb (push b): Take the first element at the top of a and put it at the top of b.


//ra (rotate a): Shift up all elements of stack a by 1.



//rb (rotate b): Shift up all elements of stack b by 1.



//rr : ra and rb at the same time.



//rra (reverse rotate a): Shift down all elements of stack a by 1



//rrb (reverse rotate b): Shift down all elements of stack b by 1.



//rrr : rra and rrb at the same time.





int main(int ac, char **av)
{
	int stack_a[500];
	int stack_b[500];
	char *error;

	error = "Error\n";
	if(!(check_args(ac, av))) 
// check for thet argemment that are all valide
		return (write(1, error, 7), 0);
	write(1, "passe the checking successefully" ,33);
// switch and appand the stack from av to stack


	linked_list_appand(&ac, av, stack_a);
	//sort_args();
	//sorting the stack a and b right here


	return 0;
}