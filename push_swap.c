/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:13:29 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/19 03:13:00 by rlamlaik         ###   ########.fr       */
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
				if (!(is_valid(av[i][j])))
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

int	*creating_list(int ac, char **av, l_list *linkedlist)
{
	int i;
	int	integer;
	l_list arg;

	i = 0;
	while (ac > i)
	{
		printf("check CHECK\n");
		integer =  ft_atoi(av[i]);
		arg.data = &integer;
		printf("%d \n", &arg.data);

		ft_lstadd_back(&linkedlist, &arg);
		i++;
	}
	l_list *head = linkedlist;
	while (head->data)
	{
		printf("%s \n", head->data);
		head = head->next;
	}
	return 0;
}
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
	l_list	*the_list;
	l_list	*linkedlist;

	error = "Error\n";
	if(!(check_args(ac, av))) 
// check for valid argemment passed
		return (write(1, error, 7), 0);
	write(1, "passe the checking successefully\n" ,34);


// switch and appand the stack from av to stack
	write(1,"now letss pass to the liked list\n",34);
	int *i;
	i = creating_list(ac, av, linkedlist);




	
	//sort_args();
	//sorting the stack a and b right here


	return 0;
}